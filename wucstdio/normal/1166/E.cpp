#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[55][10005],num[55];
bool check(int x,int y)
{
	int now=1;
	for(int i=1;i<=num[x];i++)
	{
		while(now<=num[y]&&a[y][now]<a[x][i])now++;
		if(a[y][now]==a[x][i])return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&num[i]);
		for(int j=1;j<=num[i];j++)
		  scanf("%d",&a[i][j]);
		sort(a[i]+1,a[i]+num[i]+1);
	}
	bool flag=1;
	for(int i=1;i<=m;i++)
	  for(int j=i+1;j<=m;j++)
	    if(check(i,j))flag=0;
	if(flag)printf("possible\n");
	else printf("impossible\n");
	return 0;
}