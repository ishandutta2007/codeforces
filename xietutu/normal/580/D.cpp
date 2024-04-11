#include <cstdio>
#include <algorithm>
#include <list>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll ans, dis[19][262144];
bool visit[19][262144];
int n, m, K, a[20], M[20][20];
queue<pii> Q;
int count(int s) {
	int t = 0;
	while (s) {
		++t;
		s -= s & (-s);
	}
	return t;
}
int main() {
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for (int i = 1; i <= K; ++i) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		M[x][y] = c;
	}
	memset(dis, 255, sizeof(dis));
	for (int i = 1; i <= n; ++i) {
		dis[i][1 << (i - 1)] = a[i];
		Q.push(make_pair(i, 1 << (i - 1)) );
		visit[i][1 << (i - 1)] = true;
	}
	
	while (Q.size()) {
		int x = Q.front().first, now = Q.front().second;
		Q.pop();
		for (int i = 1; i <= n; ++i)
			if (!(now & (1 << (i - 1)))) {
				int nst = now | (1 << (i - 1));
				ll v = dis[x][now] + M[x][i] + a[i];
				if (v > dis[i][nst]) {
					dis[i][nst] = v;
					if (!visit[i][nst]) {
						visit[i][nst] = true;
						Q.push(make_pair(i, nst));
					}
				}
			}
		visit[x][now] = false;
	}
	int maxs = 1 << n;
	for (int i = 0; i < maxs; ++i)
		if (count(i) == m) {
			for (int j = 1; j <= n; ++j)
				if (dis[j][i] > ans) ans = dis[j][i];
		}
	cout << ans << endl;
}