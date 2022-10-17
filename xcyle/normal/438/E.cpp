#include <iostream>
#include <cstdio>
#define ll long long
#define maxn 400005
using namespace std;
const int mo = 998244353;
int n, m, c, a[maxn];
int inva[maxn], tr[maxn];
inline int pow(int x, int step)
{
	int res = 1;
	for(; step; step >>= 1)
	{
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo;
	}
	return res;
}
int g = 3, invg = pow(g, mo - 2);
void NTT(int *f, int len, int flag)
{
	for (int i = 0; i < len; i++) tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? (len >> 1) : 0);
	for (int i = 0; i < len; i++)
	{
		if(i < tr[i]) swap(f[i], f[tr[i]]);
	}
	for (int i = 2; i <= len; i <<= 1)
	{
		int bas = pow(flag ? g : invg, (mo - 1) / i);
		for (int p = (i >> 1), j = 0; j < len; j += i)
		{
			int now = 1;
			for (register int k = j; k < j + p; k++)
			{
				int temp = (ll)now * f[k + p] % mo;
				f[k + p] = (f[k] + mo - temp) % mo;
				f[k] = (f[k] + temp) % mo;
				now = (ll)now * bas % mo;
			}
		}
	}
	if(!flag)
	{
		int temp = pow(len, mo - 2);
		for (int i = 0; i < len; i++) f[i] = (ll)f[i] * temp % mo;
	} 
}
void do_inv(int *g, int len)
{
	static int tmp[maxn], f[maxn];
	for (int i = 0; i < (len << 1); i++) f[i] = tmp[i] = 0;
	f[0] = pow(g[0], mo - 2);
	for (int i = 2; i <= len; i <<= 1)
	{
		for (int j = 0; j < i; j++) tmp[j] = g[j];
		for (int j = i; j < (i << 1); j++) tmp[j] = 0;
		NTT(tmp, i << 1, 1), NTT(f, i << 1, 1);
		for (int j = 0; j < (i << 1); j++)
		{
			f[j] = (2 * f[j] % mo + mo - (ll)f[j] * f[j] % mo * tmp[j] % mo) % mo;
		}
		NTT(f, i << 1, 0);
		for (int j = i; j < (i << 1); j++) f[j] = 0;
	}
	for (int i = 0; i < len; i++) g[i] = f[i];
} 
void do_sqrt(int *g, int len)
{
	static int f[maxn], tmp[maxn], tmp2[maxn];
	for (int i = 0; i < (len << 1); i++) f[i] = tmp[i] = tmp2[i] = 0;
	f[0] = 1;
	for (int i = 2; i <= len; i <<= 1)
	{
		for (int j = 0; j < (i >> 1); j++) tmp[j] = 2 * f[j] % mo;
		for (int j = (i >> 1); j < i; j++) tmp[j] = 0;
		do_inv(tmp, i);
		NTT(f, i << 1, 1);
		NTT(tmp, i << 1, 1);
		for (int j = 0; j < i; j++) tmp2[j] = g[j];
		NTT(tmp2, i << 1, 1); 
		for (int j = 0; j < (i << 1); j++) f[j] = ((ll)f[j] * f[j] % mo + tmp2[j]) * tmp[j] % mo;
		NTT(f, i << 1, 0);
		for (int j = i; j < (i << 1); j++) f[j] = 0;
	}
	for (int i = 0; i < len; i++)
	{
		g[i] = f[i];
	}
}
void debug()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	do_sqrt(a, n);
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	NTT(a, 2 * n, 1);
	for (int i = 0; i < 2 * n; i++) a[i] = (ll)a[i] * a[i] % mo;
	NTT(a, 2 * n, 0);
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
}
int main()
{
//	debug();
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &c);
		a[c] = 1, inva[c] = 2;
	}
	int L = 131072;
	int flag = 0;
	while(!a[flag]) flag++;
	for (int i = 0; i + flag < L; i++) inva[i] = inva[i + flag]; 
	for (int i = L - flag; i < L; i++) inva[i] = 0;
	do_inv(inva, L);
	for (int i = 0; i < L; i++)
	{
		a[i] = (mo - (ll)4 * a[i] % mo) % mo;
	} 
	a[0] = (a[0] + 1) % mo;
	do_sqrt(a, L);
	for (int i = 0; i < L; i++) a[i] = (mo - a[i]) % mo;
	a[0] = (a[0] + 1) % mo;
	for (int i = 0; i + flag < L; i++) a[i] = a[i + flag]; 
	for (int i = L - flag; i < L; i++) a[i] = 0;
	NTT(a, 2 * L, 1), NTT(inva, 2 * L, 1);
	for (int i = 0; i < 2 * L; i++)
	{
		a[i] = (ll)a[i] * inva[i] % mo;
	}
	NTT(a, 2 * L, 0);
	for (int i = 1; i <= m; i++) printf("%d\n", a[i]);
	return 0;
}