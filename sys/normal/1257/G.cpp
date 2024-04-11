#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1 << 19 | 5, p = 998244353;
int n, ct, L[Maxn], cnt[10 * Maxn], rev[Maxn];
long long maxi;
pair <int, int> A[Maxn];
void get_rev(int len)
{
	for (int i = 0; i < len; i++)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (len >> 1));
}
long long fast_pow(long long x, long long y)
{
	long long ans = 1, now = x;
	while (y)
	{
		if (y & 1) ans = ans * now % p;
		now = now * now % p;
		y >>= 1;
	}
	return ans;
}
void NTT(long long now[], int len, bool type = false)
{
	for (int i = 0; i < len; i++)
		if (i < rev[i]) swap(now[i], now[rev[i]]);
	for (int i = 1; i < len; i <<= 1)
	{
		long long w = fast_pow(type ? 332748118 : 3, (p - 1) / (i << 1));
		for (int j = 0; j < len; j += (i << 1))
		{
			long long l = 1;
			for (int k = j; k < i + j; k++, l = l * w % p)
			{
				long long x = now[i + k] * l % p, y = now[k];
				now[k] = (x + y) % p;
				now[i + k] = (y - x + p) % p;
			}
		}
	}
	if (type)
	{
		long long inv = fast_pow(len, p - 2);
		for (int i = 0; i < len; i++)
			now[i] = now[i] * inv % p;
	}
}
int lower(int x)
{
	int tmp = 1;
	for (; tmp < x; tmp <<= 1);
	return tmp;
}
void multi(long long x[], long long y[], int len)
{
	get_rev(len);
	NTT(x, len), NTT(y, len);
	for (int i = 0; i < len; i++)
		x[i] = x[i] * y[i] % p;
	NTT(x, len, true);
}
long long * ans[Maxn];
void work(int root, int lt, int rt)
{
	if (lt == rt)
	{
		L[root] = A[lt].second;
		int tmp_len = lower(L[root] + 1);
		ans[root] = new long long[tmp_len];
		memset(ans[root], 0, sizeof(long long[tmp_len]));
		for (int i = 0; i <= L[root]; i++) ans[root][i] = 1;
		return ;
	}
	int mid = (lt + rt) >> 1;
	work(root << 1, lt, mid), work(root << 1 | 1, mid + 1, rt);
	static long long tmp[Maxn];
	int tmp_len = lower(1 + (L[root] = L[root << 1] + L[root << 1 | 1]));
	ans[root] = new long long[tmp_len];
	memset(ans[root], 0, sizeof(long long[tmp_len]));
	memcpy(ans[root], ans[root << 1], sizeof(long long[1 + L[root << 1]]));
	memset(tmp, 0, sizeof(long long[tmp_len]));
	memcpy(tmp, ans[root << 1 | 1], sizeof(long long[1 + L[root << 1 | 1]]));
	multi(ans[root], tmp, tmp_len);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x), cnt[x]++;
	}
	for (int i = 1; i <= 3000000; i++)
		if (cnt[i]) A[++ct] = make_pair(i, cnt[i]);
	sort(A + 1, A + 1 + ct, [](pair <int, int> x, pair <int, int> y){return x.second < y.second;});
	work(1, 1, ct);
	printf("%lld\n", ans[1][L[1] / 2]);
	return 0;
}