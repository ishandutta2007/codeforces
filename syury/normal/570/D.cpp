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

const int L = 26;

int n, m;
vector<int> sz, h, maxd, cnt;
vector<int> col;
vector<vector<int> > cl;
vector<list<int> > gr;
vector<list<pair<int, int> > > qu;
vector<char> ans;
vector<char> big;

void add(int v, int p, int d){
	if(cl[h[v]][col[v]]&1){cnt[h[v]]--;}
	cl[h[v]][col[v]] += d;
	if(cl[h[v]][col[v]]&1){cnt[h[v]]++;}
	I(u, gr[v]){
		if(u != p && !big[u])
			add(u, v, d);
	}
}

void dfs(int v, int p, int k){
	int ms = -1, bc = -1;
	I(u, gr[v]){
		if(u != p && sz[u] > ms)
			ms = sz[u], bc = u;
	}
	I(u, gr[v]){
		if(u != p && u != bc)
			dfs(u, v, 0);
	}
	if(bc != -1)
		dfs(bc, v, 1), big[bc] = true;
	add(v, p, 1);
	I(q, qu[v]){
		if(maxd[v] < q.X){ans[q.Y] = true; cont;}
		if(cnt[q.X] <= 1){ans[q.Y] = true;}
		else{ans[q.Y] = false;}
	}
	if(bc != -1)
		big[bc] = false;
	if(k == 0)
		add(v, p, -1);
}

void proc(int v, int p){
	sz[v] = 1;
	h[v] = (p == -1) ? 0 : (h[p] + 1);
	maxd[v] = h[v];
	I(u, gr[v]){
		if(u == p)cont;
		proc(u, v);
		maxd[v] = max(maxd[v], maxd[u]);
		sz[v] += sz[u];
	}
}

char getl(){
	char c = getc(stdin);
	while(!isalpha(c))
		c = getc(stdin);
	ret c;
}

int main(){
	scanf("%d%d", &n, &m);
	col.rs(n);
	gr.rs(n); qu.rs(n); cl.rs(n); cnt.rs(n); cnt.asg(n, 0);
	sz.rs(n); h.rs(n); big.rs(n); ans.rs(m); maxd.rs(n);
	big.asg(n, false);
	F(i, 0, n)
		cl[i].rs(26);
	F(i, 1, n){
		int pr;
		scanf("%d", &pr); pr--;
		gr[pr].pb(i);
		gr[i].pb(pr);
	}
	F(i, 0, n){
		char c = getl();
		col[i] = c - 'a';
	}
	F(i, 0, m){
		int v, ch;
		scanf("%d%d", &v, &ch); v--; ch--;
		qu[v].pb(mk(ch, i));
	}
	proc(0, -1);
	dfs(0, -1, 0);
	F(i, 0, m){
		if(ans[i])
			printf("Yes\n");
		else
			printf("No\n");
	}
	ret 0;
}