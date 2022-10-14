#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n[5], a[5][150005];
set<int> G[5][150005];
pair<LL, int> order[150005];
LL dp[5][150005];

int main()
{
	rep1(i, 4) scanf("%d", &n[i]);
	rep1(i, 4) rep1(j, n[i]) scanf("%d", &a[i][j]);
	rep1(i, 3) {
		int m; scanf("%d", &m);
		while(m --) {
			int x, y; scanf("%d%d", &x, &y);
			G[i + 1][y].insert(x);
		}
	}
	rep1(i, 5) {
		if(i == 1) continue;
		rep1(j, n[i - 1]) order[j] = MP(dp[i - 1][j] + a[i - 1][j], j);
		sort(order + 1, order + n[i - 1] + 1);
		if(i == 5) { if(order[1].first >= 1e15) puts("-1"); else printf("%lld\n", order[1].first); break; }
		rep1(j, n[i]) {
			if(G[i][j].size() == n[i - 1]) { dp[i][j] = 1e15; continue; }
			int ptr = 1;
			while(G[i][j].find(order[ptr].second) != G[i][j].end()) ptr ++;
			dp[i][j] = order[ptr].first;
		}
	}
	return 0;
}