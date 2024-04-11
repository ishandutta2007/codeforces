#include <bits/stdc++.h>
using namespace std;

const int N = 35;

#define int long long

int c[N] , L;

main(void) {
	int ans = 4e18 , n = 0 , cur;
	cin >> n >> L;
	for(int i = 0;i < n;++ i) {
		cin >> c[i];
		if(i) c[i] = min(c[i] , c[i - 1] * 2ll);
	}
	int it = n;
	n = 31;
	for(int i = it;i < n;++ i) c[i] = c[i - 1] * 2;
	for(int i = n - 1;i > 0;-- i) c[i - 1] = min(c[i - 1] , c[i]);
	cur = 0;
	for(int i = n - 1;i >= 0;-- i) {
		if(L & (1 << i)) {
			cur += c[i];
		}
		ans = min(ans , cur + c[i]);
	}
	ans = min(ans , cur);
	cout << ans;
}