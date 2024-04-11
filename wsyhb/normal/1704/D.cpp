#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
__int128 sum[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				long long c;
				scanf("%lld",&c);
				sum[i]+=j*c;
			}
		__int128 mn=(__int128)1<<120,mx=0;
		for(int i=1;i<=n;++i)
		{
			mn=min(mn,sum[i]);
			mx=max(mx,sum[i]);
		}
		int k=0;
		for(int i=1;i<=n;++i)
		{
			if(sum[i]==mx)
			{
				k=i;
				break;
			}
		}
		printf("%d %lld\n",k,(long long)(mx-mn));
		for(int i=1;i<=n;++i)
			sum[i]=0;
	}
	return 0;
}