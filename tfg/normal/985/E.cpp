#include <iostream>
#include <cstdio>
#include <algorithm>

const int ms = 1 << 19;

int a[ms];
bool dp[ms];

int main() {
	int n, k, d;
	std::cin >> n >> k >> d;
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	std::sort(a, a + n);
	dp[0] = true;
	for(int i = 1, l = 0, r = 0, f = 0; i <= n; i++) {
		while(a[i - 1] - a[l] > d) {
			if(dp[l]) {
				f--;
			}
			l++;
		}
		while(r + k <= i) {
			if(dp[r]) {
				f++;
			}
			r++;
		}
		//std::cout << "on " << i << " range is [" << l << ", " << r << ") and f is " << f << "\n";
		if(f > 0) {
			//std::cout << "GOT!\n";
			dp[i] = true;
		}
	}
	std::cout << (dp[n] ? "YES\n" : "NO\n");
}