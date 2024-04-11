#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll a,b;
int t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		ll n=a/b;
		ll d=b%10,now=d;
		ll ans=0;
		for(int i=1;i<=10;i++)
		{
			ans+=(n+10-i)/10*now;
			now=(now+d)%10;
		}
		printf("%lld\n",ans);
	}
	return 0;
}