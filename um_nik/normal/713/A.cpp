#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

const int N = (1 << 18) + 7;
int a[N];

int getMask(ll x)
{
	int mask = 0;
	for (int i = 0; i < 18; i++)
	{
		if (x & 1)
			mask |= 1 << i;
		x /= 10;
	}
	return mask;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int q;
	scanf("%d", &q);
	while(q--)
	{
		char c;
		ll x;
		scanf(" %c %lld", &c, &x);
		int mask = getMask(x);
		if (c == '+')
			a[mask]++;
		else if (c == '-')
			a[mask]--;
		else
			printf("%d\n", a[mask]);
	}

	return 0;
}