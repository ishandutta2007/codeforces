// author: xay5421
// created: Mon Oct  4 15:05:16 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=505;
int n,m,a[N][N],pre[N];
char s[N][N];
int e[N][N];
bool vis[N];
int dfs(int k1){
	rep(i,1,m)if(!vis[i]&&e[k1][i]){
		vis[i]=1;
		if(!pre[i]||dfs(pre[i])){
			pre[i]=k1;
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,1,n)rep(j,1,m)a[i][j]=s[i][j]=='B';
	rep(i,1,n)rep(j,1,m)a[i][j]=a[i][j]^a[i+1][j]^a[i][j+1]^a[i+1][j+1];
	int tot=0;
	rep(i,1,n)rep(j,1,m)tot+=a[i][j];
	rep(i,1,n-1)rep(j,1,m-1)if(a[i][m]&&a[n][j]&&a[i][j]){
		e[i][j]=1;
	}
	int res=0;
	rep(i,1,n){
		memset(vis,0,sizeof(vis));
		res+=dfs(i);
	}
	int ans=tot-res/2*2;
	if((res&1)&&a[n][m])ans-=2;
	printf("%d\n",ans);
	return 0;
}