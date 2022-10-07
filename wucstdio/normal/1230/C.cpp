#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int from;
	int to;
}e[1005];
int n,m;
bool flag[15][15];
int calc(int x,int y)
{
	int ans=0;
	memset(flag,0,sizeof(flag));
	for(int i=1;i<=m;i++)
	{
		int u=e[i].from,v=e[i].to;
		if(u==y)u=x;
		if(v==y)v=x;
		if(u>v)swap(u,v);
		if(flag[u][v])ans++;
		flag[u][v]=1;
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&e[i].from,&e[i].to);
	if(n<=6)
	{
		printf("%d\n",m);
		return 0;
	}
	int num=m;
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++)
		num=min(num,calc(i,j));
	printf("%d\n",m-num);
	return 0;
}