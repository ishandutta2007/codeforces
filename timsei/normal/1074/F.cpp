#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int M = N * 2;
const int Segment_Size = N * 4;

map <pair <int, int> , int> Map;

int n, m, x, y, fir[N], ne[M], to[M], cnt, Ldfn[N], Rdfn[N];
int L[Segment_Size], R[Segment_Size], Min[Segment_Size], Num[Segment_Size], Add[Segment_Size];

long long ans = 0, ntot = 0;


#define lc (no << 1)
#define rc (no << 1 | 1)
#define getmid int mid = (L[no] + R[no]) >> 1

void up(int no) {
  Min[no] = Min[lc];
  Num[no] = Num[lc];
  if(Min[lc] == Min[rc]) {
    Num[no] += Num[rc];
  }
  else if(Min[rc] < Min[lc]){
    Min[no] = Min[rc];
    Num[no] = Num[rc];
  }
}

void build(int no, int l, int r) {
  L[no] = l, R[no] = r, Min[no] = 0, Num[no] = r - l + 1;
  Add[no] = 0;
  if(l == r) return;
  getmid;
  build(lc, l, mid);
  build(rc, mid + 1, r);
  up(no);
}

void pd(int no) {
  if(L[no] == R[no]) return;
  Min[lc] += Add[no];
  Min[rc] += Add[no];
  Add[lc] += Add[no];
  Add[rc] += Add[no];
  Add[no] = 0;
  up(no);
}

void chg(int no, int l, int r, int x) {
  if(L[no] == l && R[no] == r) {
    //cerr << l <<" " << r <<" " << x <<" " << Min[no] << " " << ntot << endl;
    if(!Min[no]) ntot -= Num[no];
    Min[no] += x;
    Add[no] += x;
    if(!Min[no]) ntot += Num[no];
    //cerr << l <<" " << r <<" " << x <<" " << Min[no] << " " << ntot << endl;
    return;
  }
  pd(no);
  getmid;
  if(l > mid) chg(rc, l, r, x);
  else if(r <= mid) chg(lc, l, r, x);
  else chg(lc, l, mid, x), chg(rc, mid + 1, r, x);
  up(no);
}

void add(int x, int y) {
	ne[++ cnt] = fir[x];
	fir[x] = cnt;
	to[cnt] = y;
}

void link(int x, int y) {
	add(x, y);
	add(y, x);
}

#define Foreachson(i, x) for(int i = fir[x];i ; i = ne[i])

int dlc, st[N][20], dep[N];

void dfs(int x, int f) {
	Ldfn[x] = ++ dlc;
	dep[x] = dep[f] + 1;
	st[x][0] = f;
	for(int i = 1; i <= 19; ++ i) st[x][i] = st[st[x][i - 1]][i - 1];
	Foreachson(i, x) {
		int V = to[i];
		if(V == f) continue;
		dfs(V, x);
	}
	Rdfn[x] = dlc;
}

int LCA(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 19; i >= 0; -- i) {
		if(dep[st[x][i]] >= dep[y]) x = st[x][i];
	}
	if(x == y) return x;
	for(int i = 19; i >= 0; -- i) {
		if(st[x][i] != st[y][i]) x = st[x][i], y = st[y][i];
	}
	return st[x][0];
}

void add(int x, int y, int K) {
	if(dep[x] > dep[y]) swap(x, y);
	int now = LCA(x, y);
	if(now == x) {
		int it = dep[y] - dep[x];
		-- it;
		int ny = y;
		for(int i = 19; i >= 0; -- i) if((it >> i) & 1) ny = st[ny][i];
		if(K == 1) {
			chg(1, Ldfn[ny], Rdfn[ny], K);
			chg(1, Ldfn[y], Rdfn[y], -K);
		}
		else {
			chg(1, Ldfn[y], Rdfn[y], -K);
			chg(1, Ldfn[ny], Rdfn[ny], K);
		}
		return;
	}
	else {
		if(K == 1) {
			chg(1, 1, n, K);
			chg(1, Ldfn[x], Rdfn[x], -K);
			chg(1, Ldfn[y], Rdfn[y], -K);		
		}
		else {
			chg(1, Ldfn[x], Rdfn[x], -K);
			chg(1, Ldfn[y], Rdfn[y], -K);			
			chg(1, 1, n, K);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i < n; ++ i) {
		scanf("%d%d", &x, &y);
		link(x, y);
	}
	ntot = n;
	build(1, 1, n);
	dfs(1, 0);
	for(int i = 1; i <= m; ++ i) {
		scanf("%d%d", &x, &y);
		if(x > y) swap(x, y);
		if(Map.count(make_pair(x, y))) {
			add(x, y, -1);
			Map.erase(make_pair(x, y));
		}
		else {
			add(x, y, 1);
			Map[make_pair(x, y)] = 1;
		}
		printf("%lld\n", ntot);
	}
}