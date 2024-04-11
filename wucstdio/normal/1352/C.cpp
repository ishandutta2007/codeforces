#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t;
ll n,k;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		printf("%lld\n",k/(n-1)*n+k%(n-1)-(k%(n-1)==0));
	}
	return 0;
}