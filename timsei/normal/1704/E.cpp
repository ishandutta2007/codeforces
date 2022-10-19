#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int mod = 998244353;

#define int long long

int n, m, x, y, du[N], A[N], dp[N];

vector <int> G[N];

main() {
	int ttt;
	for(cin >> ttt; ttt --;) {
		scanf("%lld%lld", &n, &m);
		for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]), dp[i] = 0;
		for(int i = 1; i <= n; ++ i) du[i] = 0, G[i].clear(); 
		for(int i = 1; i <= m; ++ i) {
			scanf("%lld%lld", &x, &y);
			G[x].push_back(y);
			++ du[y];
		}
		
		bool ok = 0;
		
		int now = 0;

		for(int i = 1; i <= n; ++ i) if(!G[i].size()) now = i;
		
		for(int i = 1; i <= n; ++ i) {
			ok = 1;
			vector <int> who;
			for(int j = 1; j <= n; ++ j) if(A[j]) {
				ok = 0;
				who.push_back(j);
				-- A[j];
			}
			if(ok) {
				printf("%lld\n", i - 1);
				break;
			}
			for(auto x : who) {
				for(auto V : G[x]) 
				++ A[V];
			}
		}
		if(ok) continue;
		queue <int> q;
		for(int i = 1; i <= n; ++ i) if(!du[i]) {
			q.push(i);
		}
		
		int tot = n;
		
		while(!q.empty()) {
			int ind = q.front();
			-- tot;
			q.pop();
			dp[ind] = (dp[ind] + A[ind]) % mod;
			
			for(int i = 0; i < (int) G[ind].size(); ++ i) {
				int V = G[ind][i];
				dp[V] += dp[ind];
				if(dp[V] >= mod) dp[V] -= mod;
				if(-- du[V] == 0) {
					q.push(V);
				}
			}
		}
		printf("%lld\n", (dp[now] + n) % mod);
	}
}