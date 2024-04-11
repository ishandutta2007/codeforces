#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
long long val, f[Maxn][Maxn];
int T;
bool ask(long long x)
{
	string str;
	printf("? %lld\n", x);
	fflush(stdout);
	cin >> str;
	if (str == "Lucky!") return val += x, true;
	if (str == "Fraudster!") return val -= x, false;
	puts("GG");
	exit(0);
}
int main()
{
	mt19937 rd(1);
	for (int i = 0; i <= 100; i++) f[0][i] = 1;
	for (int i = 1; i <= 100; i++)
	{
		f[i][0] = f[i - 1][1];
		for (int j = 1; j <= i; j++)
			f[i][j] = min((long long) 1e18, f[i - 1][j - 1] + f[i - 1][j + 1]);
		for (int j = i + 1; j <= 100; j++)
			f[i][j] = f[i][i];
	}
	scanf("%d", &T);
	while (T--)
	{
		if (!ask(1))
		{
			puts("! 0");
			fflush(stdout);
			continue;
		}
		val = 1;
		long long l, r;
		while (true)
		{
			long long las = val;
			if (val > 1e14)
			{
				r = 1e14;
				break;
			}
			if (ask(val)) l = las;
			else
			{
				r = las - 1;
				break;
			}
		}
		int x = 3, y = 3;
		ask(l), ask(l), ask(l);
		while (f[x][y] < r - l + 1) x++;
		while (x)
		{
			if (l == r) break;
			while (r - l + 1 > f[x][y]) ask(l), y++;
			while (r - l + 1 <= f[x - 1][y]) x--;
			long long mid = l + f[x - 1][y - 1];
			while (val < mid) ask(l);
			if (ask(mid)) l = mid, y++;
			else r = mid - 1, y--;
			x--;
		}
		printf("! %lld\n", l);
		fflush(stdout);
	}
	return 0;
}