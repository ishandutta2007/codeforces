#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ll cur=0,ans=0;
		int flag=-1;
		for(int i=1;i<=n;i++)
		{
			ll x;
			scanf("%lld",&x);
			if((x>0)!=flag)ans+=cur,cur=x,flag=(x>0);
			else cur=max(cur,x);
		}
		printf("%lld\n",ans+cur);
	}
	return 0;
}