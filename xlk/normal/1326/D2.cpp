#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1000020];
ll b = 131;
ll bb[1000020];
ll mod = 123456789012345;
int pl, pr;
void work(int l, int r)
{
	ll h1 = 0;
	ll h2 = 0;
	int llen = 0;
	for (int i = l; i <= r; i++)
	{
		h1 = (h1 * b + s[i]) % mod;
		h2 = (h2 + s[i] * bb[i - l]) % mod;
		if (h1 == h2)
		{
			llen = i - l + 1;
		}
	}
	h1 = h2 = 0;
	int rlen = 0;
	for (int i = r; i >= l; i--)
	{
		h1 = (h1 * b + s[i]) % mod;
		h2 = (h2 + s[i] * bb[r - i]) % mod;
		if (h1 == h2)
		{
			rlen = r - i + 1;
		}
	}
	if (llen >= rlen)
	{
		pl = l;
		pr = l + llen - 1;
	}
	else
	{
		pl = r - rlen + 1;
		pr = r;
	}
}
int main()
{
	int t;
	srand((long)(new int));
	mod += rand();
	for (int i = bb[0] = 1; i <= 1000000; i++)
	{
		bb[i] = bb[i - 1] * b % mod;
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%s", s);
		int n = strlen(s);
		int l = 0;
		int r = n - 1;
		while (l < r)
		{
			if (s[l] == s[r])
			{
				l++;
				r--;
			}
			else
			{
				break;
			}
		}
		pl = n;
		pr = 0;
		work(l, r);
		for (int i = 0; i < l; i++)
		{
			printf("%c", s[i]);
		}
		for (int i = pl; i <= pr; i++)
		{
			printf("%c", s[i]);
		}
		for (int i = r + 1; i < n; i++)
		{
			printf("%c", s[i]);
		}
		printf("\n");
	}
}