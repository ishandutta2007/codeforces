#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n,k,ans;
int t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d%I64d",&n,&k);
		ans=0;
		while(n!=0)
		{
			ans+=n%k+1;
			n=n/k;
		}
		printf("%I64d\n",ans-1);
	}
	return 0;
}