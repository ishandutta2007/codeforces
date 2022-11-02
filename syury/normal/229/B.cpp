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

const int inf = 2e9 + 100;

int n, m;
vector<list<pair<int, int> > > gr;
vector<int> d;
vector<vector<int> > t;
set<pair<int, int> > s;

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	gr.rs(n); d.rs(n); d.asg(n, inf); d[0] = 0; t.rs(n);
	F(i, 0, m){
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w); v--; u--;
		gr[v].pb(mk(u, w)); gr[u].pb(mk(v, w));
	}
	F(i, 0, n){
		int k;
		scanf("%d", &k); t[i].rs(k);
		F(j, 0, k){
			scanf("%d", &t[i][j]);
		}
	}
	t[n - 1].clear();
	s.ins(mk(0, 0));
	while(!s.empty()){
		int v = s.begin()->Y;
		s.era(s.begin());
		F(i, 0, (int)t[v].size()){
			if(t[v][i] == d[v])d[v]++;
		}
		I(p, gr[v]){
			int u = p.X, w = p.Y;
			if(d[u] > d[v] + w){s.era(mk(d[u], u)); d[u] = d[v] + w; s.ins(mk(d[u], u));}
		}
	}
	if(d[n - 1] == inf)printf("-1"); else printf("%d", d[n - 1]);
	ret 0;
}