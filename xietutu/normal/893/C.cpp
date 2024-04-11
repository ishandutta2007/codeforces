#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = 100010;
vector<int> G[maxn];
int n, m, c[maxn];
bool visit[maxn];
queue<int> Q;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", c + i);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].pb(v);
		G[v].pb(u);
	}
	
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
		if (!visit[i]) {
			int minv = c[i];
			Q.push(i);
			visit[i] = true;
			while (Q.size()) {
				int x = Q.front();
				Q.pop();
				for (int& v : G[x]) 
					if (!visit[v]) {
						minv = min(minv, c[v]);
						visit[v] = true;
						Q.push(v);
					}
			}
			ans += minv;
		}
	
	cout << ans << endl;
}