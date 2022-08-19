#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

int main()
{
	ll x, y, z;
	scanf("%lld%lld%lld", &x, &y, &z);
	printf("%lld\n", ((x + z - 1) / z) * ((y + z - 1) / z));

	return 0;
}