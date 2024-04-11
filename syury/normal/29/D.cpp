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
typedef pair<int, int> pii;

int n;
vector<int> gr[333];
int tin[333];
int tout[333];
int gt = 0;
int ord[333];
int k;
int ans[666];
int pr[333];

bool ispr(int v, int u){
	ret tin[v] <= tin[u] && tout[v] >= tout[u];
}

void dfs(int v, int p = -1){
	pr[v] = p;
	tin[v] = gt++;
	I(u, gr[v])if(u != p)dfs(u, v);
	tout[v] = gt++;
}

map<pii, int> went;

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d", &n);
	F(i, 0, n - 1){
		int v, u;
		scanf("%d%d", &v, &u);
		v--; u--;
		gr[v].pb(u); gr[u].pb(v);
	}
	int k = 0;
	while(true){
		int tmp;
		scanf("%d", &tmp);
		if(feof(stdin))brk;
		ord[k++] = tmp - 1;
	}
	ord[k++] = 0;
	dfs(0);
	int ptr = 0;
	ans[ptr++] = 1;
	int v = 0;
	F(i, 0, k){
		int u = ord[i];
		while(!ispr(v, u)){
			int pv = pr[v];
			//printf("%d -> %d\n", v, pv);
			pii e = mk(v, pv);
			if(v > pv)swap(e.X, e.Y);
			if(went[e] == 2){printf("-1"); ret 0;}
			went[e]++; ans[ptr++] = pv + 1; v = pv;
		}
		while(v != u){
			int s = -1;
			I(w, gr[v])if(ispr(w, u) && w != pr[v]){s = w; brk;}
			//printf("%d -> %d\n", v, s);
			if(s == -1){ret 228;}
			pii e = mk(v, s);
			if(v > s)swap(e.X, e.Y);
			if(went[e] == 2){printf("-1"); ret 0;}
			went[e]++; ans[ptr++] = s + 1; v = s;
		}
	}
	F(i, 0, ptr)printf("%d ", ans[i]);
	ret 0;
}