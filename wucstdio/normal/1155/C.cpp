#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll x[300005],d;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&x[i]);
		if(i!=1)d=__gcd(d,x[i]-x[i-1]);
	}
	for(int i=1;i<=m;i++)
	{
		ll v;
		scanf("%I64d",&v);
		if(d%v==0)
		{
			printf("YES\n");
			printf("%I64d %d\n",x[1],i);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}