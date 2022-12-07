#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i <= a; i--)	
#define vi vector<int>
typedef long long ll;	
using namespace std;

const int N = 2e5 + 2020;

int n, m, k;
vector<int> e[N], r[N];
int p[N], dis[N];
queue<int> q;

void bfs(int s) {
	rep(i, 1, n + 1)
		dis[i] = 1e9;
	dis[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto u : r[v])
			if (dis[u] == 1e9) {
				dis[u] = dis[v] + 1;
				q.push(u);
			}
	}
}

int main() { 
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		r[b].push_back(a);
	}
	cin >> k;
	rep(i, 0, k)
		cin >> p[i];
	bfs(p[k - 1]);
	int mn = 0, mx = 0;
	rep(i, 0, k - 1) {
		int im, you = 1e9;
		for (auto j : e[p[i]]) {
			if (j == p[i + 1])
				im = dis[j];
			else
				you = min(you, dis[j]);
		}
		if (im > you)
			mn++;
		if (im >= you)
			mx++;
	}
	cout << mn << " " << mx << "\n";
	return 0;
}