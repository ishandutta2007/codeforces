#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;
const ll MOD = (ll)1e9 + 7;

const int N = 100100;
ll ans = 1;
char s[N];

int getNum(char c)
{
	if ('0' <= c && c <= '9') return c - '0';
	if ('A' <= c && c <= 'Z') return 10 + c - 'A';
	if ('a' <= c && c <= 'z') return 36 + c - 'a';
	if (c == '-') return 62;
	if (c == '_') return 63;
	throw;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		int x = getNum(s[i]);
		for (int k = 0; k < 6; k++)
			if (((x >> k) & 1) == 0)
				ans = (ans * 3) % MOD;
	}
	printf("%lld\n", ans);

	return 0;
}