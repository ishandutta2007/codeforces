#include <cstdio>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 105
int map[N][N],n,m,a[N],b[N],num1,num2;bool c[N],d[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	for(int i=0;i<=29;i++)
	{
		num1=num2=0;
		for(int j=1;j<=n;j++)if((1<<i)&a[j])c[j]=1,num1++;
		for(int j=1;j<=m;j++)if((1<<i)&b[j])d[j]=1,num2++;
		if(abs(num1-num2)&1){puts("NO");return 0;}
		for(int j=1;j<=n;j++)
		{
			if(c[j])
			{
				for(int k=1;k<=m;k++)
				{
					if(d[k]){map[j][k]+=(1<<i),c[j]=0,d[k]=0;break;}
				}
			}
			if(c[j])map[j][1]+=(1<<i),c[j]=0;
		}
		for(int j=1;j<=m;j++)if(d[j])map[1][j]+=(1<<i),d[j]=0;
	}
	puts("YES");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)printf("%d ",map[i][j]);
			puts("");
	}
}