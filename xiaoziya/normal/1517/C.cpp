#include<stdio.h>
#include<queue>
using namespace std;
const int maxn=505;
int n,now;
int p[maxn],ans[maxn][maxn];
void dfs(int x,int y,int c){
	if(now==0)
		return ;
	now--,ans[x][y]=c;
	if(now>0&&y>1&&ans[x][y-1]==0)
		dfs(x,y-1,c);
	if(now>0&&x<n&&ans[x+1][y]==0)
		dfs(x+1,y,c);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
		now=p[i],dfs(i,i,p[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			printf("%d%c",ans[i][j],j==i? '\n':' ');
	return 0;
}