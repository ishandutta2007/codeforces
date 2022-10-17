#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
const int maxn=205;
int n,m,flg,ans,pos;
int vis[maxn],d[maxn][maxn];
vector<int>v[maxn];
void dfs(int x,int c){
	if(vis[x]==0)
		vis[x]=c;
	else{
		if(vis[x]!=c)
			flg=1;
		return ;
	}
	for(int i=0;i<v[x].size();i++)
		dfs(v[x][i],3-c);
}
int main(){
	scanf("%d%d",&n,&m),memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++)
		d[i][i]=0;
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		v[x].push_back(y),v[y].push_back(x);
		if(z==0)
			d[x][y]=d[y][x]=1;
		else d[x][y]=1,d[y][x]=-1;
	}
	for(int i=1;i<=n;i++)
		if(vis[i]==0)
			dfs(i,1);
	if(flg){
		puts("NO");
		return 0;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	ans=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		if(d[i][i]<0){
			puts("NO");
			return 0;
		}
		int res=0;
		for(int j=1;j<=n;j++)
			res=max(res,d[i][j]);
		if(res>ans)
			ans=res,pos=i;
	}
	puts("YES");
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		printf("%d%c",d[pos][i],i==n? '\n':' ');
	return 0;
}