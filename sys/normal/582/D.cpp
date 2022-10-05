#include <bits/stdc++.h>
using namespace std;

const int Maxn = 4005, p = 1e9 + 7;
int N, P, lim;
long long val[Maxn];
string A;
void multi(void)
{
	for (int i = 1; i <= N; i++)
		val[i] *= 10;
}
void add(int x)
{
	val[1] += x;
	N = max(N, 1);
	for (int i = 1; i <= N; i++)
		if (val[i] >= P)
		{
			val[i + 1] += val[i] / P, val[i] %= P;
			N = max(N, i + 1);
		}
}
void init(void)
{
	for (int i = 0; i < A.size(); i++)
		multi(), add(A[i] - '0');
}
long long ans, f[Maxn][2][2], g[Maxn][2][2];
int main()
{
	ios::sync_with_stdio(false);
	cin >> P >> lim >> A;
	init();
	f[0][1][0] = 1;
	for (int i = N; i >= 1; i--)
	{
		for (int j = 0; j <= N - i + 1; j++)
			g[j][0][0] = g[j][0][1] = g[j][1][0] = g[j][1][1] = 0;
		long long c1 = P * (P + 1LL) / 2 % p; // 0 <= a + b < P or we can say P <= a + b + 1 < 2 * P
		long long c2 = P * (P - 1LL) / 2 % p; // 0 <= a + b + 1 < P or we can say P <= a + b < 2 * P
		long long c3 = val[i] * (val[i] + 1LL) / 2 % p; // 0 <= a + b < val[i]
		long long c4 = val[i] * (val[i] - 1LL) / 2 % p; // 0 <= a + b + 1 < val[i]
		long long c5 = val[i] * (2LL * P - val[i] - 1) / 2 % p; // P <= a + b < P + val[i]
		long long c6 = val[i] * (2LL * P - val[i] + 1) / 2 % p; // P <= a + b + 1 < P + val[i]
		for (int j = 0; j <= N - i; j++)
		{
			(g[j][0][0] += f[j][0][0] * c1 + f[j][1][0] * c3) %= p;
			(g[j][0][1] += f[j][0][0] * c2 + f[j][1][0] * c4) %= p;
			(g[j][1][0] += f[j][1][0] * (val[i] + 1)) %= p;
			(g[j][1][1] += f[j][1][0] * val[i]) %= p;
			(g[j + 1][0][0] += f[j][0][1] * c2 + f[j][1][1] * c5) %= p;
			(g[j + 1][0][1] += f[j][0][1] * c1 + f[j][1][1] * c6) %= p;
			(g[j + 1][1][0] += f[j][1][1] * (P - 1 - val[i])) %= p;
			(g[j + 1][1][1] += f[j][1][1] * (P - val[i])) %= p;
		}
		swap(f, g);
	}
	for (int i = lim; i <= N; i++)
		(ans += f[i][0][0] + f[i][1][0]) %= p;
	printf("%lld", ans);
	return 0;
}