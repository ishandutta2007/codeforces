#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll k;
int main()
{
	scanf("%I64d",&k);
	ll x=1;
	for(int i=1;i<=20;i++)
	{
		ll num=x*9;
		if(k>num*i)k-=num*i;
		else
		{
			ll y=(k-1)/i;
			k=(k-1)%i+1;
			y+=x;
			k=i-k;
			while(k)
			{
				y/=10;
				k--;
			}
			printf("%d\n",y%10);
			return 0;
		}
		x*=10;
	}
	return 0;
}