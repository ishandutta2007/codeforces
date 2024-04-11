#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long s64;

const int MaxN = 50000;

int n;
char s[MaxN + 1];

const int H = 1000000007;
int h[MaxN + 1];
int hpow[MaxN + 1];
void init_hash()
{
	h[0] = 0;
	for (int i = 0; i < n; i++)
		h[i + 1] = (h[i] + (s64)(s[i] - 'a') * hpow[i]) % H;
}

bool is_same(int l, int i, int j)
{
	return (s64)(h[i + l] + H - h[i]) * hpow[j - i] % H == (h[j + l] + H - h[j]) % H;
}

int getlcp(int i, int j)
{
	int le = 1, ri = i + 2;
	while (le != ri)
	{
		int mid = (le + ri) / 2;
		if (is_same(mid, i - mid + 1, j - mid + 1))
			le = mid + 1;
		else
			ri = mid;
	}
	return le - 1;
}
int getlcs(int i, int j)
{
	int le = 1, ri = n - j + 1;
	while (le != ri)
	{
		int mid = (le + ri) / 2;
		if (is_same(mid, i, j))
			le = mid + 1;
		else
			ri = mid;
	}
	return le - 1;
}

bool check(int l)
{
	for (int i = l; i + l <= n; i += l)
		if (getlcp(i - 1, i + l - 1) + getlcs(i, i + l) >= l)
			return true;
	return false;
}

int main()
{
	scanf("%s", s);
	n = strlen(s);

	hpow[0] = 1;
	for (int i = 1; i <= n; i++)
		hpow[i] = (s64)hpow[i - 1] * 31 % H;

	init_hash();
	for (int l = 1; l <= n; l++)
		if (check(l))
		{
			int c = 0;
			int new_n = l;
			for (int i = l; i < n; i++)
			{
				if (s[i] == s[i - l])
				{
					c++;
					if (c == l)
					{
						new_n -= l;
						c = 0;
					}
				}
				else
					c = 0;
				s[new_n++] = s[i];
			}
			n = new_n;
			s[n] = '\0';

			init_hash();
		}

	cout << s << endl;

	return 0;
}