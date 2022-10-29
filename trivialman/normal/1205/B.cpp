#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
const LL P = 998244353;
const int N = 1e5+10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,mp[N],g1[150][150],d[150][150];
vector<int> g[65];

int main(){
	//freopen("test.in","r",stdin);
	
	scanf("%d",&n);
	rep(i,1,n){
		LL x;
		scanf("%lld",&x);
		rep(j,0,61)if(x>>j&1ll){
			g[j].PB(i);
			if(g[j].size()>=3){
				printf("3\n");
				return 0;
			}
		}
	}
	
	int m = 0; 
	rep(i,0,61)if(g[i].size()==2){
		int x = g[i][0], y = g[i][1];
		if(!mp[x])mp[x]=++m;
		if(!mp[y])mp[y]=++m;
		x = mp[x], y = mp[y];
		g1[x][y] = g1[y][x] = 1;
	}
	rep(i,1,m)rep(j,1,m)if(i!=j && !g1[i][j]) g1[i][j] = 1e7;
	memcpy(d,g1,sizeof d);
	
	int ans = 1e7;
	rep(k,1,m){
		rep(i,1,k-1)rep(j,i+1,k-1)
			if(i!=k && j!=k && i!=j) ans = min(ans, d[i][j] + g1[j][k] + g1[k][i]);
		rep(i,1,m)rep(j,i+1,m)
			d[i][j] = d[j][i] = min(d[i][j], d[i][k] + d[k][j]); 
	}
	printf("%d\n", ans==1e7 ? -1 : ans);
	return 0;
}