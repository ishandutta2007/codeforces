#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <iostream>
#include <cstdio>
#include <cstring> 
#define ll long long
#define maxn 3005
#define getc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
const int mo = 998244353;
int n, c, a[maxn], val[maxn][maxn];
int pow[maxn], pow2[maxn], fac[maxn], ifac[maxn], inv[maxn];
long long f[maxn][maxn];
int ans[maxn];
int t[maxn];
int p(int x, int step)
{
	int res = 1;
	for(; step; step >>= 1)
	{
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo;
	}
	return res;
}
inline int read()
{
	int x = 0; char ch = getc();
	while(ch < '0' || ch > '9') ch = getc();
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + ch - '0'; ch = getc();}
	return x;
}
void solve()
{
	printf("0 ");
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", (ll)fac[n] * ifac[i] % mo * ifac[n - i] % mo);
	}
}
int g[maxn][9005];
void work()
{
	g[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = (i / c + 1); j >= 0; j--)
		{
			for (register int k = (1 << c) - 1; k >= 0; k--)
			{
				if(((1 << (a[i] - 1)) | k) == (1 << c) - 1) g[j + 1][0] = (g[j + 1][0] + g[j][k]) % mo;
				else g[j][(1 << (a[i] - 1)) | k] = (g[j][(1 << (a[i] - 1)) | k] + g[j][k]) % mo;
			}
		}
	}
	for (int i = 0; i <= n; i++)
	{
		int res = (i == 0 ? mo - 1 : 0);
		for (register int j = 0; j < (1 << c); j++)
		{
			res = (res + g[i][j]) % mo;
		}
		printf("%d ", res);
	}
}
int main()
{
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; i++) a[i] = read();
	pow[0] = 1;
	for (int i = 1; i <= n; i++) pow[i] = pow[i - 1] * 2 % mo;
	for (int i = 0; i <= n; i++)
	{
		pow2[i] = p(pow[i] - 1, mo - 2);
	}
	fac[0] = fac[1] = inv[1] = ifac[0] = ifac[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		fac[i] = (ll)fac[i - 1] * i % mo;
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % mo;
	}
	if(c == 1)
	{
		solve();
		return 0;
	}
	if(c <= 13)
	{
		work();
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= c; j++) t[j] = 0;
		int cnt = 0;
		for (register int j = i - 1; j >= 1; j--)
		{
			if(a[j] == a[i])
			{
				val[i][j] = val[i][j + 1];
				continue;
			}
			t[a[j]]++;
			if(t[a[j]] == 1)
			{
				cnt++;
				if(cnt == c - 1)
				{
					val[i][j] = 1;
					for (int k = 1; k <= c; k++)
					{
						if(k == a[i]) continue;
						val[i][j] = (ll)val[i][j] * (pow[t[k]] - 1) % mo;
					}
				}
			}
			else val[i][j] = (ll)val[i][j + 1] * pow2[t[a[j]] - 1] % mo * (pow[t[a[j]]] - 1) % mo;
//			printf("%d %d %d\n", i, j, val[i][j]);
		}
	}
	memset(t, 0, sizeof(t));
	for (int i = 1; i <= n + 1; i++)
	{
		if(i > 1)
		{
			int res = 1;
			for (int j = 1; j <= c; j++)
			{
				if(j == a[i - 1]) continue;
				res = (ll)res * (pow[t[j]] - 1) % mo;
			}
			f[i][1] = res;
		}
		t[a[i]]++;
		for (int j = 2; j <= i / c; j++)
		{
			for (register int k = 1; k < i; k++)
			{
				f[i][j] += f[k][j - 1] * val[i - 1][k];
				if((k | 7) == k) f[i][j] %= mo;
			}
			f[i][j] %= mo;
		}
	}
	memset(t, 0, sizeof(t));
	for (int j = 0; j <= n; j++) ans[j] = f[n + 1][j];
	for (int i = n; i >= 1; i--)
	{
		t[a[i]]++;
		int res = 1;
		for (int j = 1; j <= c; j++)
		{
			res = (ll)res * (pow[t[j]] - 1) % mo;
		}
		for (register int j = 0; j <= n; j++)
		{
			ans[j] = (ans[j] + (ll)f[i][j] * (pow[n - i + 1] - res + mo) % mo) % mo;
//			printf("%d ",(ll)f[i][j] * (pow[n - i + 1] - res + mo) % mo);
		}
//		printf("\n");
	}
	int res = 1;
	for (int j = 1; j <= c; j++)
	{
		res = (ll)res * (pow[t[j]] - 1) % mo;
	}
	printf("%d ", (pow[n] - 1 - res + mo) % mo);
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}