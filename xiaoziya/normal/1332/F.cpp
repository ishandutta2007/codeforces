#include<stdio.h>
#include<vector>
using namespace std;
const int maxn=300005,mod=998244353;
int n;
int f[maxn][2],g[maxn];
vector<int>v[maxn];
void dfs(int x,int last){
	f[x][0]=f[x][1]=g[x]=1;
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if(y==last)
			continue;
		dfs(y,x);
		f[x][0]=1ll*(2ll*f[y][0]+2ll*f[y][1]+3ll*g[y])%mod*f[x][0]%mod;
		f[x][1]=1ll*(2ll*f[y][0]+f[y][1]+2ll*g[y])%mod*f[x][1]%mod;
		g[x]=1ll*g[x]*(0ll+f[y][0]+f[y][1]+g[y])%mod;
	}
	f[x][0]=(f[x][0]-g[x]+mod)%mod,f[x][1]=(f[x][1]-g[x]+mod)%mod;
//	printf("x=%d %d %d %d\n",x,f[x][0],f[x][1],g[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)
		scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	dfs(1,0);
	printf("%d\n",(0ll+f[1][0]+f[1][1]+g[1]-1+mod)%mod);
	return 0;
}