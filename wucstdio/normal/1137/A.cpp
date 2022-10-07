#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[2005][2005],tmp[2005],sa[2005],ans1[1005][1005],ans2[1005][1005],maxx1[1005],maxx2[1005];
bool cmp(int a,int b)
{
	return tmp[a]<tmp[b];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)tmp[j]=a[i][j],sa[j]=j;
		sort(sa+1,sa+m+1,cmp);
		int x=0;
		for(int j=1;j<=m;j++)
		{
			if(tmp[sa[j]]!=tmp[sa[j-1]])x++;
			ans1[i][sa[j]]=x;
		}
		maxx1[i]=x;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)tmp[j]=a[j][i],sa[j]=j;
		sort(sa+1,sa+n+1,cmp);
		int x=0;
		for(int j=1;j<=n;j++)
		{
			if(tmp[sa[j]]!=tmp[sa[j-1]])x++;
			ans2[sa[j]][i]=x;
		}
		maxx2[i]=x;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ans1[i][j]<ans2[i][j])printf("%d ",max(maxx1[i]+(ans2[i][j]-ans1[i][j]),maxx2[j]));
			else printf("%d ",max(maxx2[j]+(ans1[i][j]-ans2[i][j]),maxx1[i]));
		}
		printf("\n");
	}
	return 0;
}