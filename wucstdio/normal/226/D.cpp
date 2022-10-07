#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[105][105],sum1[105],sum2[105],p1[105],p2[105],sum;
bool flag1[105],flag2[105];
bool cmp1(int i,int j)
{
	return sum1[i]<sum1[j];
}
bool cmp2(int i,int j)
{
	return sum2[i]<sum2[j];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		scanf("%d",&a[i][j]);
		sum1[i]+=a[i][j];
		sum2[j]+=a[i][j];
	}
	for(int i=1;i<=n;i++)p1[i]=i;
	for(int i=1;i<=m;i++)p2[i]=i;
	sort(p1+1,p1+n+1,cmp1);
	sort(p2+1,p2+m+1,cmp2);
	while(sum1[p1[1]]<0||sum2[p2[1]]<0)
	{
		if(sum1[p1[1]]<sum2[p2[1]])
		{
			flag1[p1[1]]^=1;
			sum1[p1[1]]=-sum1[p1[1]];
			for(int i=1;i<=m;i++)
			{
				a[p1[1]][i]=-a[p1[1]][i];
				sum2[i]+=2*a[p1[1]][i];
			}
		}
		else
		{
			flag2[p2[1]]^=1;
			sum2[p2[1]]=-sum2[p2[1]];
			for(int i=1;i<=n;i++)
			{
				a[i][p2[1]]=-a[i][p2[1]];
				sum1[i]+=2*a[i][p2[1]];
			}
		}
		for(int i=1;i<=n;i++)p1[i]=i;
		for(int i=1;i<=m;i++)p2[i]=i;
		sort(p1+1,p1+n+1,cmp1);
		sort(p2+1,p2+m+1,cmp2);
	}
	int num=0;
	for(int i=1;i<=n;i++)if(flag1[i])num++;
	printf("%d ",num);
	for(int i=1;i<=n;i++)if(flag1[i])printf("%d ",i);
	printf("\n");
	num=0;
	for(int i=1;i<=m;i++)if(flag2[i])num++;
	printf("%d ",num);
	for(int i=1;i<=m;i++)if(flag2[i])printf("%d ",i);
	printf("\n");
	return 0;
}