#include <set>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100000;

struct edge{
	int to, dis; edge *nxt;
}edges[2*MAXN + 5], *adj[MAXN + 5], *ecnt = edges;
void addedge(int u, int v, int w) {
	edge *p = (++ecnt);
	p->to = v, p->dis = w, p->nxt = adj[u], adj[u] = p;
	p = (++ecnt);
	p->to = u, p->dis = w, p->nxt = adj[v], adj[v] = p;
}

ll ans; int siz[MAXN + 5], rt, n;
void get_rt(int x, int f) {
	int mx = 0; siz[x] = 1;
	for(edge *p=adj[x];p;p=p->nxt) {
		if( p->to == f ) continue;
		get_rt(p->to, x), siz[x] += siz[p->to];
		ans += 2LL * min(siz[p->to], n - siz[p->to]) * p->dis;
		mx = max(mx, siz[p->to]);
	}
	mx = max(mx, n - siz[x]);
	if( 2*mx <= n ) rt = x;
}
int id[MAXN + 5], num[MAXN + 5], cnt;
void get_id(int x, int f, int i) {
	id[x] = i, num[i]++;
	for(edge *p=adj[x];p;p=p->nxt)
		if( p->to != f ) get_id(p->to, x, i);
}

struct heap{
	priority_queue<int>q1, q2;
	void maintain() {
		while( !q1.empty() && !q2.empty() && q1.top() == q2.top() )
			q1.pop(), q2.pop();
	}
	bool empty() {maintain(); return q1.empty();}
	int top() {maintain(); return q1.top();}
	int size() {maintain(); return q1.size() - q2.size();}
	void push(int x) {q1.push(x); maintain();}
	void erase(int x) {q2.push(x); maintain();}
}h1, h2[MAXN + 5], h3, A, B;

bool tag[MAXN + 5];
int main() {
	scanf("%d", &n);
	for(int i=1;i<n;i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w);
	}
	get_rt(1, 0), printf("%lld\n", ans);
	for(edge *p=adj[rt];p;p=p->nxt)
		get_id(p->to, rt, ++cnt);
	id[rt] = 0, num[0] = 0;
	for(int i=1;i<=n;i++)
		h2[id[i]].push(-i);
	for(int i=0;i<=cnt;i++)
		num[i] *= 2, h1.push(num[i]), h3.push(h2[i].top());
	int nw = 1;
	while( nw <= n && h1.top() < n - nw + 1 ) {
		h1.erase(num[id[nw]]), num[id[nw]]--, h1.push(num[id[nw]]);
		if( nw != rt ) h3.erase(h2[id[nw]].top());
		int res = -h3.top(); printf("%d ", res), tag[res] = true;
		h1.erase(num[id[res]]), num[id[res]]--, h1.push(num[id[res]]);
		h3.erase(h2[id[res]].top()), h2[id[res]].erase(-res);
		if( !h2[id[res]].empty() ) h3.push(h2[id[res]].top());
		if( nw != rt ) h3.push(h2[id[nw]].top());
		nw++;
	}
	if( nw <= n ) {
		int mx;
		for(int i=0;i<=cnt;i++)
			if( num[i] == n - nw + 1 ) mx = i;
		for(int i=1;i<=n;i++) {
			if( tag[i] ) continue;
			if( id[i] == mx ) A.push(-i);
			else B.push(-i);
		}
		while( nw <= n ) {
			if( id[nw] == mx ) {
				int res = -B.top();
				printf("%d ", res);
				B.erase(-res);
			}
			else {
				int res = -A.top();
				printf("%d ", res);
				A.erase(-res);
			}
			nw++;
		}
	}
}