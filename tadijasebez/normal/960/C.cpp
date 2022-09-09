#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
vector<ll> sol;
int main()
{
	ll x,d;int i,j;
	scanf("%lld %lld",&x,&d);
	for(i=0;i<62;i++)
	{
		if((x>>i)&1)
		{
			for(j=0;j<i;j++)
			{
				sol.pb(((i+1)*2+1)*(d+1));
			}
			sol.pb(((i+1)*2)*(d+1));
		}
	}
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++)
	{
		printf("%lld ",sol[i]);
	}
	printf("\n");
	return 0;
}