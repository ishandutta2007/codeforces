#include <bits/stdc++.h>
using namespace std;

const int Maxn = 7901, p = 1e9 + 7;
const int dx[] = {0, -1, 0, 1, 0}, dy[] = {0, 0, -1, 0, 1};
int R, tot, sum, a[Maxn][Maxn];
long long P[6];
map <pair <int, int>, int> id;
pair <int, int> pos[Maxn];
long long get_inv(long long x)
{
	if (x <= 1) return 1;
	return (p - p / x) * get_inv(p % x) % p;
}
void work(void)
{
	int r = 0;
	for (int i = 1; i <= tot; i++)
	{
		r = max(r, id[make_pair(pos[i].first + 1, pos[i].second)]);
		long long inv = get_inv(a[i][i]);
		for (int j = r; j >= i; j--)
			a[i][j] = a[i][j] * inv % p;
		a[i][tot + 1] = (a[i][tot + 1] * inv) % p;
		for (int j = i + 1; j <= r; j++)
		{
			(a[j][tot + 1] += p - a[j][i] * (long long) a[i][tot + 1] % p) %= p;
			for (int k = r; k >= i; k--)
				(a[j][k] += p - a[j][i] * (long long) a[i][k] % p) %= p;
		}
	}
	for (int i = tot; i >= 1; i--)
	{
		for (int j = i + 1; j <= tot; j++)
			(a[i][tot + 1] += p - a[i][j] * (long long) a[j][tot + 1] % p) %= p;
		a[i][tot + 1] = (a[i][tot + 1] * get_inv(a[i][i])) % p;
	}
}
int main()
{
	scanf("%d%lld%lld%lld%lld", &R, &P[1], &P[2], &P[3], &P[4]);
	sum = get_inv(P[1] + P[2] + P[3] + P[4]);
	for (int i = 1; i <= 4; i++)
		(P[i] *= sum) %= p;
	for (int i = -R; i <= R; i++)
		for (int j = -R; j <= R; j++)
			if (i * i + j * j <= R * R)
				id[make_pair(i, j)] = ++tot, pos[tot] = make_pair(i, j);
	for (int i = 1; i <= tot; i++)
	{
		a[i][i] = 1, a[i][tot + 1] = 1;
		int now;
		for (int j = 1; j <= 4; j++)
			if ((now = id[make_pair(pos[i].first + dx[j], pos[i].second + dy[j])]))
				a[i][now] = (p - P[j]) % p;
	}
	work();
	printf("%d", a[id[make_pair(0, 0)]][tot + 1]);
	return 0;
}