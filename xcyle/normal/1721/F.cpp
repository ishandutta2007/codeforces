/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define maxn 400005
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n1, n2, m, q;
int tot = 1, adj[maxn], cur[maxn], dis[maxn];
struct edge {int v, nxt, w;}G[maxn * 3];
inline void add(int x, int y) {
	G[++tot] = {y, adj[x], 1}, adj[x] = tot;
	G[++tot] = {x, adj[y], 0}, adj[y] = tot;
}
inline int bfs() {
	ru(i, 1, n1 + n2 + 1) dis[i] = INF;
	dis[0] = 0;
	queue<int> q; q.push(0);
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = adj[x]; i; i = G[i].nxt) {
			int V = G[i].v;
			if(dis[V] != INF || !G[i].w) continue;
			dis[V] = dis[x] + 1, q.push(V);
		}
	}
	return dis[n1 + n2 + 1] != INF;
}
int dfs(int x, int flow) {
	if(x == n1 + n2 + 1) return flow;
	int rem = flow;
	for (int i = cur[x]; i; i = G[i].nxt) {
		int V = G[i].v;
		cur[x] = i;
		if(dis[V] != dis[x] + 1 || !G[i].w) continue;
		int tmp = dfs(V, min(rem, G[i].w));
		rem -= tmp, G[i].w -= tmp, G[i ^ 1].w += tmp;
		if(!rem) break;
	}
	return flow - rem;
}
int match[maxn], vis[maxn];
vector<int> GG[maxn];
map<pii, int> id;
int de[maxn], dv[maxn], top;
void upd(int x) {
	for (auto V: GG[x]) if(!vis[V]) {
		vis[V] = vis[match[V]] = vis[x], upd(match[V]);
	}
} 
int main() {
	n1 = read(), n2 = read(), m = read(), q = read();
	ru(i, 1, n1) add(0, i);
	ru(i, n1 + 1, n1 + n2) add(i, n1 + n2 + 1);
	ru(i, 1, m) {
		int x = read(), y = read() + n1; 
		add(x, y), GG[x].push_back(y), GG[y].push_back(x);
		id[mp(x, y)] = i;
	}
	int cnt = 0;
	while(bfs()) {
		ru(i, 0, n1 + n2 + 1) cur[i] = adj[i];
		cnt += dfs(0, n1); 
	}
	ru(i, 1, n1) {
		for (int j = adj[i]; j; j = G[j].nxt) if(!G[j].w && G[j].v) match[match[i] = G[j].v] = i;
	}
	ru(i, 1, n1) if(!match[i]) {
		for (auto V: GG[i]) if(!vis[V]) {
			vis[V] = vis[match[V]] = 2, upd(match[V]);
		}
	}
	ru(i, n1 + 1, n1 + n2) if(!match[i]) {
		for (auto V: GG[i]) if(!vis[V]) {
			vis[V] = vis[match[V]] = 1, upd(match[V]);
		}
	}
	ll sum = 0;
	ru(i, 1, n1) if(match[i]) {
		if(!vis[i]) vis[i] = vis[match[i]] = 1, upd(match[i]);
		top++;
		de[top] = id[mp(i, match[i])];
		if(vis[i] == 1) dv[top] = i;
		else dv[top] = n1 - match[i];
		sum += de[top];
	}
	while(q--) {
		int opt = read();
		if(opt == 1) sum -= de[top], printf("1\n%d\n%lld\n", dv[top], sum), top--;
		else {
			printf("%d\n", top);
			ru(i, 1, top) printf("%d ", de[i]); printf("\n");
		}
		fflush(stdout);
	}
	return 0;
}