#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>
#include <bitset>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 105;
const int mv = ms * ms;

std::bitset<mv> pref[ms][ms], suf[ms][ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		a[i] = i + 1;
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	std::vector<std::pair<int, int>> b;
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && a[l] == a[r]) {
			r++;
		}
		b.emplace_back(a[l], r - l);
	}
	if(b.size() <= 2) {
		std::cout << n << '\n';
		return 0;
	}
	std::shuffle(b.begin(), b.end(), rng);
	n = (int) b.size();
	pref[0][0] = true;
	int sum = 0;
	for(int i = 0; i < n; i++) {
		// compute prefix
		//std::cout << i << ": computing prefix of (" << b[i].first << ", " << b[i].second << ")" << std::endl;
		for(int j = 0; j <= sum; j++) {
			for(int k = 0; k <= b[i].second; k++) {
				pref[i+1][j+k] |= pref[i][j] << (b[i].first * k);
			}
		}
		sum += b[i].second;
	}
	sum = 0;
	suf[n][0] = true;
	for(int i = n-1; i >= 0; i--) {
		// compute suffix
		//std::cout << i << ": computing suffix of (" << b[i].first << ", " << b[i].second << ")" << std::endl;
		for(int j = 0; j <= sum; j++) {
			for(int k = 0; k <= b[i].second; k++) {
				suf[i][j+k] |= suf[i+1][j] << (b[i].first * k);
			}
		}
		sum += b[i].second;
	}
	int ans = 1;
	for(int i = 0; i < n; i++) {
		// make check
		for(int j = ans + 1; j <= b[i].second; j++) {
			bool valid = true;
			// check if can take sum b[i].first * j using j elements
			//std::cout << "trying to get "  << j << " times " << b[i].first << "\n";
			for(int f1 = 0; f1 <= j && valid; f1++) {
				for(int f2 = 0; f1 + f2 <= j && valid; f2++) {
					int f3 = j - f1 - f2;
					if(f3 > b[i].second || f1 + f2 == 0) continue;
					for(int k = 0; k + f3 * b[i].first <= b[i].first * j; k++) {
						int kk = b[i].first * j - k - f3 * b[i].first;
						if(pref[i][f1][k] && suf[i+1][f2][kk]) {
							valid = false;
							break;
						}
					}
				}
			}
			if(valid) {
				ans = j;
			}
		}
	}
	std::cout << ans << '\n';
}