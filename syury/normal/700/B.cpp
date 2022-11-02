#include<bits/stdc++.h>

using namespace std;
typedef long long lint;
typedef long double ldb;
typedef unsigned long long uli;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define uF(i, l, r) for(i = l; i != r; i++)
#define uDf(i, l, r) for(i = l; i != r; i--)
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
#define y1 adjf

int n, k;
vector<list<int> > gr;
vector<lint> un;

void dfs(int v, int p = -1){
	F(it, gr[v].begin(), gr[v].end()){
		int u = *it;
		if(u == p){cont;}
		dfs(u, v);
		un[v] += un[u];
	}
}

lint tot = 0ll;

void solve(int v, int p = -1){
	F(it, gr[v].begin(), gr[v].end()){
		int u = *it;
		if(u == p){cont;}
		solve(u, v);
		tot += min(un[u], un[0] - un[u]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d%d", &n, &k);
	gr.rs(n); un.rs(n); un.asg(n, 0);
	F(i, 0, 2 * k){
		int v;
		scanf("%d", &v); v--;
		un[v] = 1;
	}
	F(i, 0, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		v--; u--;
		gr[v].pb(u); gr[u].pb(v);
	}
	dfs(0);
	solve(0);
	printf("%lld", tot);
	ret 0;
}