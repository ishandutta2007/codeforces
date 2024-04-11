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
#define tm afhdhn

int n;
vector<list<int> > gr;
vector<lint> a;
vector<int> p;
vector<int> out;
vector<lint> car;
//lint ans = 0ll;
vector<vector<lint> > cp, cm;

pair<lint, lint> dfs(int v, int pr = -1){
	p[v] = pr;
	int sz = 0;
	I(u, gr[v])
		if(u != pr){pair<lint, lint> crr = dfs(u, v); cp[v].pb(crr.X); cm[v].pb(crr.Y); sz++;}
	pair<lint, lint> cans = {0ll, 0ll};
	sort(cp[v].begin(), cp[v].begin() + sz);
	sort(cm[v].begin(), cm[v].begin() + sz);
	lint cr = 0ll;
	F(i, 0, sz){
		cp[v][i] -= cr;
		cans.X += cp[v][i];
		cr += cp[v][i];
	}
	cr = 0ll;
	F(i, 0, sz){
		cm[v][i] -= cr;
		cans.Y += cm[v][i];
		cr += cm[v][i];
	}	a[v] += cans.X - cans.Y;
	if(a[v] > 0)cans.Y += a[v];
	else cans.X -= a[v];
	ret cans;
}

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	gr.rs(n); a.rs(n); p.rs(n); out.rs(n); out.asg(n, 0);
	car.rs(n); car.asg(n, 0);
	cp.rs(n); cm.rs(n);
	F(i, 0, n - 1){
		int v, u;
		scanf("%d%d", &v, &u); v--; u--;
		gr[v].pb(u); gr[u].pb(v);
	}
	F(i, 0, n)scanf("%lld", &a[i]);
	pair<lint, lint> ans = dfs(0);
	printf("%lld", ans.X + ans.Y);
	ret 0;
}