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
#define acpy(y, x) memcpy(y, x, sizeof(y))
#define y1 adjf
#define ws wejgnjn
#define left fhgfj
#define tm shfhf

const int MAXN = 1e5 + 5;

lint x[MAXN], y[MAXN];
int n, m;
vector<int> gr[MAXN];
int up[MAXN][20];
int tin[MAXN], tout[MAXN];
int gt = 0;

void dfs(int v, int p = -1){
	tin[v] = gt++;
	up[v][0] = (p == -1) ? v : p;
	F(i, 1, 20)up[v][i] = up[up[v][i - 1]][i - 1];
	I(u, gr[v])if(u != p)dfs(u, v);
	tout[v] = gt++;
}

bool ispr(int v, int u){
	ret (tin[v] <= tin[u]) && (tout[v] >= tout[u]);
}

int lca(int v, int u){
	if(ispr(v, u))ret v;
	if(ispr(u, v))ret u;
	Df(i, 19, -1){
		if(!ispr(up[v][i], u))v = up[v][i];
	}
	ret up[v][0];
}

bool le(int i, int j, int k){
	lint lp = (y[i] - y[j]) * 1ll * (x[i] - x[k]);
	lint rp = (y[i] - y[k]) * 1ll * (x[i] - x[j]);
	ret lp < rp;
}

int ids[MAXN];
int ptr = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	F(i, 0, n){
		scanf("%lld%lld", &x[i], &y[i]);
	}
	ids[ptr++] = n - 1;
	Df(i, n - 2, -1){
		while(ptr > 1 && le(i, ids[ptr - 1], ids[ptr - 2]))ptr--;
		gr[i].pb(ids[ptr - 1]); gr[ids[ptr - 1]].pb(i);
		//printf("At i = %d prv = %d\n", i, ids[ptr - 1]);
		ids[ptr++] = i;
	}
	dfs(n - 1);
	scanf("%d", &m);
	F(i, 0, m){
		int v, u;
		scanf("%d%d", &v, &u); v--; u--;
		printf("%d ", lca(v, u) + 1);
	}
	ret 0;
}