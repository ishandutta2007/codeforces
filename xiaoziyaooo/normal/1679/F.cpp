#include<stdio.h>
const int maxn=50005,maxs=1<<10,mod=998244353,maxd=10;
int n,m,ans;
int f[maxn][maxs],s[maxd],t[maxd],g[maxd][maxd];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++)
		scanf("%d%d",&x,&y),g[x][y]=g[y][x]=1,s[y]|=(1<<x),t[x]|=(1<<y),t[y]|=(1<<x);
	int S=(1<<10)-1;
	f[1][S]=1;
	for(int i=2;i<=n+1;i++){
		for(int j=0;j<=S;j++)
			if(f[i-1][j])
				for(int k=0;k<10;k++)
					if((j>>k)&1){
						int nxt=(S^s[k])&(S^((S^j)&t[k]));
						f[i][nxt]=(f[i][nxt]+f[i-1][j])%mod;
					}
	}
	for(int i=0;i<=S;i++)
		ans=(ans+f[n+1][i])%mod;
	printf("%d\n",ans);
	return 0;
}