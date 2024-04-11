#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;

ll solve(ll x)
{
	x--;
	return (x / 4) * 16 + (x & 1) * 7;
}

int getPos(char c)
{
	if (c >= 'd') return (int)('f' - c);
	return 3 + (int)(c - 'a');
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll x;
	char c;
	scanf("%lld%c", &x, &c);
	printf("%lld\n", solve(x) + getPos(c) + 1);

	return 0;
}