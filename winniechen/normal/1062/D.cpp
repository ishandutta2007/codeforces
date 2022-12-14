#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
#define ll long long
#define mod 1000000007
ll n,ans;
int main()
{
	scanf("%lld",&n);ll i;
	for(i=2;i<=n;i++)ans+=(2ll+(n/i))*((n/i)-1ll)/2;
	printf("%lld\n",ans<<2);
	return 0;
}