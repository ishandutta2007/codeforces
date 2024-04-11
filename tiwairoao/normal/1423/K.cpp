#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000005
int t, n, f[N];
int P[N], H[N], cnt;
template<typename tmp>void Read(tmp &p)
{
	p = 0;
	int f = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar())f |= (c == '-');
	for (; c >= '0' && c <= '9'; c = getchar())p = p * 10 + c - '0';
	if (f)p =- p;
}
int main()
{
	f[1] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		if (!H[i])
		{
			P[++cnt] = i;
			f[i]++;
			if (1ll * i * i <= 1000000)
				f[i * i]--;
		}
		for (int j = 1; j <= cnt; j++)
		{
			if (i * P[j] > 1000000)
				break;;
			H[i * P[j]] = 1;
			if (i % P[j] == 0)
				break;
		}
		f[i] += f[i - 1];
	}
	Read(t);
	while (t--)
	{
		Read(n);
		printf("%d\n", f[n]);
	}
}