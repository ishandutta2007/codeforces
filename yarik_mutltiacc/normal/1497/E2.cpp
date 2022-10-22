// Problem: E2. Square-free division (hard version)
// Contest: Codeforces - Codeforces Round #708 (Div. 2)
// URL: https://codeforces.com/contest/1497/problem/E2
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
const int N = 1e7 + 13;
int lp[N+1], dp[N+1];
vector<int> pr;
void sieve() {
	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
		    lp[i] = i;
		    pr.push_back (i);
		}
		for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*1ll*pr[j]<=N; ++j)
		    lp[i * pr[j]] = pr[j];
	}
	dp[1] = 1;
	for(int i = 2; i <= N; i++) {
		int ti = i, c = 0;
		while(ti%lp[i] == 0) ti/=lp[i], c++;
		dp[i] = dp[ti];
		if(c&1) dp[i] *= lp[i];
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);sieve();
	multitest([&](){
		int n, k;
		cin >> n >> k;
		set<int, greater<int>> dup;
		map<int, int> lst;
		array<int, 21> def;
		def.fill(1<<23);
		dup.insert(0);
		vector<array<int, 21>> q(n+1, def);
		def.fill(0);
		q[0] = def;
		int ans = 1;
		for(int t, i = 1; i <= n; i++) {
			cin >> t;
			t = dp[t];
			if(lst.count(t)) {
				dup.insert(lst[t]);
			}
			lst[t] = i;
			int cn = 0;
			for(auto j : dup) {
				if(cn > k) break;
				for(int x = 0; x <= k-cn; x++) {
					//cout << q.size() << endl;
					//cout << j << " " << q[i][0] << endl;
					q[i][x+cn] = min(q[i][x+cn],
					 q[j][x]+1);
				}
				//cout << i << " " << j << " " << q[i][k] << endl;
				cn++;
			}
			for(int j = 1; j <= k; j++) q[i][j] = min(q[i][j], q[i][j-1]);
		}
		cout << q[n][k] << '\n';
	});
	
}