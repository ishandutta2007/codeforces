#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[200005],sa[200005],d1[200005],d2[200005];
bool f1[200005],f2[200005];
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	scanf("%d",&n);
	if(n<=3)
	{
		printf("1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sa[i]=i;
	}
	sort(sa+1,sa+n+1,cmp);
	f1[0]=f1[1]=f1[2]=1;
	d1[2]=a[sa[2]]-a[sa[1]];
	for(int i=3;i<=n;i++)
	{
		f1[i]=f1[i-1];
		if(a[sa[i]]+a[sa[i-2]]!=2*a[sa[i-1]])f1[i]=0;
		d1[i]=a[sa[i]]-a[sa[i-1]];
	}
	f2[n+1]=f2[n]=f2[n-1]=1;
	d2[n-1]=a[sa[n]]-a[sa[n-1]];
	for(int i=n-2;i>=1;i--)
	{
		f2[i]=f2[i+1];
		if(a[sa[i]]+a[sa[i+2]]!=2*a[sa[i+1]])f2[i]=0;
		d2[i]=a[sa[i+1]]-a[sa[i]];
	}
	for(int i=3;i<=n-2;i++)
	{
		if(f1[i-1]&&f2[i+1]&&d1[i-1]==d2[i+1]&&a[sa[i+1]]-a[sa[i-1]]==d1[i-1])
		{
			printf("%d\n",sa[i]);
			return 0;
		}
	}
	if(f2[3]&&a[sa[3]]-a[sa[1]]==d2[3])
	{
		printf("%d\n",sa[2]);
		return 0;
	}
	if(f1[n-2]&&a[sa[n]]-a[sa[n-2]]==d1[n-2])
	{
		printf("%d\n",sa[n-1]);
		return 0;
	}
	if(f2[2])
	{
		printf("%d\n",sa[1]);
		return 0;
	}
	if(f1[n-1])
	{
		printf("%d\n",sa[n]);
		return 0;
	}
	printf("-1\n");
	return 0;
}