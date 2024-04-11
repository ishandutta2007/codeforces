#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int N, M;
struct segtree {
	int tree[1050000][2];
	int lazy[1050000];
	void pu(int idx) {
		tree[idx][0] = max(tree[idx*2][0],tree[idx*2+1][0]);
		tree[idx][1] = max(tree[idx*2][1],tree[idx*2+1][1]);
	}
	void pd(int idx) {
		if (lazy[idx]) {
			lazy[idx*2]^=1;
			lazy[idx*2+1]^=1;
			swap(tree[idx*2][0],tree[idx*2][1]);
			swap(tree[idx*2+1][0],tree[idx*2+1][1]);
			lazy[idx] = 0;
		}
	}
	void init(int col[], int dep[], int lab[], int s=0, int e=N-1, int idx=1) {
		if (s==e) {
			tree[idx][col[lab[s]]] = dep[lab[s]];
			tree[idx][col[lab[s]]^1]= -1;
			return;
		}
		int m = (s+e)/2;
		init(col,dep,lab,s,m,idx*2);
		init(col,dep,lab,m+1,e,idx*2+1);
		pu(idx);
	}
	void upd(int S, int E, int s=0, int e=N-1, int idx=1) {
		if (e<S||E<s) return;
		if (S<=s&&e<=E) {
			lazy[idx] ^=1;
			swap(tree[idx][0],tree[idx][1]);
			return;
		}
		pd(idx);
		int m = (s+e)/2;
		upd(S,E,s,m,idx*2);
		upd(S,E,m+1,e,idx*2+1);
		pu(idx);
	}
	int getv(int S, int E, int t, int s=0, int e=N-1, int idx=1) {
		if (e<S||E<s) return 0;
		if (S<=s&&e<=E) {
			return tree[idx][t];
		}
		pd(idx);
		int m = (s+e)/2;
		return max(getv(S,E,s,m,idx*2), getv(S,E,m+1,e,idx*2+1));
	}
	int getc(int i, int s=0, int e=N-1, int idx=1) {
		if (s==e) {
			if (tree[idx][0]==-1) return 1;
			return 0;
		}
		pd(idx);
		int m = (s+e)/2;
		if (i<=m) return getc(i,s,m,idx*2);
		return getc(i,m+1,e,idx*2+1);
	}
} seg[2];

vector<pii> lis[500100];
int col[2][500100], lab[2][500100], dep[2][500100];
int st[2][500100], en[2][500100];
pii edg[500100];

int tim;
void dfs(int here, int p, int c, int t) {
	st[t][here] = tim;
	lab[t][tim] = here;
	col[t][here] = c;
	dep[t][here] = (~p?dep[t][p]:-1)+1;
	tim++;
	for (pii &e : lis[here]) {
		if (e.second != p) {
			dfs(e.second, here, c^e.first, t);
		}
	}
	en[t][here] = tim-1;
}

int md, mt;
void idfs(int here, int p, int d) {
	if (md<d) {
		md=d;
		mt=here;
	}
	for (pii &e : lis[here]) {
		if (e.second != p) {
			idfs(e.second,here,d+1);
		}
	}
}

int main() {
	scanf("%d",&N);
	for (int i=0;i<N-1;i++) {
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c); --a; --b;
		lis[a].push_back({c,b});
		lis[b].push_back({c,a});
		edg[i] = {a,b};
	}
	md = -1;
	idfs(0,-1,0);
	int u = mt;
	md = -1;
	idfs(u, -1, 0);
	int v = mt;
	tim = 0;
	dfs(u,-1,0,0);
	tim = 0;
	dfs(v,-1,0,1);

	seg[0].init(col[0],dep[0],lab[0]);
	seg[1].init(col[1],dep[1],lab[1]);

	scanf("%d",&M);
	for (int i=0;i<M;i++) {
		int e;
		scanf("%d",&e); --e;
		int tu = edg[e].first, tv = edg[e].second;
		for (int t=0;t<2;t++) {
			if (dep[t][tu]>dep[t][tv]) swap(tu,tv);
			seg[t].upd(st[t][tv],en[t][tv]);
		}
		int c1 = seg[0].getc(st[0][u]);
		int c2 = seg[0].getc(st[0][v]);
		int df = (c1^c2);
		if (df) {
			printf("%d\n",max(seg[0].getv(0,N-1,c1),seg[1].getv(0,N-1,seg[1].getc(st[1][v]))));
		}
		else {
			printf("%d\n",md);
		}
	}

	return 0;
}