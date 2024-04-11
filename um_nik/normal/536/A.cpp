#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long ll;

ll A, B;
int n;
ll l, t, m;

bool check(ll r)
{
	ll sum = A * (r - l) + B * ((r - l) * (r + l - 1) / 2LL);
	if (sum > m * t) return false;
	ll val = A + B * (r - 1);
	if (val > t) return false;
	return true;
}

void solve()
{
	scanf("%I64d%I64d%I64d", &l, &t, &m);
	l--;
	ll L = l;
	ll R = l + t + 3;
	while(L + 1 < R)
	{
		ll x = (L + R) / 2;
		if (check(x))
			L = x;
		else
			R = x;
	}
	if (L == l)
		printf("-1\n");
	else
		printf("%d\n", (int)L);
}

int main()
{
	scanf("%I64d%I64d", &A, &B);
	scanf("%d", &n);
	while(n--)
		solve();

	return 0;
}