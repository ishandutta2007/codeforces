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

struct frac{
	int p, q;
	frac(){}
	frac(int _p, int _q):p(_p), q(_q){}
};

bool operator < (const frac & a, const frac & b){
	ret a.p * 1ll * b.q < b.p * 1ll * a.q;
}

int n, m, k;
set<pair<frac, int> > s;
frac best = frac(0, 1);
vector<char> fort;
vector<char> alive;
vector<list<int> > gr;
vector<frac> cs;
int del = 0, bdel = 0;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d%d", &n, &m, &k);
	gr.rs(n); cs.rs(n); fort.rs(n); alive.rs(n);
	fort.asg(n, false); alive.asg(n, true);
	F(i, 0, k){
		int v;
		scanf("%d", &v); v--;
		fort[v] = true;
	}
	F(i, 0, m){
		int v, u;
		scanf("%d%d", &v, &u); v--; u--;
		gr[v].pb(u); gr[u].pb(v);
	}
	F(i, 0, n){
		int ne = gr[i].size();
		int g = 0;
		I(u, gr[i])if(!fort[u])g++;
		cs[i] = frac(g, ne);
		if(!fort[i])s.ins(mk(cs[i], i)); else alive[i] = false;
	}
	while(!s.empty()){
		if(best < s.begin()->X){best = s.begin()->X; bdel = del;}
		del++;
		int v = s.begin()->Y;
		s.era(s.begin());
		alive[v] = false;
		I(u, gr[v])if(alive[u]){s.era(mk(cs[u], u)); cs[u] = frac(cs[u].p - 1, cs[u].q); s.ins(mk(cs[u], u));}
	}
	alive.asg(n, true);
	F(i, 0, n){
		int ne = gr[i].size();
		int g = 0;
		I(u, gr[i])if(!fort[u])g++;
		cs[i] = frac(g, ne);
		if(!fort[i])s.ins(mk(cs[i], i)); else alive[i] = false;
	}
	del = 0;
	while(!s.empty()){
		if(del == bdel){
			printf("%d\n", (int)s.size());
			I(v, s)printf("%d ", v.Y + 1);
			ret 0;
		}
		del++;
		int v = s.begin()->Y;
		s.era(s.begin());
		alive[v] = false;
		I(u, gr[v])if(alive[u]){s.era(mk(cs[u], u)); cs[u] = frac(cs[u].p - 1, cs[u].q); s.ins(mk(cs[u], u));}
	}
	ret 0;
}