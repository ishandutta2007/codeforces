#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 10000;
const int MAXM = 100000;
const int MAXK = 2000000;
const int INF = (1<<30);
struct FlowGraph{
	struct edge{
		int to, cap, flow;
		edge *nxt, *rev;
	}edges[2*MAXK + 5], *adj[MAXM + 5], *ecnt=&edges[0];
	int S, T, d[MAXM + 5], vd[MAXM + 5];
	void addedge(int u, int v, int c) {
		edge *p = (++ecnt);
		p->to = v, p->cap = c, p->flow = 0;
		p->nxt = adj[u], adj[u] = p;
		edge *q = (++ecnt);
		q->to = u, q->cap = 0, q->flow = 0;
		q->nxt = adj[v], adj[v] = q;
		p->rev = q, q->rev = p;
	}
	int aug(int x, int tot) {
		if( x == T ) return tot;
		int mind = T+1, sum = 0;
		for(edge *p=adj[x];p!=NULL;p=p->nxt) {
			if( p->cap > p->flow ) {
				if( d[p->to] + 1 == d[x] ) {
					int del = aug(p->to, min(tot-sum, p->cap-p->flow));
					p->flow += del, p->rev->flow -= del, sum += del;
					if( d[S] == T+1 ) return sum;
					if( sum == tot ) return sum;
				}
				mind = min(mind, d[p->to]);
			}
		}
		if( sum == 0 ) {
			vd[d[x]]--;
			if( vd[d[x]] == 0 )
				d[S] = T+1;
			d[x] = mind + 1;
			vd[d[x]]++;
		}
		return sum;
	}
	int max_flow() {
		int flow = 0;
		while( d[S] < T+1 )
			flow += aug(S, INF);
		return flow;
	}
}G;
int cnt = 0;
struct SegmentTree{
	int le, ri, num;
}t[2][4*MAXN + 5];
vector<int>v[2];
void build_segtree(int x, int l, int r, int n) {
	t[n][x].le = l, t[n][x].ri = r, t[n][x].num = (++cnt);
	if( l == r ) return ;
	int mid = (l + r) >> 1;
	build_segtree(x<<1, l, mid, n);
	build_segtree(x<<1|1, mid+1, r, n);
}
void build_edge_segtree(int x, int n) {
	if( t[n][x].le == t[n][x].ri ) {
		if( n == 0 ) G.addedge(G.S, t[n][x].num, 1);
		else G.addedge(t[n][x].num, G.T, 1);
	}
	else {
		if( n == 0 ) {
			G.addedge(t[n][x<<1].num, t[n][x].num, INF);
			G.addedge(t[n][x<<1|1].num, t[n][x].num, INF);
		}
		else {
			G.addedge(t[n][x].num, t[n][x<<1].num, INF);
			G.addedge(t[n][x].num, t[n][x<<1|1].num, INF);
		}
		build_edge_segtree(x<<1, n);
		build_edge_segtree(x<<1|1, n);
	}
}
void get_segment(int x, int l, int r, int n) {
	if( l <= t[n][x].le && t[n][x].ri <= r ) {
		v[n].push_back(t[n][x].num);
		return ;
	}
	if( l > t[n][x].ri || r < t[n][x].le )
		return ;
	get_segment(x<<1, l, r, n);
	get_segment(x<<1|1, l, r, n);
}
void build_edge_area(int x1, int y1, int x2, int y2) {
	if( x1 > x2 || y1 > y2 ) return ;
	v[0].clear(), v[1].clear();
	get_segment(1, x1, x2, 0);
	get_segment(1, y1, y2, 1);
	for(int i=0;i<v[0].size();i++)
		for(int j=0;j<v[1].size();j++)
			G.addedge(v[0][i], v[1][j], INF);
}
struct node{
	int le, ri;
	node(int _l=0, int _r=0):le(_l), ri(_r){}
};
vector<node>vec[MAXN + 5][2];
int left[MAXN + 5];
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	build_segtree(1, 1, n, 0); build_segtree(1, 1, n, 1); G.T = cnt + 1;
	build_edge_segtree(1, 0); build_edge_segtree(1, 1);
	for(int i=1;i<=q;i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
		vec[x1][0].push_back(node(y1, y2));
		vec[x2][1].push_back(node(y1, y2));
	}
	vec[n+1][0].push_back(node(1, n));
	for(int i=1;i<=n+1;i++) {
		for(int j=0;j<vec[i][0].size();j++) {
			int lst = vec[i][0][j].le;
			for(int k=vec[i][0][j].le+1;k<=vec[i][0][j].ri;k++)
				if( left[k] != left[k-1] )
					build_edge_area(left[k-1]+1, lst, i-1, k-1), lst = k;
			build_edge_area(left[vec[i][0][j].ri]+1, lst, i-1, vec[i][0][j].ri);
		}
		for(int j=0;j<vec[i][1].size();j++)
			for(int k=vec[i][1][j].le;k<=vec[i][1][j].ri;k++)
				left[k] = i;
	}
	int ans = G.max_flow();
	printf("%d\n", ans);
}