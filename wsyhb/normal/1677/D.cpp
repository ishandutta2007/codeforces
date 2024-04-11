//
#include<bits/stdc++.h>
using namespace std;
const int max_n=1e6+5;
int v[max_n];
const int mod=998244353;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;++i)
			scanf("%d",v+i);
		bool ok=true;
		for(int i=n-k+1;i<=n;++i)
		{
			if(v[i]!=-1&&v[i]!=0)
			{
				ok=false;
				break;
			}
		}
		if(!ok)
		{
			puts("0");
			continue;
		}
		int ans=1;
		for(int i=1;i<=k;++i)
			ans=1ll*ans*i%mod;
		for(int i=1;i<=n-k;++i)
		{
			if(v[i]==-1)
				ans=1ll*ans*(k+i)%mod;
			else if(!v[i])
				ans=ans*(k+1ll)%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}