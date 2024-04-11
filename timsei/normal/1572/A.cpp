#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int M = 1e6 + 5;

int n, m, x, y, du[N];
int vis[N], fuck[N];
queue <int> q;
vector <int> G[N];

int main() {
	int T;
	for(cin >> T; T --;) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++ i) fuck[i] = vis[i] = 0, G[i].clear(), du[i] = 0;
		for(int i = 1; i <= n; ++ i) {
			scanf("%d", &y);
			for(int j = 1; j <= y; ++ j) scanf("%d", &x), G[x].push_back(i), ++ du[i];
		}
		for(int i = 1; i <= n; ++ i) if(!du[i]) {
			fuck[i] = vis[i] = 1;
			q.push(i);
		}
		while(!q.empty()) {
			int x = q.front();
			q.pop();
			for(int i = 0; i < (int) G[x].size(); ++ i) {
				int V = G[x][i];
				vis[V] = max(vis[x] + (V < x), vis[V]);
				if(-- du[V] == 0) {
					fuck[V] = 1;
					q.push(V);
				}
			}
		}
		int cnt = 0, sum = 1;
		for(int i = 1; i <= n; ++ i) cnt += fuck[i], sum = max(sum, vis[i]);
		if(cnt != n) {
			puts("-1");
		} else printf("%d\n", sum);
	}
}