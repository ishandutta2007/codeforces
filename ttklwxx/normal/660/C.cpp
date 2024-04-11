#include<iostream>
#include<cstdio>
using namespace std;
int a[300001];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int l=1,ans=0,maxn=0,maxr=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0)ans++;
		while(ans>k)
		{
			if(a[l]==0)ans--;
			l++;
		}
		if(i-l+1>maxn)
		{
			maxn=i-l+1;
			maxr=i;
		}
	}
	printf("%d\n",maxn);
	for(int i=1;i<=n;i++)
	{
		if(i<=maxr&&i>=maxr-maxn+1)printf("1 ");
		else printf("%d ",a[i]);
	}
	return 0;
}