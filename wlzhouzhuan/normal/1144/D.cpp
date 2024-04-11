#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
int n,a[200010],cnt[200010],mx=-1,mxd;//cnt[]mxd
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for(int i=0;i<=200000;i++)//0200000
		if(cnt[i]>mx)
		{
			mx=cnt[i];
			mxd=i;
		}
	printf("%d\n",n-mx);
	for(int i=2;i<=n;i++)//
	{
		if(a[i-1]!=mxd)continue;
		if(a[i]>a[i-1])printf("2 %d %d\n",i,i-1);//2
		if(a[i]<a[i-1])printf("1 %d %d\n",i,i-1);//1
		a[i]=a[i-1];
	}
	for(int i=n-1;i>=1;i--)//
	{
		if(a[i+1]!=mxd)continue;
		if(a[i]>a[i+1])printf("2 %d %d\n",i,i+1);
		if(a[i]<a[i+1])printf("1 %d %d\n",i,i+1);
		a[i]=a[i+1];
	}
	return 0;
}