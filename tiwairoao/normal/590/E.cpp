#include<cstdio>
#include<queue>
#include<cstring>
#include<bitset>
#include<algorithm>
using namespace std;
const int MAXN = 750;
const int MAXS = int(1E7);
const int MAXV = 2*750;
const int MAXE = MAXV*MAXV + 2*MAXV;
const int INF = (1<<30);
struct FlowGraph{
	struct edge{
		int to, flow, cap;
		edge *nxt, *rev;
	}edges[MAXE + 5], *adj[MAXV + 5], *cur[MAXV + 5], *ecnt;
	FlowGraph() {ecnt = &edges[0];}
	void addedge(int u, int v, int c) {
		edge *p = (++ecnt), *q = (++ecnt);
		p->to = v, p->cap = c, p->flow = 0;
		p->nxt = adj[u], adj[u] = p;
		q->to = u, q->cap = 0, q->flow = 0;
		q->nxt = adj[v], adj[v] = q;
		p->rev = q, q->rev = p;
	}
	int d[MAXV + 5], s, t;
	bool relabel() {
		for(int i=s;i<=t;i++)
			d[i] = t + 5, cur[i] = adj[i];
		queue<int>que;
		d[t] = 0; que.push(t);
		while( !que.empty() ) {
			int f = que.front(); que.pop();
			for(edge *p=adj[f];p;p=p->nxt) {
				if( p->rev->cap > p->rev->flow ) {
					if( d[f] + 1 < d[p->to] ) {
						d[p->to] = d[f] + 1;
						que.push(p->to);
					}
				}
			}
		}
		return !(d[s] == t + 5);
	}
	int aug(int x, int tot) {
		if( x == t ) return tot;
		int sum = 0;
		for(edge *&p=cur[x];p;p=p->nxt) {
			if( p->cap > p->flow && d[p->to] + 1 == d[x] ) {
				int del = aug(p->to, min(tot - sum, p->cap - p->flow));
				sum += del, p->flow += del, p->rev->flow -= del;
				if( sum == tot ) return sum;
			}
		}
		return sum;
	}
	int max_flow(int _s, int _t) {
		s = _s, t = _t; int flow = 0;
		while( relabel() )
			flow += aug(s, INF);
		return flow;
	}
	bool vis[MAXV + 5];
	void dfs(int x) {
		vis[x] = true;
		for(edge *p=adj[x];p;p=p->nxt)
			if( !vis[p->to] && p->cap > p->flow )
				dfs(p->to);
	}
}G;
int n, s, t;
bitset<MAXN + 5>e[MAXN + 5];
struct ACM{
	struct node{
		int ch[2], fail;
		int tag;
	}nd[MAXS + 5];
	int ncnt, root;
	ACM() {ncnt = root = 0;}
	void add(char *S, int lenS, int x) {
		int nw = root;
		for(int i=0;i<lenS;i++) {
			if( !nd[nw].ch[S[i] - 'a'] )
				nd[nw].ch[S[i] - 'a'] = (++ncnt);
			nw = nd[nw].ch[S[i] - 'a'];
		}
		nd[nw].tag = x;
	}
	void build() {
		queue<int>que;
		if( nd[root].ch[0] ) que.push(nd[root].ch[0]);
		if( nd[root].ch[1] ) que.push(nd[root].ch[1]);
		while( !que.empty() ) {
			int f = que.front(); que.pop();
			if( nd[f].ch[0] ) {
				nd[nd[f].ch[0]].fail = nd[nd[f].fail].ch[0];
				if( !nd[nd[f].ch[0]].tag ) nd[nd[f].ch[0]].tag = nd[nd[nd[f].ch[0]].fail].tag;
				que.push(nd[f].ch[0]);
			}
			else nd[f].ch[0] = nd[nd[f].fail].ch[0];
			if( nd[f].ch[1] ) {
				nd[nd[f].ch[1]].fail = nd[nd[f].fail].ch[1];
				if( !nd[nd[f].ch[1]].tag ) nd[nd[f].ch[1]].tag = nd[nd[nd[f].ch[1]].fail].tag;
				que.push(nd[f].ch[1]);
			}
			else nd[f].ch[1] = nd[nd[f].fail].ch[1];
		}
	}
	void solve(char *S, int lenS, int x) {
		int nw = root;
		for(int i=0;i<lenS;i++) {
			if( nd[nw].tag )
				e[x][nd[nw].tag] = true;
			nw = nd[nw].ch[S[i] - 'a'];
		}
		nw = nd[nw].fail;
		if( nd[nw].tag )
			e[x][nd[nw].tag] = true;
	}
}ac;
char S[MAXS + 5];
int len[MAXN + 5];
int main() {
	scanf("%d", &n), s = 0, t = 2*n + 1;
	for(int i=1;i<=n;i++) {
		scanf("%s", S + len[i-1]);
		len[i] = len[i-1] + strlen(S + len[i-1]);
		ac.add(S + len[i-1], len[i] - len[i-1], i);
	}
	ac.build();
	for(int i=1;i<=n;i++)
		G.addedge(s, i, 1), G.addedge(n + i, t, 1);
	for(int i=1;i<=n;i++)
		ac.solve(S + len[i-1], len[i] - len[i-1], i);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			if( e[i][k] ) e[i] |= e[k];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if( e[i][j] ) G.addedge(i, j + n, 1);
	printf("%d\n", n - G.max_flow(s, t));
	G.dfs(G.s);
	for(int i=1;i<=n;i++)
		if( G.vis[i] && (!G.vis[i+n]) )
			printf("%d ", i);
}