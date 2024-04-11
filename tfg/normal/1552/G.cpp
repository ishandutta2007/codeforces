#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <bitset>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 44;

int n, k;

int pos[ms][ms], sz[ms], unknownSZ[ms];
long long knownMask[ms], unknownMask[ms][ms];

bool good(long long mask) {
	return mask == 0 || (mask + 1) == ((mask + 1) & -(mask + 1));
}

bool bf(int on, long long mask) {
	//std::cout << "on " << on << ", mask " << std::bitset<40>(mask) << '\n';
	if(on == k) {
		return good(mask);
	}
	int bits = __builtin_popcountll(mask & knownMask[on]);
	mask ^= mask & knownMask[on];
	for(int i = 0; i <= unknownSZ[on]; i++) {
		//std::cout << "(" << on << ", " << mask << "), had " << bits << " and now giving " << i << "\n";
		if(!bf(on+1, mask ^ unknownMask[on][bits + i])) {
			return false;
		}
	}
	return true;
}


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> k;
	if(n == 1) {
		std::cout << "ACCEPTED\n";
		return 0;
	}
	std::vector<bool> isKnown(n, false);
	for(int i = 0; i < k; i++) {
		std::cin >> sz[i];
		for(int j = 0; j < sz[i]; j++) {
			std::cin >> pos[i][j];
			pos[i][j]--;
		}
		std::sort(pos[i], pos[i] + sz[i]);
		long long curMask = 0, other = 0;
		for(int j = 0; j < sz[i]; j++) {
			other |= 1LL << pos[i][j];
			unknownMask[i][j+1] = other;
			if(isKnown[pos[i][j]]) {
				curMask |= 1LL << pos[i][j];
				knownMask[i] = curMask;
			} else {
				isKnown[pos[i][j]] = true;
				++unknownSZ[i];
			}
		}
		//std::cout << "at " << i << " unknown is " << unknownSZ[i] << '\n';
	}
	for(int i = 0; i < n; i++) {
		if(!isKnown[i]) {
			std::cout << "REJECTED\n";
			return 0;
		}
	}
	std::cout << (bf(0, 0) ? "ACCEPTED\n" : "REJECTED\n");
}