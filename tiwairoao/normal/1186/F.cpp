#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 1000000;
const int MAXM = 5000000;
struct edge{
	int from, to;
	bool flag, tag;
	edge *nxt, *rev;
}edges[MAXM + 5], *adj[MAXN + 5], *ecnt = &edges[0];
int fa[MAXN + 5];
int find(int x) {
	return fa[x] = (fa[x] == x ? x : find(fa[x]));
}
void addedge(int u, int v, bool t) {
	edge *p = (++ecnt), *q = (++ecnt);
	p->from = u, p->to = v, p->nxt = adj[u], adj[u] = p;
	q->from = v, q->to = u, q->nxt = adj[v], adj[v] = q;
	p->flag = q->flag = false, p->tag = q->tag = t;
	p->rev = q, q->rev = p;
	if( find(u) != find(v) )
		fa[find(u)] = find(v);
}
int deg[MAXN + 5]; edge *e[MAXM + 5], *tmp[MAXM + 5];
int ans1[MAXM + 5], ans2[MAXM + 5];
int cnt, tot;
void dfs(int x) {
	for(edge *p=adj[x];p;p=adj[x]) {
		if( p->flag ) {
			adj[x] = adj[x]->nxt;
			continue;
		}
		p->flag = p->rev->flag = true;
		adj[x] = adj[x]->nxt; dfs(p->to); e[++cnt] = p;
	}
}
void print() {
	printf("%d\n", tot);
	for(int i=1;i<=tot;i++)
		printf("%d %d\n", ans1[i], ans2[i]);
}
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
		fa[i] = i;
	for(int i=1;i<=m;i++) {
		int u, v; scanf("%d%d", &u, &v);
		addedge(u, v, true); deg[u]++, deg[v]++;
	}
	int lst = 0, fir = 0;
	for(int i=1;i<=n;i++) {
		if( deg[i] & 1 ) {
			if( !lst ) lst = i;
			else addedge(lst, i, false), lst = 0;
		}
	}
	for(int i=1;i<=n;i++) {
		if( find(i) != i ) continue;
		cnt = lst = fir = 0; dfs(i);
		for(int j=1;j<=cnt;j++) {
			if( !e[j]->tag ) {
				if( lst ) {
					int siz = 0;
					for(int k=lst+1;k<=j-1;k++)
						tmp[++siz] = e[k];
					if( siz && siz % 2 == 0 ) tmp[siz+1] = tmp[siz], siz++;
					for(int k=1;k<=siz;k+=2)
						tot++, ans1[tot] = tmp[k]->from, ans2[tot] = tmp[k]->to;
					if( siz && siz % 2 == 0 )
						tot++, ans1[tot] = tmp[siz]->from, ans2[tot] = tmp[siz]->to;
				}
				else fir = j;
				lst = j;
			}
		}
		if( !lst ) {
			for(int j=1;j<=cnt;j+=2)
				tot++, ans1[tot] = e[j]->from, ans2[tot] = e[j]->to;
		}
		else {
			int siz = 0;
			for(int j=lst+1;j<=cnt;j++)
				tmp[++siz] = e[j];
			for(int j=1;j<=fir-1;j++)
				tmp[++siz] = e[j];
			if( siz && siz % 2 == 0 ) tmp[siz+1] = tmp[siz], siz++;
			for(int j=1;j<=siz;j+=2)
				tot++, ans1[tot] = tmp[j]->from, ans2[tot] = tmp[j]->to;
		}
	}
	print();
}