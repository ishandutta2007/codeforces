#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
int n,m;
bool p[Maxn];
int ans[Maxn];
int a[Maxn],r[Maxn];
int calc(int x,int y)
{
	return (x-1)*m+y;
}
bool judge(int a,int b)
{
	int xa=(a-1)/m+1,ya=(a-1)%m+1;
	int xb=(b-1)/m+1,yb=(b-1)%m+1;
	return (abs(xa-xb)+abs(ya-yb)==1);
}
int check()
{
	for (int i=1;i<n;i++)
		for (int j=1;j<=m;j++)
			if (judge(r[calc(i,j)],r[calc(i+1,j)])) return calc(i,j);
	for (int j=1;j<m;j++)
		for (int i=1;i<=n;i++)
			if (judge(r[calc(i,j)],r[calc(i,j+1)])) return calc(i,j);
	return -1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++)
		r[i]=i;
	random_shuffle(r+1,r+n*m+1);
	while (clock()<=1.9*CLOCKS_PER_SEC)
	{
		int now=check();
		if (now==-1)
		{
			printf("YES\n");
			for (int i=1;i<=n*m;i++)
			{
				printf("%d ",r[i]);
				if (i%m==0) printf("\n");
			}
			return 0;
		}
		int x=rand()%n+1,y=rand()%m+1;
		swap(r[calc(x,y)],r[now]);
	}
	printf("NO\n");
	return 0;
}