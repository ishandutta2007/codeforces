#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#define ll long long
using namespace std;
ll n,a[100005],now;
set<ll>s;
int main()
{
	for(ll x=0;x<=4000000;x++)s.insert(x*x);
	scanf("%I64d",&n);
	for(int i=2;i<=n;i+=2)
	  scanf("%I64d",&a[i]);
	for(int i=1;i<=n;i+=2)
	{
		ll last=now;
		now++;
		while(now<=4000000&&s.find(now*now+a[i+1])==s.end())now++;
		if(now>4000000)
		{
			printf("No\n");
			return 0;
		}
		a[i]=now*now-last*last;
		last=now;
		while(last*last+a[i+1]!=now*now)now++;
	}
	printf("Yes\n");
	for(int i=1;i<=n;i++)
	  printf("%I64d ",a[i]);
	printf("\n");
	return 0;
}