#include <bits/stdc++.h>
using namespace std;

const int Maxn = 3005;
int n, k, pos[Maxn], tot[Maxn], t[Maxn];
long long ans, f[Maxn], sum[Maxn];
vector <int> Ve[Maxn];
void insert(int x)
{
	for (int j = k - t[x]; j >= 0; j--)
		f[t[x] + j] = max(f[t[x] + j], f[j] + sum[x]);
}
void divide(int root, int lt, int rt)
{
	if (lt == rt)
	{
		long long tmp_sum = 0;
		for (int j = k; j >= 0; j--)
		{
			ans = max(ans, f[j] + tmp_sum);
			if (k - j + 1 <= t[lt]) tmp_sum += Ve[lt][k - j + 1];
		}
	}
	else
	{
		long long tmp[Maxn];
		int mid = (lt + rt) >> 1;
		memcpy(tmp, f, sizeof(long long[k + 1]));
		for (int i = mid + 1; i <= rt; i++)
			insert(i);
		divide(root << 1, lt, mid);
		memcpy(f, tmp, sizeof(long long[k + 1]));
		for (int i = lt; i <= mid; i++)
			insert(i);
		divide(root << 1 | 1, mid + 1, rt);
	}
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &t[i]);
		Ve[i].resize(t[i] + 1);
		for (int j = 1; j <= t[i]; j++)
			scanf("%d", &Ve[i][j]), sum[i] += Ve[i][j];
	} 
	divide(1, 1, n);
	printf("%lld", ans);
	return 0;
}