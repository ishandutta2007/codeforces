#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6005;
ll dp[N][N];
int fa[N],tot,ne[N],fi[N],zz[N],x,y,n,size[N];
void jb(int x,int y){
	ne[++tot]=fi[x];
	fi[x]=tot;
	zz[tot]=y;
}
void dfs(int x,int y){
	size[x]=1;fa[x]=y;
	for (int i=fi[x];i;i=ne[i])
		if (zz[i]!=y)dfs(zz[i],x),size[x]+=size[zz[i]];
}
inline getsize(int x){
	if (fa[zz[x]]==zz[x^1])return size[zz[x]];
	return n-size[zz[x^1]];
}
ll dfs2(int x,int y){
	if (dp[x][y])return dp[x][y];
	for (int i=fi[zz[x]];i;i=ne[i])
		if (zz[i]!=zz[x^1])dp[x][y]=max(dp[x][y],dfs2(i,y));
	for (int i=fi[zz[y]];i;i=ne[i])
		if (zz[i]!=zz[y^1])dp[x][y]=max(dp[x][y],dfs2(x,i));
	dp[x][y]+=getsize(x)*getsize(y);
	return dp[x][y];
}
int main(){
	scanf("%d",&n);
	tot=1;
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		jb(x,y);jb(y,x);
	}
	dfs(1,0);
	ll ans=0;
	for (int i=2;i<=tot;i+=2)ans=max(ans,dfs2(i,i^1));
	printf("%lld\n",ans);
	return 0;
}