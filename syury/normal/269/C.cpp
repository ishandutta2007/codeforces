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
#define acpy(x, y) memcpy(x, y, sizeof(y))
#define y1 adjf

struct edge{
	int v, u, c;
	int type = -1;
	edge(){}
	edge(int _v, int _u, int _c):v(_v), u(_u), c(_c){}
	void orient_from(int i){type = (i == v) ? 0 : 1;}
	int get_next(int i){ret (i == v) ? u : v;}
};

int n, m;
vector<list<int> > gr;
vector<edge> e;
set<int> s;
vector<int> in, ts;

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &m);
	gr.rs(n); e.rs(m); in.rs(n); ts.rs(n);
	in.asg(n, 0); ts.asg(n, 0);
	F(i, 0, m){
		int v, u, c;
		scanf("%d%d%d", &v, &u, &c); v--; u--;
		e[i] = edge(v, u, c);
		gr[v].pb(i); gr[u].pb(i);
		ts[v] += c; ts[u] += c;
	}
	s.ins(0);
	while(!s.empty()){
		int v = *s.begin();
		s.era(s.begin());
		I(i, gr[v]){
			if(e[i].type != -1)cont;
			e[i].orient_from(v);
			int u = e[i].get_next(v);
			if(u == n - 1)cont;
			in[u] += e[i].c;
			if(in[u] + in[u] == ts[u])s.ins(u);
		}
	}
	F(i, 0, m)printf("%d\n", e[i].type);
	ret 0;
}