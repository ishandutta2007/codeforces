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
#define tm afhdhn

const int MAXN = 1e5 + 20;

int n, m;
int root;
vector<int>  gr[MAXN];
int sz[MAXN], h[MAXN], maxd[MAXN];
unordered_map<string, int>  cst[MAXN];
int cnt[MAXN];
string col[MAXN];
bool big[MAXN];
int ans[MAXN];
vector<pair<int, int> >  qu[MAXN];
//unordered_map<string, int> ss;
int csz = 0;

void add(int v, int p, int d){
	if(d == 1){
		cst[h[v]][col[v]]++;
		if(cst[h[v]][col[v]] == 1){cnt[h[v]]++;}
	}
	else{
		auto it = cst[h[v]].find(col[v]);
		it->Y--;
		if(it->Y == 0){cnt[h[v]]--; cst[h[v]].era(it);}
	}
	I(u, gr[v])
		if(u != p && !big[u])add(u, v, d);
}

void dfs(int v, int p, int k){
//	printf("In %d\n", v); fflush(stdout);
	int ms = -1, bc = -1;
	I(u, gr[v]){
		if(u != p && sz[u] > ms)
			ms = sz[u], bc = u;
	}
	I(u, gr[v])
		if(u != p && u != bc)
			dfs(u, v, 0);
	if(bc != -1)
		big[bc] = true, dfs(bc, v, 1);
//	printf("Mid of %d\n", v); fflush(stdout);
	add(v, p, 1);
//	printf("Mid++ of %d\n", v); fflush(stdout);
	I(q, qu[v]){
		//printf("Query: v = %d id = %d d = %d\n", v, q.X, q.Y); fflush(stdout);
		int d = q.Y;
		int id = q.X;
		int hh = h[v] + d;
		if(hh > maxd[v]){ans[id] = 0; cont;}
//		printf("!!!! hh = %d\n", hh); fflush(stdout);
		ans[id] = cnt[hh];
	}
//	printf("Almost end of %d\n", v); fflush(stdout);
	if(bc != -1)
		big[bc] = false;
	if(k == 0)
		add(v, p, -1);
		
}

void calc(int v, int p){
	sz[v] = 1;
	h[v] = (p == -1) ? 0 : (h[p] + 1);
	maxd[v] = h[v];
	I(u, gr[v]){
		if(u == p)cont;
		calc(u, v);
		sz[v] += sz[u];
		maxd[v] = max(maxd[v], maxd[u]);
	}
}

string tmp;

void getstr(){
	tmp = "";
	char c = getc(stdin);
	while(!isalpha(c))
		c = getc(stdin);
	while(isalpha(c)){
		tmp += c;
		c = getc(stdin);
	}
}

int main(){
//	freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	scanf("%d", &n);
//	gr.rs(n + 1); sz.rs(n + 1); h.rs(n + 1); cnt.rs(n + 1); col.rs(n + 1);
//	qu.rs(n + 1); cst.rs(n + 1); maxd.rs(n + 1);
	root = n;
//	cnt.asg(n + 1, 0); big.rs(n + 1); big.asg(n + 1, false);
	fi0(big);
	F(i, 0, n){
		int p;	
		getstr();
		col[i] = tmp;
		scanf("%d", &p); p--;
		/*if(ss.count(tmp)){col[i] = ss[tmp];}
		else{col[i] = csz; ss.ins(mk(tmp, csz++));}*/
		if(p == -1){p = n;}
		gr[p].pb(i);
		gr[i].pb(p);
	}
	scanf("%d", &m);
//	ans.rs(m); 
	F(i, 0, m){
		int v, k;
		scanf("%d%d", &v, &k); v--;
		qu[v].pb(mk(i, k));
	}
	calc(root, -1);
	dfs(root, -1, 0);
	F(i, 0, m)
		printf("%d\n", ans[i]);
	ret 0;
}