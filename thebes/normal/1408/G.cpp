#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 1505, mod = 998244353;
int N, i, j, x, y, a[MN][MN], dp[MN][MN], ds[MN], sz[MN], ecnt[MN], cc[MN], nxt, tmp[MN], rev[MN];
int fnd(int x){return ds[x]=ds[x]==x?x:fnd(ds[x]);}
struct edge{int x, y, w, id;}; map<int,int> mp;
vector<edge> vec; vi rep[MN], adj[MN];

void dfs(int n){
	dp[n][0] = 1; sz[n] = 0;
	for(auto v : adj[n]){
		dfs(v);
		for(i=0;i<=sz[n]+sz[v];i++)
			tmp[i] = 0;
		for(i=0;i<=sz[n];i++){
			for(j=0;j<=sz[v];j++){
				tmp[i+j] = (tmp[i+j]+1LL*dp[n][i]*dp[v][j])%mod;
			}
		}
		sz[n] += sz[v];
		for(i=0;i<=sz[n];i++)
			dp[n][i] = tmp[i];
	}
	dp[n][cc[n]]=(dp[n][cc[n]]+1)%mod;
	sz[n] = max(sz[n], cc[n]);
}

int main(){
	scanf("%d",&N);
	if(N==1){
		printf("1\n");
		return 0;
	}
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			scanf("%d",&a[i][j]);
			if(i<j) vec.push_back({i,j,a[i][j],(i-1)*N+j});
		}
	}
	sort(vec.begin(),vec.end(),[](edge i,edge j){return i.w<j.w;});
	for(i=1;i<=N;i++){
		ds[i] = i;
		sz[i] = 1;
	}
	for(auto v : vec){
		x = v.x, y = v.y;
		if(fnd(x)^fnd(y)){
			x = fnd(x), y = fnd(y);
			ds[x] = y;
			for(auto v : rep[x])
				rep[y].pb(v);
			rep[x].clear();
			sz[y] += sz[x];
			ecnt[y] += ecnt[x]+1;
		}
		else ecnt[fnd(x)]++;
		x=fnd(x);
		if(sz[x]*(sz[x]-1)/2==ecnt[x]){
			mp[v.id] = ++nxt;
			rev[nxt] = v.id;
			for(auto v : rep[x])
				adj[nxt].pb(v);
			cc[nxt] = sz[x]-1;
			rep[x].clear();
			rep[x].pb(nxt);
		}
	}
	dfs(nxt);
	for(i=1;i<=N;i++){
		printf("%d ",dp[nxt][N-i]);
	}
	printf("\n");
	return 0;
}