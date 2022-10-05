#include <bits/stdc++.h>
using namespace std;

const int Maxn = 255, p = 998244353;
int n, cyc, P[Maxn], Q[Maxn], fa[Maxn], cnt[7];
bool vis1[Maxn], vis2[Maxn];
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void merge(int x, int y)
{
	int a = get_fa(x), b = get_fa(y);
	if (a == b)
	{
		cyc++;
		fa[a] = 0;
	}
	else
	{
		fa[a] = b;
		vis1[b] |= vis1[a];
		vis2[b] |= vis2[a];
	}
}
long long get_inv(int x)
{
	if (x <= 1) return 1;
	return (p - p / x) * get_inv(p % x) % p;
}
void multi(long long A[], long long B[], long long C[], long long ans[], int len)
{
	for (int i = 0; i <= len; i++) ans[i] = 0;
	for (int i = 0; i <= len; i++)
		for (int j = 0; i + j <= len; j++)
			for (int k = 0; i + j + k <= len; k++)
				(ans[i + j + k] += A[i] * B[j] % p * C[k]) %= p;
}
long long A[Maxn], B[Maxn], D[Maxn], C[Maxn][Maxn], S[Maxn][Maxn], fac[Maxn], inv[Maxn], result[Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &P[i]), fa[i] = i;
	for (int i = 1; i <= n; i++)
		scanf("%d", &Q[i]);
	for (int i = 1; i <= n; i++)
	{
		if (P[i] && Q[i]) merge(P[i], Q[i]);
		if (P[i] && !Q[i]) vis2[get_fa(P[i])] = true;
		if (!P[i] && Q[i]) vis1[get_fa(Q[i])] = true;
	}
	for (int i = 1; i <= n; i++)
		if (get_fa(i) == i)
			cnt[vis1[i] * 2 + vis2[i]]++;
	C[0][0] = S[0][0] = fac[0] = inv[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
			S[i][j] = (S[i - 1][j - 1] + S[i - 1][j] * (i - 1)) % p;
		}
		fac[i] = fac[i - 1] * i % p;
		inv[i] = get_inv(fac[i]);
	}
	for (int i = 0; i <= cnt[1]; i++)
		for (int j = i; j <= cnt[1]; j++)
			(A[i] += C[cnt[1]][j] * S[j][i] % p * fac[cnt[0] + cnt[1] - j] % p * inv[cnt[0]]) %= p;
	for (int i = 0; i <= cnt[1]; i++)
	{
		long long tmp = 0;
		for (int j = i; j <= cnt[1]; j++)
			(tmp += A[j] * C[j][i] % p * ((j - i) & 1 ? p - 1 : 1)) %= p;
		A[i] = tmp;
	}
	for (int i = 0; i <= cnt[2]; i++)
		for (int j = i; j <= cnt[2]; j++)
			(B[i] += C[cnt[2]][j] * S[j][i] % p * fac[cnt[0] + cnt[2] - j] % p * inv[cnt[0]]) %= p;
	for (int i = 0; i <= cnt[2]; i++)
	{
		long long tmp = 0;
		for (int j = i; j <= cnt[2]; j++)
			(tmp += B[j] * C[j][i] % p * ((j - i) & 1 ? p - 1 : 1)) %= p;
		B[i] = tmp;
	}
	for (int i = 0; i <= cnt[0]; i++)
		D[i] = S[cnt[0]][i];
	multi(A, B, D, result, n);
	for (int i = 0; i < n; i++)
		printf("%lld ", n - i - cyc >= 0 ? result[n - i - cyc] * fac[cnt[0]] % p : 0);
	return 0;
}