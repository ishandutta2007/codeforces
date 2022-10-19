#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
const int M = N * 2;

int T, n, k, fir[N], ne[M], to[M], cnt = 1, fa[N];

void add(int x, int y) {
	ne[++ cnt] = fir[x];
	fir[x] = cnt;
	to[cnt] = y;
}

void link(int x, int y) {
	add(x, y);
	add(y, x);
}

#define Foreachson(i, x) for(int i = fir[x]; i; i = ne[i])

int S[N], x, dep[N];
void dfs(int x, int f) {
	S[x] = 1; fa[x] = f;
	Foreachson(i, x) {
		int V = to[i];
		if(V == f) continue;
		dfs(V, x);
		S[x] += S[V];
	}
}

bool vis[N];

void doit(int x, int f, int now) {
	if(!now) return;
	cout << x <<' ';
	-- now;
	Foreachson(i, x) {
		int V = to[i];
		if(V == f) continue;
		if(S[V] <= now)
		doit(V, x, S[V]), now -= S[V];
		else doit(V, x, now), now = 0;
	}
	cout << f << ' ';
}

int main() {
	for(cin >> T; T --;) {
		scanf("%d%d", &n, &k);
		cnt = 1;
		memset(fir, 0, sizeof(fir));
		memset(vis, 0, sizeof(vis));
		for(int i = 2; i <= n; ++ i) {
			scanf("%d", &x);
			link(x, i);
			dep[i] = dep[x] + 1;
		}
		dfs(1, 0);
		int ans = 0;
		for(int i = 1; i <= n; ++ i) {
			ans = max(ans, dep[i]);
		}
		int it = 0;
		for(int i = 1; i <= n; ++ i)
		if(dep[i] == ans) it = i;
		vector <int> fuck;
		int x = it;
		while(it != 1) {
			vis[it] = 1;
			fuck.push_back(it);
			it = fa[it];
		}
		vis[1] = 1;
		fuck.push_back(1);
		reverse(fuck.begin(), fuck.end());
		++ ans;
		int now = k - ans;
		if(k < ans) {
			cout << k - 1 << endl;
			for(int i = 0; i < k; ++ i) {
				cout << fuck[i] <<' ';
			}
			cout << endl;
			continue;
		}
		cout << ans + (k - ans) * 2 - 1 << endl;
		for(int i = 0; i < (int) fuck.size(); ++ i) {
			cout << fuck[i] << ' ';
			if(now) {
				Foreachson(j, fuck[i]) {
					int V = to[j];
					if(!vis[V]) {
						if(S[V] > now) {
							doit(V, fuck[i], now);
							now = 0;
						} else doit(V, fuck[i], S[V]), now -= S[V];
					}
				}
			}
		}
		cout << endl;
	}
}