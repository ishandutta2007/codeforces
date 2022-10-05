#include <bits/stdc++.h>
using namespace std;

const int Maxn = 405;
int n, m, p, ct, fct, fa[Maxn * Maxn], F[Maxn * Maxn], id[Maxn][Maxn];
long long ans, A[Maxn][Maxn];
char G[Maxn][Maxn];
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void merge(int x, int y)
{
	if (!x || !y) return ;
	if (get_fa(x) == get_fa(y))
	{
		puts("0");
		exit(0);
	}
	fa[get_fa(x)] = get_fa(y);
}
void add(int x, int y)
{
	(A[x][y] += p - 1) %= p, (A[y][x] += p - 1) %= p, (A[x][x] += 1) %= p, (A[y][y] += 1) %= p;
}
long long get_inv(long long x)
{
	if (x <= 1) return 1;
	return (p - p / x) * get_inv(p % x) % p;
}
void work(void)
{
	bool flag = false;
	for (int i = 1; i < fct; i++)
	{
		for (int j = i; j < fct; j++)
			if (A[j][i])
			{
				if (i != j) flag ^= 1;
				swap(A[i], A[j]);
				break;
			}
		long long inv = get_inv(A[i][i]);
		for (int j = i + 1; j < fct; j++)
			(A[i][j] *= inv) %= p;
		for (int j = 1; j < fct; j++)
			if (i != j)
				for (int k = fct - 1; k >= i; k--)
					(A[j][k] += p - A[j][i] * A[i][k] % p) %= p;
	}
	long long result = 1;
	for (int i = 1; i < fct; i++)
		(result *= A[i][i]) %= p;
	if (flag) result = (p - result) % p;
	(ans += result) %= p;
}
int main()
{
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			char ch = getchar();
			while (ch != '\\' && ch != '/' && ch != '*')
				ch = getchar();
			G[i][j] = ch;
		}
	for (int i = 1; i <= n + 1; i++)
		for (int j = 1; j <= m + 1; j++)
			if ((i + j) & 1) id[i][j] = ++ct, fa[ct] = ct;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (G[i][j] == '\\') merge(id[i][j], id[i + 1][j + 1]);
			if (G[i][j] == '/') merge(id[i][j + 1], id[i + 1][j]);
		}
	for (int i = 1; i <= n + 1; i++)
		for (int j = 1; j <= m + 1; j++)
			if (id[i][j] && get_fa(id[i][j]) == id[i][j]) F[id[i][j]] = ++fct;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (G[i][j] == '*')
			{
				add(F[get_fa(id[i][j])], F[get_fa(id[i + 1][j + 1])]);
				add(F[get_fa(id[i][j + 1])], F[get_fa(id[i + 1][j])]);
			}
	work();
	ct = fct = 0;
	for (int i = 1; i <= n + 1; i++)
		for (int j = 1; j <= m + 1; j++)
			if (!((i + j) & 1)) id[i][j] = ++ct, fa[ct] = ct;
			else id[i][j] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (G[i][j] == '\\') merge(id[i][j], id[i + 1][j + 1]);
			if (G[i][j] == '/') merge(id[i][j + 1], id[i + 1][j]);
		}
	for (int i = 1; i <= n + 1; i++)
		for (int j = 1; j <= m + 1; j++)
			if (id[i][j] && get_fa(id[i][j]) == id[i][j]) F[id[i][j]] = ++fct;
	for (int i = 1; i <= fct; i++)
		for (int j = 1; j <= fct; j++)
			A[i][j] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (G[i][j] == '*')
			{
				add(F[get_fa(id[i][j])], F[get_fa(id[i + 1][j + 1])]);
				add(F[get_fa(id[i][j + 1])], F[get_fa(id[i + 1][j])]);
			}
	work();
	printf("%lld", ans);
	return 0;
}