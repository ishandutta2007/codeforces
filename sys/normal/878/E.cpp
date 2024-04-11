#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 100005, p = 1e9 + 7;
int n, q, pnt, s[Maxn], a[Maxn], l[Maxn], r[Maxn], lt[Maxn], rt[Maxn], siz[Maxn], fa[Maxn];
long long p2[Maxn], inv_p2[Maxn], tot[Maxn], ans[Maxn], S[Maxn], sum[Maxn];
vector <int> Ve[Maxn];
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void merge(int x, int y)
{
	int A = get_fa(x), B = get_fa(y);
	fa[B] = A;
	r[A] = r[B];
	if (siz[A] >= 31 && tot[B])
		tot[A] = (tot[A] + p + p2[siz[A]] * tot[B]) % p + p;
	else
	{
		tot[A] += p2[siz[A]] * tot[B];
		if (tot[A] >= p) tot[A] = tot[A] % p + p;
	}
	siz[A] += siz[B];
	pnt--;
	S[A] = (S[s[pnt - 1]] + p + tot[A]) % p;
	if (s[pnt - 1]) (S[A] += p + tot[A]) %= p;
}
long long work(int L)
{
	return (S[s[pnt]] + p - S[get_fa(L)] + (sum[r[get_fa(L)]] - sum[L - 1] + p) * inv_p2[L - 1] % p) % p;
}
int main()
{
	scanf("%d%d", &n, &q);
	p2[0] = inv_p2[0] = 1;
	for (int i = 1; i <= n; i++)
		p2[i] = i <= 30 ? p2[i - 1] * 2 : p2[i - 1] * 2 % p, inv_p2[i] = inv_p2[i - 1] * (p + 1) / 2 % p;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), sum[i] = (sum[i - 1] + (p + a[i]) * p2[i - 1]) % p, fa[i] = i, l[i] = r[i] = i, tot[i] = a[i], siz[i] = 1;
	for (int i = 1; i <= q; i++)
		scanf("%d%d", &lt[i], &rt[i]), Ve[rt[i]].push_back(i);
	for (int i = 1; i <= n; i++)
	{
		s[++pnt] = i, S[i] = (S[get_fa(i - 1)] + 2LL * (p + a[i])) % p;
		while (tot[get_fa(i)] >= 0 && l[get_fa(i)] != 1) merge(l[get_fa(i)] - 1, i);
		for (vector <int> :: iterator it = Ve[i].begin(); it != Ve[i].end(); it++)
			ans[*it] = work(lt[*it]);
	}
	for (int i = 1; i <= q; i++)
		printf("%lld\n", ans[i]);
	return 0;
}