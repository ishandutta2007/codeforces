#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;

int n;
vector<int> g[1 << 20];
int dis[1 << 20];

int main() {
	cin >> n;
	int ans = n + 1;
	rep(i, 1, n) {
		int x;
		cin >> x;
		vector<int> f;
		for (int p = 2; p * p <= x; p++) {
			int cnt = 0;
			while (x % p == 0) {
				cnt++;
				x /= p;
			}
			if (cnt & 1)
				f.push_back(p);
		}
		if (x > 1) f.push_back(x);
		while (f.size() < 2)
			f.push_back(1);
		g[f[0]].push_back(f[1]);
		g[f[1]].push_back(f[0]);
	}
	rep(i, 1, 1000) {
		if (g[i].size()) {
			memset(dis, -1, sizeof dis);
			queue<int> q;
			q.push(i);
			dis[i] = 0;
			while (!q.empty()) {
				int v = q.front();
				q.pop();
				for (auto u : g[v]) {
					if (dis[u] == -1) {
						dis[u] = dis[v] + 1;
						q.push(u);
					}
					else if (dis[u] >= dis[v])
						ans = min(ans, dis[u] + dis[v] + 1);
				}
			}
		}
	}	
	if (ans == n + 1) ans = -1;
	cout << ans << "\n";
	return 0;
}