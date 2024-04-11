#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf
#define tm dhgdg

const int MAXN = 5e5 + 5;

int lv[MAXN], rv[MAXN];
vector<int> gr[MAXN];
int col[4 * MAXN + 3];
int t[4 * MAXN + 3];
int ver[4 * MAXN + 3];
int cid = 0;
int n, m;

void dfs(int v, int p = -1){
	lv[v] = cid++;
	rv[v] = lv[v];
	I(u, gr[v])
		if(u != p){dfs(u, v); rv[v] = max(rv[u], rv[v]);}
}

void push(int v, bool leaf){
	if(ver[v] == -1)ret;
	col[v] = ver[v];
	if(!leaf){
		ver[v + v] = ver[v];
		ver[v + v + 1] = ver[v];
	}
	ver[v] = -1;
}

void build(int v, int l, int r){
	t[v] = -1;
	col[v] = -2;
	ver[v] = -1;
	if(l == r)ret;
	int mid = (l + r) >> 1;
	build(v + v, l, mid);
	build(v + v + 1, mid + 1, r);
}

void paint(int v, int l, int r, int ul, int ur, int nc){
	if(ul > ur)ret;
	push(v, l == r);
	if(l == ul && r == ur){ver[v] = nc; ret;}
	int mid = (l + r) >> 1;
	paint(v + v, l, mid, ul, min(ur, mid), nc);
	paint(v + v + 1, mid + 1, r, max(ul, mid + 1), ur, nc);
}

void upd(int v, int l, int r, int pos, int nv){
	t[v] = nv;
	if(l == r)ret;
	int mid = (l + r) >> 1;
	if(pos <= mid)upd(v + v, l, mid, pos, nv);
	else upd(v + v + 1, mid + 1, r, pos, nv);
}

int color(int v, int l, int r, int pos){
	push(v, l == r);
	if(l == r)ret col[v];
	int mid = (l + r) >> 1;
	if(pos <= mid)ret color(v + v, l, mid, pos);
	else ret color(v + v + 1, mid + 1, r, pos);
}

int get(int v, int l, int r, int ul, int ur){
	if(ul > ur)ret -2;
	if(l == ul && r == ur)ret t[v];
	int mid = (l + r) >> 1;
	ret max(get(v + v, l, mid, ul, min(ur, mid)), get(v + v + 1, mid + 1, r, max(ul, mid + 1), ur));
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	F(i, 0, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		v--; u--;
		gr[v].pb(u); gr[u].pb(v);
	}
	dfs(0);
	build(1, 0, n - 1);
	scanf("%d", &m);
	F(i, 0, m){
		int c, v;
		scanf("%d%d", &c, &v); v--;
		if(c == 1)paint(1, 0, n - 1, lv[v], rv[v], i);
		if(c == 2)upd(1, 0, n - 1, lv[v], i);
		if(c == 3)printf("%d\n", (get(1, 0, n - 1, lv[v], rv[v]) > color(1, 0, n - 1, lv[v])) ? 0 : 1);
	}
	ret 0;
}