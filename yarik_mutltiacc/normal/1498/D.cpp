// Problem: D. Bananas in a Microwave
// Contest: Codeforces - CodeCraft-21 and Codeforces Round #711 (Div. 2)
// URL: https://codeforces.com/contest/1498/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}

int main() {
	#define int long long
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n, m;
	cin >> n >> m;
	vector<int> dp(m+1, 1<<20);
	dp[0] = 0;
	const int B = 100000;
	for(int t, x, y, it = 1; it <= n; it++) {
		cin >> t >> x >> y;
		vector<int> ndp(m+1, 1<<20);
		for(int i = 0; i <= m; i++) if(dp[i] < (1<<20)) ndp[i] = 0;
		if(t == 1) {
			x=(x+B-1)/B;
			for(int i = 0; i <= m; i++) {
				if(i+x<=m) ndp[i+x] = min(ndp[i+x], ndp[i]+1);
			}
		} else {
			for(int i = 0; i <= m; i++) {
				ll j = (i*1ll*x+B-1)/B;
				if(ndp[i] < y) {
					//cout << i << " -> " << j << endl;
				}
				if(j<=m) ndp[j] = min(ndp[j], ndp[i]+1);
			}
		}
		for(int p = 0; p <= m; p++)
			if(dp[p] >= (1<<20) && ndp[p] <= y)
				dp[p] = it;
	}
	for(auto &i : dp) if(i>=(1<<20)) i = -1;
	for(int i = 1; i <= m; i++) cout << dp[i] << " ";
}