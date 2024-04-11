// Problem: D.  
// Contest: Codeforces - CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/1704/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
		int n, m;
		cin >> n >> m;
		vector<vector<ll>> a(n);
		ll mn = 1ll<<62, mx = -(1ll<<62), pos = 1, mni = -1;
		for(auto &i : a) {
			i.resize(m);
			for(auto &j : i)
				cin >> j;
			ll val = 0, sum = 0;
			for(int x = 0; x < m; x++) {
				sum += i[x];
				val += sum;
			}
			mn = min(mn, val);
			if(mn == val) mni = pos;
			mx = max(mx, val);
			pos++;
		}
		cout << mni << " " << mx-mn << '\n';
	});
	
}