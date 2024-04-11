#include <stack>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int*, int> pii;
#define fi first
#define se second
#define mp make_pair

const int BLOCK = 225;
const int MAXN = 50000;
const int MAXK = (1 << 20);

int ch[2][2*MAXK + 5], s[MAXK + 5], cnt, rt;
int mn[2*MAXK + 5], mx[2*MAXK + 5];
int build(int dep) {
	int p = (++cnt);
	mn[p] = MAXK + 5, mx[p] = 0;
	if( dep == -1 ) return p;
	ch[0][p] = build(dep - 1);
	ch[1][p] = build(dep - 1);
	return p;
}
stack<pii>stk; int res;
void restore(int x) {
	while( stk.size() > x ) {
		pii t = stk.top(); stk.pop();
		(*t.fi) = t.se;
	}
}
void update_mx(int &p, int k) {
	if( p < k ) stk.push(mp(&p, p)), p = k;
}
void update_mn(int &p, int k) {
	if( p > k ) stk.push(mp(&p, p)), p = k;
}
int query_mn(int x, int dep, int k, int p) {
	if( dep == -1 ) return 0;
	int dir = ((k >> dep) & 1);
	if( mn[ch[!dir][x]] < p )
		return query_mn(ch[!dir][x], dep - 1, k, p) | (1 << dep);
	else return query_mn(ch[dir][x], dep - 1, k, p);
}
int query_mx(int x, int dep, int k, int p) {
	if( dep == -1 ) return 0;
	int dir = ((k >> dep) & 1);
	if( mx[ch[!dir][x]] > p )
		return query_mx(ch[!dir][x], dep - 1, k, p) | (1 << dep);
	else return query_mx(ch[dir][x], dep - 1, k, p);	
}
void insert_mn(int x, int dep, int k, int p) {
	update_mn(mn[x], p);
	if( dep == -1 ) return ;
	int dir = ((k >> dep) & 1);
	insert_mn(ch[dir][x], dep - 1, k, p);
}
void insert_mx(int x, int dep, int k, int p) {
	update_mx(mx[x], p);
	if( dep == -1 ) return ;
	int dir = ((k >> dep) & 1);
	insert_mx(ch[dir][x], dep - 1, k, p);
}
void add(int x) {
	insert_mn(rt, 19, s[x - 1], x - 1), insert_mx(rt, 19, s[x], x);
	update_mx(res, query_mn(rt, 19, s[x], x));
	update_mx(res, query_mx(rt, 19, s[x - 1], x - 1));
}

int n, m;
int le[MAXN + 5], ri[MAXN + 5], id[MAXN + 5], bcnt;
void init() {
	for(int i=1;i<MAXK;i++)
		s[i] = s[i - 1] ^ i;
	rt = build(19);
	
	for(int i=1;i<=n;i++) {
		if( (i - 1) % BLOCK == 0 )
			le[++bcnt] = i;
		ri[bcnt] = i, id[i] = bcnt;
	}
}

struct query{
	int l, r, id; query() {}
	query(int _l, int _r, int _i) : l(_l), r(_r), id(_i) {}
	friend bool operator < (query a, query b) {
		return a.r < b.r;
	}
};
int a[MAXN + 5], ans[MAXN + 5];
vector<query>qry[MAXN + 5];
int main() {
	scanf("%d%d", &n, &m), init();
	for(int i=1;i<=n;i++) scanf("%d", &a[i]);
	for(int i=1;i<=m;i++) {
		int l, r; scanf("%d%d", &l, &r);
		qry[id[l]].push_back(query(l, r, i));
	}
	for(int i=1;i<=bcnt;i++) {
		sort(qry[i].begin(), qry[i].end());
		int nwr = ri[i];
		for(int j=0;j<qry[i].size();j++) {
			int l = qry[i][j].l, r = qry[i][j].r;
			if( r <= ri[i] ) {
				for(int k=l;k<=r;k++) add(a[k]);
				ans[qry[i][j].id] = res, restore(0);
			}
			else {
				for(int k=nwr+1;k<=r;k++) add(a[k]); nwr = r;
				int tim = stk.size();
				for(int k=l;k<=ri[i];k++) add(a[k]);
				ans[qry[i][j].id] = res, restore(tim);
			}
		}
		restore(0);
	}
	for(int i=1;i<=m;i++)
		printf("%d\n", ans[i]);
}