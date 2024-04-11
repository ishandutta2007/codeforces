#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
long long a[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%lld",a+i);
		for(int i=1;i<n;++i)
			if(a[i]>0)
			{
				a[i+1]+=a[i];
				a[i]=0;
			}
		long long ans=0;
		for(int i=1;i<=n;++i)
			if(a[i]>0) ans+=a[i];
		printf("%lld\n",ans);
	}
	return 0;
}