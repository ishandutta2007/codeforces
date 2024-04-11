#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int mod = 998244353;
long long w, h;
long long ksm(long long a, long long b)
{
	long long sum = 1;
	while(b)
	{
		if(b&1)
		{
			sum = sum * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return sum;
}
int main()
{
	scanf("%lld%lld", &w, &h);
	printf("%lld", ksm(2LL, w + h));
	return 0;
}