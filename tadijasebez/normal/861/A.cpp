#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll lcm(int n, int x){ return (ll)x*n/__gcd(n,x);}
int main()
{
	int n,k,i,x=1;
	scanf("%i %i",&n,&k);
	while(k--) x*=10;
	printf("%lld\n",lcm(n,x));
	return 0;
}