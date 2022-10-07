#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t;
ll n,x,y;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&x,&y);
		ll k=x+y;
		printf("%lld ",min(n,max(1ll,k+1-n)));
		printf("%lld\n",min(n,k-1));
	}
	return 0;
}