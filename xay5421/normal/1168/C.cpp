#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=300005;
int n,q,a[N],ans[N],lst[21],yy[N],f[N][21];std::vector<int>g[N];bool vis[21];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=q;++i){
		int x,y;scanf("%d%d",&x,&y);
		g[x].push_back(i),yy[i]=y;
	}
	for(int i=0;i<=20;++i)f[n+1][i]=n+1,lst[i]=n+1;
	for(int i=n;i>=1;--i){
		for(int j=0;j<=20;++j)if(a[i]>>j&1)f[i][j]=lst[j],lst[j]=i,vis[j]=0;else f[i][j]=n+1,vis[j]=0;
		for(int j=0;j<=20;++j){
			int mn=-1;
			for(int k=0;k<=20;++k)if(!vis[k]&&(mn==-1||f[i][k]<f[i][mn]))mn=k;
			vis[mn]=1;
			for(int k=0;k<=20;++k)if(!vis[k])f[i][k]=min(f[i][k],f[f[i][mn]][k]);
		}
		for(int j=0;j<g[i].size();++j){
			int x=g[i][j],y=yy[x];
			for(int k=0;k<20;++k)if(a[y]>>k&1){
				ans[x]|=(f[i][k]<=y);
			}
		}
	}
	for(int i=1;i<=q;++i)if(ans[i])puts("Shi");else puts("Fou");
	return 0;
}