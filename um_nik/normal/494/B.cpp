#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 200100;
const ll MOD = (ll)1e9 + 7;
int n, m;
string s, p;
int z[N];
int sz;
int a[N];
int pos[N];
ll sum[N], sumsum[N];

void calc_z()
{
	z[0] = 0;
	int l = 0, r = 0;
	for (int i = 1; i < n; i++)
	{
		if (i < r)
			z[i] = min(r - i, z[i - l]);
		while (i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++;
		if (i + z[i] > r)
		{
			l = i;
			r = i + z[i];
		}
	}
	return;
}

int main()
{
	cin >> s >> p;
	s = p + "#" + s;
	m = p.length();
	n = s.length();
	calc_z();
	for (int i = m + 1; i < n; i++)
		if (z[i] >= m)
			a[sz++] = i - m - 1;
//	for (int i = 0; i < sz; i++)
//		printf("%d ", a[i]);
//	printf("\n");
	if (sz == 0)
	{
		printf("0\n");
		return 0;
	}
	int idx = sz - 1;
	n -= m + 1;
	for (int i = 0; i <= n; i++)
		pos[i] = -1;
	for (int i = n; i >= 0; i--)
	{
		while (idx >= 0 && a[idx] + m > i) idx--;
		if (idx == -1) break;
		pos[i] = a[idx];
	}
	sum[0] = sumsum[0] = 1LL;
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1];
		if (pos[i] != -1)
			sum[i] = (sum[i] + sumsum[pos[i]]) % MOD;
		sumsum[i] = (sumsum[i - 1] + sum[i]) % MOD;
	}
	printf("%I64d\n", (sum[n] + MOD - 1LL) % MOD);

	return 0;
}