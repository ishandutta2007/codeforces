#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;
int n;
ll k, h;
ll cur, T;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld%lld", &n, &h, &k);
	cur = 0;
	T = 0;
	while(n--)
	{
		ll x;
		scanf("%lld", &x);
		if (cur + x > h)
		{
			ll z = (cur + x - h + k - 1) / k;
			T += z;
			cur = max(0LL, cur - z * k);
		}
		cur += x;
	}
	T += (cur + k - 1) / k;
	printf("%lld\n", T);

	return 0;
}