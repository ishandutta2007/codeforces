#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		long long sum=0;
		int mx=0;
		for(int i=1;i<=n;++i)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if(a>b)
				swap(a,b);
			sum+=a,mx=max(mx,b);
		}
		printf("%lld\n",2*(sum+mx));
	}
	return 0;
}