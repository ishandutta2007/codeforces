#include <iostream>
#include <algorithm>
#include <cstdio>

const int ms = 100100;

int freq[ms];
int lis[2][ms];
int a[ms];

int main() {
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int l, r;
		//std::cin >> l >> r;
		scanf("%d %d", &l, &r);
		freq[l]++;
		freq[r + 1]--;
	}
	for(int i = 1; i <= m; i++) {
		freq[i] += freq[i - 1];
		//std::cout << freq[i] << (i == m ? '\n' : ' ');
	}
	int c = 0;
	for(int i = 1; i <= m; i++) {
		int cur = freq[i];
		int idx = std::upper_bound(a, a + c, cur) - a;
		a[idx] = cur;
		if(idx == c) {
			c++;
		}
		lis[0][i] = c;
	}
	c = 0;
	for(int i = m; i > 0; i--) {
		int cur = freq[i];
		int idx = std::upper_bound(a, a + c, cur) - a;
		a[idx] = cur;
		if(idx == c) {
			c++;
		}
		lis[1][i] = c;
	}
	int ans = 0;
	for(int i = 1; i <= m; i++) {
		ans = std::max(ans, lis[0][i] + lis[1][i] - 1);
	}
	std::cout << ans << '\n';
}