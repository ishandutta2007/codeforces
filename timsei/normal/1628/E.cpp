#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int Segment_Size = N * 4;

#define lc (no << 1)
#define rc (no << 1 | 1)
#define getmid int mid = (L[no] + R[no]) >> 1

int n, m, x, y, st[N][22], fa[N], L[Segment_Size], R[Segment_Size], Tag[Segment_Size], A[Segment_Size], B[Segment_Size];
int a[Segment_Size], b[Segment_Size], who[N], dep[N], tot, w[N], dfn[N], dlc, Ba[N], q;

void pt(int no, int ty) {
	Tag[no] = ty;
	if(!ty) {
		A[no] = 1e9; B[no] = 0;
		return;
	}
	A[no] = a[no]; B[no] = b[no];
}

void up(int no) {
	A[no] = min(A[lc], A[rc]);
	B[no] = max(B[lc], B[rc]);
}

void build(int no, int l, int r) {
	L[no] = l; R[no] = r; Tag[no] = -1;
	if(l == r) {
		a[no] = b[no] = dfn[l];
		A[no] = 1e9;
		return;
	}
	getmid;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	up(no);
	a[no] = min(a[lc], a[rc]);
	b[no] = max(b[lc], b[rc]);
}

void pd(int no) {
	if(Tag[no] == -1 || L[no] == R[no]) return;
	pt(lc, Tag[no]);
	pt(rc, Tag[no]);
	up(no);
	Tag[no] = -1;
}

void PushTag(int no, int l, int r, int ty) {
	pd(no);
	if(L[no] == l && R[no] == r) {
		pt(no, ty); return;
	}
	getmid;
	if(r <= mid) PushTag(lc, l, r, ty);
	else if(l > mid) PushTag(rc, l, r, ty);
	else PushTag(lc, l, mid, ty), PushTag(rc, mid + 1, r, ty);
	up(no);
}

struct Edge {
	int x, y, w;
	friend bool operator < (Edge a, Edge b) {
		return a.w < b.w;
	}
}E[N];

int getf(int x) {return (fa[x] == x) ? x : fa[x] = getf(fa[x]);}

int LCA(int x, int y) {
	if(dep[x] >= dep[y]) swap(x, y);
	for(int i = 20; i >= 0; -- i) {
		if(dep[st[y][i]] >= dep[x]) {
			y = st[y][i];
		}
 	}
 	if(x == y) return x;
 	for(int i = 20; i >= 0; -- i) {
 		if(st[x][i] != st[y][i]) {
 			x = st[x][i]; y = st[y][i];
		 }
	}
	return st[x][0];
}

vector <int> G[N];

void dfs(int x) {
	dfn[x] = ++ dlc;
	for(int i = 1; i <= 20; ++ i)
	st[x][i] = st[st[x][i - 1]][i - 1];
	for(int i = 0; i < (int) G[x].size(); ++ i) {
		int V = G[x][i];
		dep[V] = dep[x] + 1; dfs(V);
	}
}

int main() {
	//freopen("data.txt", "r", stdin);
	cin >> n >> q;
	for(int i = 1; i < n; ++ i) {
		scanf("%d%d%d", &E[i].x, &E[i].y, &E[i].w);
	}
	//cerr <<"HERE" << endl;
	sort(E + 1, E + n);
	for(int i = 1; i <= n; ++ i) w[i] = -1;
	for(int i = 1; i <= 2 * n; ++ i) fa[i] = i;
	tot = n;
	for(int i = 1; i < n; ++ i) {
		int u = E[i].x, v = E[i].y;
		u = getf(u); v = getf(v);
		++ tot;
		fa[u] = fa[v] = tot;
		w[tot] = E[i].w;
		st[u][0] = tot; st[v][0] = tot;
		G[tot].push_back(u);
		G[tot].push_back(v);
	}
	dfs(tot);
	for(int i = 1; i <= tot; ++ i) Ba[dfn[i]] = i;
	build(1, 1, n);
	for(int i = 1, ty, l, r, x; i <= q; ++ i) {
		scanf("%d", &ty);
		if(ty <= 2) {
			scanf("%d%d", &l, &r);
			PushTag(1, l, r, 2 - ty);
		} else {
			scanf("%d", &x);
			if(A[1] == 1e9) {
				puts("-1");
				continue;
			}
			l = A[1], r = B[1];
			int ans = -1;
			l = LCA(Ba[l], x); r = LCA(Ba[r], x);
			ans = max(ans, w[l]);
			ans = max(ans, w[r]);
			//cerr << A[1] <<' ' << B[1] <<' ' << ans <<' ' << dfn[x] << endl;
			printf("%d\n", ans);
		}
	}
}