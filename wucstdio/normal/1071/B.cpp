#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,k,top,dis[2005][2005];
bool flag[2005][2005];
char a[2005][2005],ans[5005];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	  scanf("%s",a[i]);
	if(k>=2*n-1)
	{
		for(int i=1;i<=2*n-1;i++)
		  putchar('a');
		printf("\n");
		return 0;
	}
	for(int i=0;i<n;i++)
	  for(int j=0;j<n;j++)
	    dis[i][j]=100000;
	dis[0][0]=1;
	if(a[0][0]=='a')dis[0][0]--;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		if(dis[i][j]<=k)a[i][j]='a';
		dis[i+1][j]=min(dis[i+1][j],dis[i][j]+(a[i+1][j]=='a'?0:1));
		dis[i][j+1]=min(dis[i][j+1],dis[i][j]+(a[i][j+1]=='a'?0:1));
	}
	for(int i=0;i<2*n-1;i++)
	{
		char minn='z';
		for(int x=max(0,i-n+1);x<min(n,i+1);x++)
		{
			int y=i-x;
			if((x==0&&y==0)||(x>0&&flag[x-1][y])||(y>0&&flag[x][y-1]))
			  minn=min(minn,a[x][y]);
		}
		for(int x=max(0,i-n+1);x<min(n,i+1);x++)
		{
			int y=i-x;
			if((x==0&&y==0||x>0&&flag[x-1][y]||y>0&&flag[x][y-1])&&a[x][y]==minn)
			  flag[x][y]=1;
		}
		ans[++top]=minn;
	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		  printf("%d",flag[i][j]);
//		printf("\n");
//	}
	for(int i=1;i<=top;i++)
	  putchar(ans[i]);
	printf("\n");
	return 0;
}