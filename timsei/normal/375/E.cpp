#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define N 502
using namespace std;
const int inf=10000;
int next[N*2],e[N*2],head[N],len,x,y,S,n,D,a[N],size[N],i,j,k,g[N],h[N],F[N][N];
short f[N][N][N];
long long dis[N][N];
void dfs(int x,int ff){
	int i,j,k,y,l;
	for(i=head[x];i;i=next[i])
	if(e[i]!=ff)
	dfs(e[i],x);
	for(i=1;i<=S;++i)F[x][i]=inf;
	for(j=1;j<=n;++j)
	if(dis[j][x]<=D)
	{
		g[1]=0;
		for(k=2;k<=S;++k)g[k]=inf;
		size[x]=1;
		for(i=head[x];i;i=next[i])
		if(e[i]!=ff)
		{
			y=e[i];
			for(k=1;k<=S;++k)h[k]=inf;
			for(k=1;k<=size[x];++k)
				for(l = 1 ; l <= size[ y ] && l + k -1 <= S   ;++ l)
				{
					h[k+l]=min(h[k+l],g[k]+F[y][l])    ;
//					if(dis[j][y]>D) continue;
					int z=dis[j][y]>D?inf:f[y][j][l]   ;
					h[k+l-1]=min(h[k+l-1],g[k]+z) ;
				}
			for(k=1;k<=S;++k)
			g[k]=h[k];
			size[x]+=size[y];
		}
		for(k=1;k<=S;++k)
		{
			f[x][j][k]=g[k];
			F[x][k]=min(F[x][k],g[k]+a[j]);
		}
	}
}
int main(){
	scanf("%d%d",&n,&D);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
		S+=a[i];
		a[i]=1-a[i];
	}
	memset(dis,3,sizeof(dis));
	for(i=1;i<n;++i){
		scanf("%d%d%d",&x,&y,&k);
		dis[x][y]=dis[y][x]=k;
		next[++len]=head[x]; head[x]=len; e[len]=y;
		next[++len]=head[y]; head[y]=len; e[len]=x;
	}
	for(i=1;i<=n;++i)dis[i][i]=0;
	for(k=1;k<=n;++k)
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	dfs(1,0);
	if(F[1][S]>1000)
	printf("-1\n");
	else 
	printf("%d\n",F[1][S]);
}