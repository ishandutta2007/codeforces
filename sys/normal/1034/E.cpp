#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1 << 21 | 5;
int n;
long long a[Maxn], b[Maxn];
string s, t;
void FWT(long long now[], int len, bool type = false)
{
	for (int i = 1; i < len; i <<= 1)
		for (int j = 0; j < len; j += (i << 1))
			for (int k = j; k < i + j; k++)
				now[k + i] += type ? -now[k] : now[k];
}
int main()
{
	cin >> n >> s >> t;
	for (int i = 0; i < (1 << n); i++)
	{
		a[i] = (s[i] - 48LL) << (__builtin_popcount(i) << 1);
		b[i] = (t[i] - 48LL) << (__builtin_popcount(i) << 1);
	}
	FWT(a, 1 << n), FWT(b, 1 << n);
	for (int i = 0; i < (1 << n); i++)
		a[i] *= b[i];
	FWT(a, 1 << n, true);
	for (int i = 0; i < (1 << n); i++)
		putchar(((a[i] >> (__builtin_popcount(i) << 1)) & 3) + '0');
	return 0;
}