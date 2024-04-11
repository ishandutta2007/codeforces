#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,ans;
char s[3005][3005];
int flag[3005][3005],sum[3005][3005];
void check(int x,int y)
{
	int len=0,xx=x;
	while(s[xx][y]==s[x][y])len++,xx++;
	if(x+len*3-1>n)return;
	int now=0,nowx=xx;
	while(s[xx][y]==s[nowx][y])now++,xx++;
	if(now!=len)return;
	now=0,nowx=xx;
	while(s[xx][y]==s[nowx][y])now++,xx++;
	if(now<len)return;
	ans++;
	xx=x+len*3-1;
	for(int i=y+1;i<=m;i++)
	{
		if(sum[xx][i]-sum[x-1][i]-sum[xx][y]+sum[x-1][y]==(i-y)*(xx-x+1))ans++;
		else break;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
	  for(int j=2;j<=m;j++)
	    if(s[i][j]==s[i][j-1])
	      flag[i][j]=1;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+flag[i][j];
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    check(i,j);
	printf("%d\n",ans);
	return 0;
}