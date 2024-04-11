#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
ll Try(ll n, ll k)
{
	ll sol=0,need=(n+1)/2;
	while(n)
	{
		sol+=min(k,n);
		n-=min(k,n);
		n-=n/10;
	}
	return sol>=need;
}
int main()
{
	ll n;
	scanf("%lld",&n);
	//for(n=1;n<=100;n++)
	//{
		ll top=n,bot=1,mid,ans;
		//for(ans=1;!Try(n,ans);ans++);
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(Try(n,mid)) ans=mid,top=mid-1;
			else bot=mid+1;
		}
		printf("%lld\n",ans);
		//printf("%lld: %lld\n",n,ans);
	//}
	return 0;
}