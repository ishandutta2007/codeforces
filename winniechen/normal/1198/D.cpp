#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int f[N][N][N][N],n,m;char s[N][N];
int dfs(int x,int y,int z,int w)
{
	if(f[x][y][z][w]!=-1)return f[x][y][z][w];if(x==z&&y==w)return f[x][y][z][w]=(s[x][y]=='#');
	int ret=max(z-x+1,w-y+1);
	for(int i=x;i<z;i++)ret=min(dfs(x,y,i,w)+dfs(i+1,y,z,w),ret);
	for(int i=y;i<w;i++)ret=min(dfs(x,y,z,i)+dfs(x,i+1,z,w),ret);
	return f[x][y][z][w]=ret;
}
int main()
{
	scanf("%d",&n);memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	printf("%d\n",dfs(1,1,n,n));
}