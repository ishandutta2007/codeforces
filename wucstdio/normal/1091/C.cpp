#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n,ans[100005],top;
ll sum(ll x)
{
	return n/x*(1+n-x+1)/2;
}
int main()
{
	scanf("%I64d",&n);
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ans[++top]=sum(i);
			if(i!=n/i)ans[++top]=sum(n/i);
		}
	}
	sort(ans+1,ans+top+1);
	for(int i=1;i<=top;i++)
	  printf("%I64d ",ans[i]);
	printf("\n");
	return 0;
}