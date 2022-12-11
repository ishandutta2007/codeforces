#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		long long k;
		scanf("%d%lld",&n,&k);
		int Max=-1e9,Min=1e9;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			Max=max(Max,a[i]);
			Min=min(Min,a[i]);
		}
		for(int i=1;i<=n;i++) a[i]=Max-a[i];
		if(k%2==0)
		{
			for(int i=1;i<=n;i++) a[i]=Max-Min-a[i];
		}
		for(int i=1;i<=n;i++) printf("%d%c",a[i],i<n?' ':'\n');
	}
	return 0;
}