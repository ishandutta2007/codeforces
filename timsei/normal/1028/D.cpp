#include <bits/stdc++.h>
using namespace std;

const int N = 3633055;

#define int long long

const int mod = 1e9 + 7;

int n, p, x, mn = -1e9, mx = 1e9, res = 1;

set <int> S;

char ty[N];

main(void) {
	cin >> n;
	int ans = 1;
	for(int i = 1; i <= n; ++ i) {
		scanf("%s", ty + 1);
		scanf("%lld", &x);
		if(ty[2] == 'D') {
			if(x <= mx && x >= mn) ++ res;
			S.insert(x);
		}
		else {
			res = 1;
			if(x < mn || x > mx) {
				ans = 0; break;
			}
			S.erase(x);
			if(x > mn && x < mx) ans = ans * 2 % mod;
			set <int> :: iterator it = S.upper_bound(x);
			if(it == S.end()) mx = 1e9;else mx  = *it;
			if(it == S.begin()) mn = -1e9; else mn = *(-- it);
		}
	}
	cout << ans * res % mod << endl;
}