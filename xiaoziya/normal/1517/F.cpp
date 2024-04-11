#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
const int maxn=305,mod=998244353,inv2=(mod+1)/2;
int n,ban,ans,mul;
int f[maxn][maxn],g[maxn][maxn],sz[maxn],tf[maxn],tg[maxn];
vector<int>v[maxn];
void dfs(int x,int last){
	sz[x]=1;
	f[x][0]=g[x][0]=1;
	for(int t=0;t<v[x].size();t++){
		int y=v[x][t];
		if(y==last)
			continue;
		dfs(y,x);
		for(int i=0;i<=sz[x];i++)
			for(int j=0;j<=sz[y];j++){
				int fnxt=min(i,j+1),gnxt=max(i,j+1);
				tf[fnxt]=(tf[fnxt]+1ll*f[x][i]*f[y][j])%mod;
				tg[gnxt]=(tg[gnxt]+1ll*g[x][i]*g[y][j])%mod;
				if(i+j+1>ban){
					tg[j+1]=(tg[j+1]+1ll*f[x][i]*g[y][j])%mod;
					tg[i]=(tg[i]+1ll*g[x][i]*f[y][j])%mod;
				}
				else{
					tf[i]=(tf[i]+1ll*f[x][i]*g[y][j])%mod;
					tf[j+1]=(tf[j+1]+1ll*g[x][i]*f[y][j])%mod;
				}
			}
		sz[x]+=sz[y];
		for(int i=0;i<=sz[x]+1;i++)
			f[x][i]=tf[i],g[x][i]=tg[i],tf[i]=tg[i]=0;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)
		scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	mul=1;
	for(int i=1;i<=n;i++)
		mul=1ll*mul*inv2%mod;
	for(ban=1;ban<n;ban++){
		dfs(1,0);
		int res=0;
		for(int i=0;i<=n;i++)
			res=(0ll+res+g[1][i])%mod;
		res=1ll*res*mul%mod;
		ans=(ans+res)%mod;
		memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
	}
	printf("%d\n",ans);
	return 0;
}