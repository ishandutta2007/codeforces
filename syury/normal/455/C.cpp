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
#define y1 adjf

int n, m, q;
vector<list<int> > gr;
vector<int> deg;
vector<int> p, ds;
vector<int> rnk, maxp, cen, cdi;
vector<int> tmp; 
queue<int> proc;
queue<int> bq;
set<pair<int, int> > ss;

void mark(int v, int id){
	p[v] = id;
	I(u, gr[v]){
		if(p[u] == -1)mark(u, id);
	}
}

void getcd(int cc){
	tmp[cc] = 0;
	bq.push(cc);
	cdi[p[cc]] = 0;
	while(!bq.empty()){
		int v = bq.front(); bq.pop();
		I(u, gr[v]){
			if(tmp[u] == -1){
				bq.push(u); tmp[u] = tmp[v] + 1; cdi[p[cc]] = max(cdi[p[cc]], tmp[v] + 1);
			}
		}
	}
}



int dist(int v, int p, bool tt){
	if(p != -1){
		if(tt)tmp[v] = tmp[p] + 1;
		else rnk[v] = rnk[p] + 1;
	}
	int ca = v;
	I(u, gr[v]){
		if(u != p){
			int cu = dist(u, v, tt);
			if(tt){if(tmp[cu] > tmp[ca])ca = cu;}
			else{if(rnk[cu] > rnk[ca])ca = cu;}
		}
	}
	ret ca;
}

void findmp(int ex){
	int u = dist(ex, -1, true);
	u = dist(u, -1, false);
	maxp[p[ex]] = rnk[u];
}

int find_set(int v){
	ret (v == ds[v]) ? v : ds[v] = find_set(ds[v]);
}

void unite_sets(int v, int u){
	v = find_set(v); u = find_set(u);
	if(v == u)ret;
	if(rnk[v] > rnk[u])swap(v, u);
	ds[v] = u;
	if(rnk[v] == rnk[u])rnk[u]++;
	maxp[u] = max({maxp[v], maxp[u], cdi[v] + cdi[u] + 1});
	int rl = max(cdi[v], 1 + cdi[u]);
	int rr = max(cdi[u], 1 + cdi[v]);
	if(rl < rr){cdi[u] = rl;}else{cdi[u] = rr;}
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
	scanf("%d%d%d", &n, &m, &q);
	gr.rs(n); deg.rs(n); p.rs(n); rnk.rs(n); maxp.rs(n); cen.rs(n); cdi.rs(n);
	ds.rs(n);
	tmp.rs(n); tmp.asg(n, -1);
	p.asg(n, -1);
	rnk.asg(n, 0); deg.asg(n, 0);
	F(i, 0, m){
		int v, u;
		scanf("%d%d", &v, &u); v--; u--;
		gr[v].pb(u); gr[u].pb(v);
		deg[v]++; deg[u]++;
	}
	F(i, 0, n)ss.ins(mk(deg[i], i));
	int cp = 0;
	F(i, 0, n){
		if(p[i] == -1)mark(i, cp++);
	}
	while(!ss.empty()){
		if(ss.begin()->X == 0){cen[p[ss.begin()->Y]] = ss.begin()->Y; ss.era(ss.begin()); cont;}
		if(ss.begin()->X > 1){printf("!!!"); ret 1111;}
		while(!ss.empty() && ss.begin()->X == 1){
			proc.push(ss.begin()->Y); ss.era(ss.begin());
		}
		while(!proc.empty()){
			int v = proc.front(); proc.pop();
			if(deg[v] == 0){ss.ins(mk(deg[v], v)); cont;}
			I(u, gr[v]){
				if(deg[u] == 0)cont;
				ss.era(mk(deg[u], u)); deg[u]--; ss.ins(mk(deg[u], u));
			}
			deg[v] = 0;
		}
	}
	F(i, 0, n){
		if(cdi[p[i]] == 0)getcd(cen[p[i]]);
	}
	tmp.asg(n, 0);
	F(i, 0, n){
		if(maxp[p[i]] == 0)findmp(i);
	}
	//F(i, 0, cp)printf("Maxp = %d cdi = %d cen = %d\n", maxp[i], cdi[i], cen[i]);
	rnk.asg(n, 0);
	//F(i, 0, n)rnk[p[i]]++;
	F(i, 0, cp){ds[i] = i; rnk[i] = 0;}
	F(i, 0, q){
		int tp;
		scanf("%d", &tp);
		if(tp == 1){
			int v;
			scanf("%d", &v); v--;
			printf("%d\n", maxp[find_set(p[v])]);
		}
		else{
			int v, u;
			scanf("%d%d", &v, &u);v--; u--;
			unite_sets(p[v], p[u]);
		}
	}
	ret 0;
}