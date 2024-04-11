#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000005;
int ne[N],tot,fi[N],zz[N],sl[N],a[N],x,y,z,n,k,dp[N][2],T;
inline int cmp(int x,int y){
	return x>y;
}
inline void jb(int x,int y,int z){
	ne[++tot]=fi[x];
	fi[x]=tot;
	zz[tot]=y;
	sl[tot]=z;
}
inline void dfs(int x,int y){
	for (int i=fi[x];i;i=ne[i])
		if (zz[i]!=y)dfs(zz[i],x);
	int cnt=0;	
	for (int i=fi[x];i;i=ne[i])
		if (zz[i]!=y)dp[x][0]+=dp[zz[i]][0],dp[x][1]+=dp[zz[i]][0],a[++cnt]=dp[zz[i]][1]-dp[zz[i]][0]+sl[i];
	sort(a+1,a+cnt+1,cmp);
	for (int i=1;i<k&&i<=cnt;i++)dp[x][1]+=max(0ll,a[i]),dp[x][0]+=max(0ll,a[i]);
	if (k<=cnt)dp[x][0]+=max(0ll,a[k]);
}
signed main(){
	scanf("%lld",&T);
	while (T--){
		scanf("%lld%lld",&n,&k);
		for (int i=1;i<n;i++){
			scanf("%lld%lld%lld",&x,&y,&z);
			jb(x,y,z);jb(y,x,z);
		}
		dfs(1,0);
		printf("%lld\n",dp[1][0]);
		tot=0;
		for (int i=1;i<=n;i++)dp[i][0]=dp[i][1]=fi[i]=0;
	}
}