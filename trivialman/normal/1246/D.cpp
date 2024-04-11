#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define CL(a,x) memset(a, x, sizeof(a))
typedef long long LL;
const int P = 998244353;
const int N = 1e5+5;
const double PI = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> g[N];
int n, T, x, dep[N], lf1[N], op[N], nxt[N];

void dfs(int x,int d){
	dep[x] = lf1[x] = d;
	int mi = 0;
	for(int i=0;i<g[x].size();++i){
		int u = g[x][i];
		dfs(u,d+1);
		if(lf1[u]>lf1[x]) lf1[x] = lf1[u], mi = i;
	}
	if(mi) swap(g[x][mi], g[x][0]);
}

void dfs2(int x){
	int sz = g[x].size();
	rrep(i,sz-1,0){
		int u = g[x][i];
		dfs2(u);
		if(i<sz-1){
			int lf = g[x][i+1];
			for(; g[lf].size(); lf = g[lf][0]) op[++T] = u;
			op[++T] = nxt[lf] = u;
		}
	}
	if(sz) nxt[x] = g[x][sz-1];
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	rep(i,1,n-1) scanf("%d",&x),g[x].PB(i);
	dfs(0,1);
	dfs2(0);
	x = 0;
	rep(i,1,n) printf("%d ",x), x = nxt[x];
	printf("\n%d\n",T);
	rep(i,1,T) printf("%d ",op[i]);
	return 0;
}