#include <iostream>
#define int long long
#include <cstdio>
using namespace std;
int a[500005],sum[505][505];
signed main()
{
	int n,q;
	cin >> q;
	while(q--)
	{
		int op,x,y;
		scanf("%lld%lld%lld",&op,&x,&y);
		if(op==2)
		{
			if(x<=500)
				printf("%lld\n",sum[x][y%x]);
			else
			{
				int ans=0;
				for(int i=y;i<=500000;i+=x)
					ans+=a[i];
				printf("%lld\n",ans);
			}
		}
		else
		{
			a[x]+=y;
			for(int i=1;i<=500;i++)
				sum[i][x%i]+=y;
		}
	}
	return 0;
}