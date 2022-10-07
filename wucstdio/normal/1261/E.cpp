#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[1005],sa[1005],res[1005][1005];
bool cmp(int x,int y)
{
	return a[x]>a[y];
}
int main()
{
	int num=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sa[i]=i;
		if(a[i]==n)num++;
	}
	num=(num<=1);
	sort(sa+1,sa+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		res[n+2-i-num][sa[i]]=0;
		for(int j=1;j<=a[sa[i]];j++)
		{
			res[(n+2-i-num-j+n+n)%(n+1-num)+1][sa[i]]=1;
		}
	}
	printf("%d\n",n+1-num);
	for(int i=1;i<=n+1-num;i++)
	{
		for(int j=1;j<=n;j++)
		  printf("%d",res[i][j]);
		printf("\n");
	}
	return 0;
}