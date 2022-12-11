#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int a[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x;
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;++i)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		long long sum=0,ans=0;
		for(int i=1;i<=n;++i)
		{
			sum+=a[i];
			if(sum>x)
				break;
			ans+=(x-sum)/i+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}