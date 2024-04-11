#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define ll long long
ll n;
int ans;
int main()
{
	scanf("%lld",&n);
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			n-=i;
			ans++;
			break;
		}
	}if(!ans)return puts("1"),0;
	printf("%lld\n",(n>>1)+ans);
}