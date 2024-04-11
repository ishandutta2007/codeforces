// Problem: B.  
// Contest: Codeforces - CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n, x;
		cin >> n >> x;
		int mn = -(1<<30), mx = 1<<30, ans = 0;
		for(int t; n--;) {
			cin >> t;
			mn = max(mn, t-x);
			mx = min(mx, t+x);
			if(mn > mx) {
				mn = t-x;
				mx = t+x;
				ans++;
			}
		}
		cout << ans << '\n';
	});
	
}