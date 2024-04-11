// Problem: D.   
// Contest: Codeforces - Codeforces Global Round 23
// URL: https://codeforces.com/contest/1746/problem/D
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
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n, k;
		cin >> n >> k;
		vector<vector<int>> g(n);
		for(int p, i = 1; i < n; i++) {
			cin >> p;
			g[p-1].push_back(i);
		}
		vector<ll> c(n);
		for(auto &i : c) cin >> i;
		auto push = [&](auto self, int v, int cnt) -> array<ll, 2> {
			array<ll, 2> dp {0, 0};
			vector<ll> A;
			for(auto i : g[v]) {
				auto ch = self(self, i, cnt / g[v].size());
				dp[0] += ch[0];
				dp[1] += ch[1];
				A.push_back(-ch[0]+ch[1]);
			}
			if(g[v].size()) {
				sort(all(A), greater<>());
				for(int i = 0; i < (cnt % g[v].size()); i++)
					dp[0] += A[i];
				if((cnt+1)%g[v].size()) {
					dp[1] = dp[0] + A[cnt % g[v].size()];
				}
			}
			dp[0] += cnt * c[v];
			dp[1] += (cnt+1) * c[v];
			return dp;
		};
		cout << push(push, 0, k)[0] << '\n';
	});
	
}