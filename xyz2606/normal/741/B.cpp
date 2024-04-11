#include<bits/stdc++.h>
using namespace std;
const int N(1111);
int w[N], b[N], rela[N];
vector<int> vec[N];
int getr(int x) {
	int p(x);
	while(p != rela[p]) {
		p = rela[p];
	}
	int p1(p); p = x;
	while(p != rela[p]) {
		int p2(rela[p]);
		rela[p] = p1;
		p = p2;
	}
	return p1;
}
int dp[2][N];
int main() {
	int n, m, W;
	scanf("%d%d%d", &n, &m, &W);
	for(int i(1); i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for(int i(1); i <= n; i++) {
		scanf("%d", &b[i]);
		rela[i] = i;
	}
	
	for(int i(1); i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		rela[getr(x)] = getr(y);
	}
	for(int i(1); i <= n; i++) {
		vec[getr(i)].push_back(i);
	}
	int cur(0);
	for(int i(1); i <= n; i++) {
		if(rela[i] == i) {
			for(int k(0); k <= W; k++) {
				dp[cur ^ 1][k] = dp[cur][k];
			}
			int totw(0), totb(0);
			for(int j(0); j < (int)vec[i].size(); j++) {
				//printf("%d: %d\n", i, vec[i][j]);
				for(int k(0); k <= W; k++) {
					if(k + w[vec[i][j]] <= W) {
						dp[cur ^ 1][k + w[vec[i][j]]] = max(dp[cur ^ 1][k + w[vec[i][j]]], dp[cur][k] + b[vec[i][j]]);
					}
				}
				totw += w[vec[i][j]];
				totb += b[vec[i][j]];
			}
			//cout << totb << ' ' << W << endl;
			for(int k(0); k <= W; k++) {
				if(k + totw <= W) {
					dp[cur ^ 1][k + totw] = max(dp[cur ^ 1][k + totw], dp[cur][k] + totb);
				}
			}
			cur = cur ^ 1;
		}
	}
	int ans(0);
	for(int i(0); i <= W; i++) {
		ans = max(ans, dp[cur][i]);
	}
	printf("%d\n", ans);
}