#include <bits/stdc++.h>
using namespace std;

int cnt[16][65536];
long long dcount[20][16];
bool visit[20][16];

long long DC(int k, int d)
{
	if (d == 0) return 1;
	if (k == 0) return 0;
	if (visit[k][d] == false)
	{
		visit[k][d] = true;
		dcount[k][d] = d * DC(k - 1, d);
		for (int z = 0; z <= d; z++)
		{
			dcount[k][d] += DC(k - 1, z);
		}
	}
	return dcount[k][d];
}

inline int lg2(int a)
{
	return 31 - __builtin_clz(a);
}

inline int ctoi(char ch)
{
	if (ch >= '0' && ch <= '9') return ch - '0';
	else return ch - 'a' + 10;
}

long long g(char *buf, int len, int hi)
{
	if (len == 0) return cnt[hi][65535];
	long long c[16] = {};

	for (int i = 0; i < ctoi(buf[0]); i++)
	{
		for (int j = 0; j < 16; j++)
		{
			c[max({ hi, i, j })] += DC(len - 1, j);
		}
	}

	long long ret = 0;
	for (int i = 0; i < 16; i++) ret += cnt[i][65535] * c[i];

	return ret + g(buf + 1, len - 1, max(hi, ctoi(buf[0])));
}

long long f(long long n)
{
	if (n <= 65535)
	{
		return cnt[0][n];
	}

	long long upper = n / 65536;
	int high = 0;
	for (long long z = upper; z; z /= 16) high = max(high, (int)(z % 16));
	long long ret = cnt[high][n % 65536];

	char buf[22];
	--upper;
	sprintf(buf, "%llx", upper);

	return ret + g(buf, strlen(buf), 0);
}

long long naive(long long n)
{
	long long ret = 0;
	for (long long i = 0; i <= n; i++)
	{
		int hi = 0;
		for (long long j = i; j; j /= 16) hi = max(hi, (int)(j % 16));
		if (i & (1 << hi)) ret++;
	}
	return ret;
}

int main()
{
	for (int i = 0; i < 16; i++)
	{
		cnt[i][0] = 0;
		for (int j = 1; j < 65536; j++)
		{
			int high = i;
			for (int jj = j; jj; jj /= 16) high = max(high, jj % 16);
			if ((1 << high) & j) cnt[i][j] = cnt[i][j - 1] + 1;
			else cnt[i][j] = cnt[i][j - 1];
		}
	}

	int q;
	scanf("%d", &q);

	while (q--)
	{
		long long a, b;
		scanf("%llx%llx", &a, &b);
		if (a == 0) printf("%lld\n", f(b));
		else printf("%lld\n", f(b) - f(a - 1));
		/*if (a == 0) printf("%lld %lld\n", f(b), naive(b));
		else printf("%lld %lld\n", f(b) - f(a-1), naive(b) - naive(a-1));*/
	}
}