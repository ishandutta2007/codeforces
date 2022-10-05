#include <bits/stdc++.h>
using namespace std;

const int Maxn = 17;
int n, tot, d[Maxn], Lg[1 << Maxn | 5];
long long ans = 0x3f3f3f3f3f3f3f3fLL, f[1 << Maxn | 5], sum[1 << Maxn | 5];
string str;
int c(char x)
{
	if (isdigit(x)) return x - '0';
	return x - 'a' + 10;
}
int lowbit(int x)
{
	return x & -x;
}
void work(void)
{
	int maxi = 1 << (n - 1);
	memset(f, 0x3f, sizeof(long long[maxi]));
	f[0] = 0;
	sum[0] = d[n - 1];
	for (int i = 1; i < maxi; i++)
		sum[i] = sum[i - lowbit(i)] + d[Lg[lowbit(i)]];
	if (sum[maxi] < 0 || sum[maxi] > 15) return ;
	for (int i = 0; i < maxi; i++)
	{
		if (sum[i] < 0 || sum[i] > 15) continue;
		for (int j = 0; j < n; j++)
			if (!(i & (1 << j)))
				f[i ^ (1 << j)] = min(f[i ^ (1 << j)], f[i] + (sum[i] << (j << 2)));
	}
	ans = min(ans, f[maxi - 1]);
}
void dfs(int u, int cnt)
{
	if (u == n - 1)
	{
		if (!cnt) work();
	}
	else
	{
		if (cnt < n - u) dfs(u + 1, cnt);
		if (cnt)
		{
			d[u] -= 16;
			d[u + 1]++;
			dfs(u + 1, cnt - 1);
			d[u] += 16;
			d[u + 1]--;
		}
	}
}
void putc(int x)
{
	if (x < 10) putchar(x + '0');
	else putchar(x - 10 + 'a');
}
void print(long long x, int dig)
{
	if (dig == 1) putc(x);
	else print(x / 16, dig - 1), putc(x % 16);
}
int main()
{
	for (int i = 0; i <= 15; i++)
		Lg[1 << i] = i;
	cin >> str;
	n = str.size();
	for (int i = 0; i < n; i++)
		tot += c(str[i]), d[i] = c(str[n - i - 1]);
	if (tot % 15)
	{
		puts("NO");
		return 0;
	}
	tot /= 15;
	dfs(0, tot);
	if (ans == 0x3f3f3f3f3f3f3f3fLL)
		puts("NO");
	else print(ans, n);
	return 0;
}