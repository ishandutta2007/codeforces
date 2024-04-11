#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
int T, n, a[Maxn], cnt[2], f[Maxn][Maxn][2];
bool dfs(int a, int b, bool A)
{
	if (!a && !b) return A ^ 1;
	if (a < 0 || b < 0) return true;
	if (f[a][b][A] != -1) return f[a][b][A];
	return (f[a][b][A] = !dfs(a - 1, b, (b & 1) ^ A ^ 1) | !dfs(a, b - 1, ((b - 1) & 1) ^ A));
}
int main()
{
	scanf("%d", &T);
	memset(f, -1, sizeof(f));
	while (T--)
	{
		cnt[0] = cnt[1] = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), cnt[a[i] & 1]++;
		puts(dfs(cnt[0], cnt[1], 0) ? "Alice" : "Bob");
	}
	return 0;
}