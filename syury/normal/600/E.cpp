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

vector<int> cnt, sz;
int mx = 0, cmx = 0;
lint sum = 0ll;
int n;
vector<list<int> > gr;
vector<int> col;
vector<lint> ans;
vector<char> big;
vector<lint> cc;
set<pair<int, int>, greater<pair<int, int> > > ss;
int c;

void mod(int c, int d){
//	printf("mod %d %d\n", c, d); fflush(stdout);
//	ss.era(mk(cnt[c], c));
//	cc[cnt[c]] -= c;
//	if(cnt[c] == mx){sum -= c;}
//	cnt[c] += d;
//	cc[cnt[c]] += c;
//	ss.ins(mk(cnt[c], c));
//	if(ss.begin()->X > mx || sum == 0ll){
//		mx = ss.begin()->X;
//		sum = cc[mx];
//	}
}

void add(int v, int p, int val){
//	printf("add %d %d\n", v, val); fflush(stdout);
	c = col[v];
//	printf("c = %d cnt = %d\n", c, cnt[c]);
	ss.era(mk(cnt[c], c));
	cc[cnt[c]] -= c;
	if(cnt[c] == mx){sum -= c;}
	cnt[c] += val;
	if(cnt[c] == mx){sum += c;}
	cc[cnt[c]] += c;
	ss.ins(mk(cnt[c], c));
	if(ss.begin()->X > mx || sum == 0ll){
		mx = ss.begin()->X;
		sum = cc[mx];
	}
	//mod(col[v], val);
	I(u, gr[v]){
		if(u == p || big[u])
			cont;
		add(u, v, val);
	}
}

void dfs(int v, int p, int k){
//	printf("In %d\n", v); fflush(stdout);
	int ms = -1, bc = -1;
	I(u, gr[v]){
		if(u == p){cont;}
		if(sz[u] > ms){ms = sz[u]; bc = u;}
	}
	I(u, gr[v]){
		if(u != p && u != bc)
			dfs(u, v, 0);
	}
	if(bc != -1)
		dfs(bc, v, 1), big[bc] = true;
	add(v, p, 1);
	ans[v] = sum;
	if(bc != -1)
		big[bc] = false;
	if(k == 0)
		add(v, p, -1);
//	printf("Leaving %d\n", v); fflush(stdout);
}

void calcsz(int v, int p){
	sz[v] = 1;
	I(u, gr[v]){
		if(u != p){calcsz(u, v); sz[v] += sz[u];}
	}
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
	scanf("%d", &n);
	col.rs(n); cnt.rs(n + 1); sz.rs(n); gr.rs(n); ans.rs(n);
	big.rs(n); big.asg(n, false);
	cnt.asg(n + 1, 0);
	cc.rs(3 * n); cc.asg(3 * n, 0ll);
	F(i, 0, n)
		scanf("%d", &col[i]);
	F(i, 0, n - 1){
		int v, u;
		scanf("%d%d", &v, &u); v--; u--;
		gr[v].pb(u); gr[u].pb(v);
	}
	calcsz(0, -1);
	dfs(0, -1, 0);
	F(i, 0, n)
		printf("%lld ", ans[i]);
	ret 0;
}