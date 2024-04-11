#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long

int main()
{
	ll n,i;
	scanf("%lld",&n);
	ll sol=0;
	for(i=1;i<n;i<<=1)
	{
		ll block=(n+i-1)/i;
		sol+=(block/2)*i;
	}
	printf("%lld\n",sol);
	return 0;
}