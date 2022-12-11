#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n;
int a[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int ans=1,val=100000000;
	for(int k=1;k<=100;++k)
	{
		int t=0;
		for(int i=1;i<=n;++i)
		{
			if(a[i]>k)t+=a[i]-(k+1);
			if(a[i]<k)t+=(k-1)-a[i];
		}
		if(t<val)val=t,ans=k;
	}
	printf("%d %d\n",ans,val);
	return 0;
}