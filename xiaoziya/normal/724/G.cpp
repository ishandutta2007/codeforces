#include<stdio.h>
#include<vector>
using namespace std;
const int maxn=200005,mod=1000000007,maxk=105;
int n,m,flg,tot,ans,ptot;
int xx[maxn],yy[maxn],vis[maxn],o[60][2],f[60],mul2[maxn];
long long zz[maxn],p[maxk],dis[maxn];
vector<int>v[maxn];
void insert(long long x){
	for(int i=59;i>=0;i--)
		if((x>>i)&1){
			if(p[i]==0){
				ptot++,p[i]=x;
				return ;
			}
			x^=p[i];
		}
}
void dfs(int x,long long d){
	vis[x]=1,tot++,dis[x]=d;
	for(int b=0;b<60;b++)
		o[b][(d>>b)&1]++;
	for(int i=0;i<v[x].size();i++){
		int k=v[x][i],y=xx[k]+yy[k]-x;
		long long z=zz[k];
		if(vis[y]==0)
			dfs(y,d^z);
		else{
			long long val=dis[x]^dis[y]^z;
			insert(val);
			for(int b=0;b<60;b++)
				f[b]|=(val>>b)&1;
		}
	}
}
int main(){
	mul2[0]=1;
	for(int i=1;i<maxn;i++)
		mul2[i]=(mul2[i-1]+mul2[i-1])%mod;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%lld",&xx[i],&yy[i],&zz[i]),v[xx[i]].emplace_back(i),v[yy[i]].emplace_back(i);
	for(int i=1;i<=n;i++)
		if(vis[i]==0){
			tot=0,dfs(i,0);
			for(int b=0;b<60;b++){
				if(f[b]==0)
					ans=(ans+1ll*o[b][0]*o[b][1]%mod*mul2[b]%mod*mul2[ptot])%mod;
				else ans=(ans+1ll*tot*(tot-1)/2%mod*mul2[b]%mod*mul2[ptot-1])%mod;
				p[b]=o[b][0]=o[b][1]=f[b]=0;
			}
			ptot=0;
		}
	printf("%d\n",ans);
	return 0;
}