#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005, p = 998244353;
int T, n, cnt, ct[Maxn], head[Maxn], maxi[Maxn];
long long ans, inv[Maxn];
struct edg
{
	int nxt, to, A, B;
} edge[2 * Maxn];
void add(int x, int y, int A, int B)
{
	edge[++cnt] = (edg){head[x], y, A, B};
	head[x] = cnt;
	edge[++cnt] = (edg){head[y], x, B, A};
	head[y] = cnt;
}
void dfs(int u, int fa)
{
	
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to, A = edge[i].A, B = edge[i].B;
		if (to != fa)
		{
			int tmp = B, M = sqrt(B);
			for (int i = 2; i <= M; i++)
				if (tmp % i == 0)
					while (tmp % i == 0) tmp /= i, ct[i]--;
			if (tmp != 1) ct[tmp]--;
			tmp = A, M = sqrt(A);
			for (int i = 2; i <= M; i++)
				if (tmp % i == 0)
				{
					while (tmp % i == 0) tmp /= i, ct[i]++;
					maxi[i] = max(maxi[i], ct[i]);
				}
			if (tmp != 1) ct[tmp]++, maxi[tmp] = max(maxi[tmp], ct[tmp]);
			dfs(to, u);
			tmp = B, M = sqrt(B);
			for (int i = 2; i <= M; i++)
				if (tmp % i == 0)
					while (tmp % i == 0) tmp /= i, ct[i]++;
			if (tmp != 1) ct[tmp]++;
			tmp = A, M = sqrt(A);
			for (int i = 2; i <= M; i++)
				if (tmp % i == 0)
					while (tmp % i == 0) tmp /= i, ct[i]--;
			if (tmp != 1) ct[tmp]--;
		}
	}
}
void dfs2(int u, int fa, long long now)
{
	(ans += now) %= p;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to, A = edge[i].A, B = edge[i].B;
		if (to != fa)
			dfs2(to, u, now * B % p * inv[A] % p);
	}
}
int main()
{
	inv[1] = 1;
	for (int i = 2; i <= 200000; i++)
		inv[i] = (p - p / i) * inv[p % i] % p;
	scanf("%d", &T);
	while (T--)
	{
		ans = 0;
		memset(head, 0, sizeof(int[n + 1])), cnt = 0;
		memset(ct, 0, sizeof(int[n + 1])), memset(maxi, 0, sizeof(int[n + 1]));
		scanf("%d", &n);
		for (int i = 1; i < n; i++)
		{
			int x, y, A, B;
			scanf("%d%d%d%d", &x, &y, &A, &B), add(x, y, A, B);
		}
		dfs(1, 0);
		memcpy(ct, maxi, sizeof(int[n + 1]));
		long long tmp = 1;
		for (int i = 2; i <= n; i++)
			for (int j = 1; j <= ct[i]; j++) (tmp *= i) %= p;
		dfs2(1, 0, tmp);
		printf("%lld\n", ans);
	}
	return 0;
}