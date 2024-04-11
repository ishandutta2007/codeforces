#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t,a,b,q,sum[40005];
bool flag[40005];
ll ask(ll n)
{
	return sum[a*b-1]*(n/(a*b))+sum[n%(a*b)];
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&q);
		for(int i=0;i<a*b;i++)
		{
			if(i%a%b!=i%b%a)flag[i]=1;
			else flag[i]=0;
			if(i==0)sum[i]=0;
			else sum[i]=sum[i-1];
			if(flag[i])sum[i]++;
		}
		while(q--)
		{
			ll l,r;
			scanf("%lld%lld",&l,&r);
			printf("%lld ",ask(r)-ask(l-1));
		}
		printf("\n");
	}
	return 0;
}