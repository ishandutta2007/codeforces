#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <bitset>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 10010;
const int INF = 1e9;

int pref[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, l, r;
	std::bitset<ms> bad;
	bad[0] = true;
	std::vector<int> vals;
	std::cin >> n >> l >> r;
	int sum = 0;
	{
		std::vector<int> trash(n);
		for(int i = 0; i < n; i++) {
			std::cin >> trash[i];
		}
		for(int i = 0; i < n; i++) {
			int t;
			std::cin >> t;
			if(t == 0) {
				bad |= bad << trash[i];
			} else {
				vals.push_back(trash[i]);
				sum += trash[i];
			}
		}
	}
	n = (int) vals.size();
	std::sort(vals.rbegin(), vals.rend());
	int other = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 1; j < ms; j++) {
			pref[j] = pref[j-1] + (bad[j-1] ? 1 : 0);
		}
		// first check if answer exists
		for(int j = l; j <= r && j + sum - vals[i] <= r; j++) {
			if(bad[j]) {
				std::cout << n-i << '\n';
				return 0;
			}
		}
		// second check, replacing some value in there by some value in bad
		for(int j = i; j < n; j++) {
			int rl = l, rr = r;
			rl = std::max(l - vals[j], 0);
			rr = std::min(r - vals[j], other - 1);
			// x + sum <= r
			// x <= r - sum
			rr = std::min(rr, r - sum); 
			//std::cout << "at " << i << ", " << j << " got range [" << rl << ", " << rr << "]\n";
			if(rl > rr) continue;
			if(pref[rr+1] - pref[rl] > 0) {
				std::cout << n-i << '\n';
				return 0;
			}
		}
		sum -= vals[i];
		bad |= bad << vals[i];
		other += vals[i];
	}
	std::cout << 0 << '\n';
}