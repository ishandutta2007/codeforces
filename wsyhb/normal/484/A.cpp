#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		long long l,r;
		scanf("%lld%lld",&l,&r);
		long long ans=0;
		for(int i=59;i>=0;--i)
		{
			if((l>>i&1)==(r>>i&1))
			{
				if(l>>i&1)
					ans|=1ll<<i;
			}
			else
			{
				assert(r>>i&1);
				long long v=(1ll<<i)-1;
				if((r&v)==v)
					ans|=(1ll<<(i+1))-1;
				else
					ans|=v;
				break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}