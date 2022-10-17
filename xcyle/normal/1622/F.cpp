/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 1000005
using namespace std;
const int mod1 = 998244353;
const int mod2 = 431902847;
const int bas1 = 2;
const int bas2 = 5980513;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int ok[maxn], n, vis[maxn], prime[maxn], cnt;
struct node
{
	int Hash1, Hash2;
	inline bool friend operator == (node aa, node bb)
	{
		return aa.Hash1 == bb.Hash1 && aa.Hash2 == bb.Hash2;
	}
	inline node friend operator ^ (node aa, node bb)
	{
		return (node){aa.Hash1 ^ bb.Hash1, aa.Hash2 ^ bb.Hash2};
	}
}fac[maxn], Pow[maxn], tot;
node sum[maxn];
int check0()
{
	if(tot == (node){0, 0})
	{
		printf("%d\n", n);
		for (int i = 1; i <= n; i++) printf("%d ", i);
		printf("\n");
		return 1;
	}
	return 0;
}
int check1()
{
	for (int i = 1; i <= n; i++)
	{
		if(tot == fac[i])
		{
			printf("%d\n", n - 1);
			for (int j = 1; j <= n; j++)
			{
				if(i != j) printf("%d ", j);
			}
			printf("\n");
			return 1;
		}
	}
	return 0;
}
int check2()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = n; j >= 1; j--)
		{
			if(i == j) continue;
//			if(i == 11 && j == 24) printf("!");
			if(tot == (fac[i] ^ fac[j]))
			{
				printf("%d\n", n - 2);
				for (int k = 1; k <= n; k++)
				{
					if(k != i && k != j) printf("%d ", k);
				}
				printf("\n");
				return 1;
			}
			if(!vis[j] && (n - j + 1) % 2 == 1) break;
		}
	}
	return 0;
}
inline void print(node aa)
{
	printf("%d %d\n", aa.Hash1, aa.Hash2);
}
int main()
{
	scanf("%d", &n);
	Pow[0] = (node){1, 1};
	for (int i = 1; i <= n; i++) Pow[i] = {(ll)Pow[i - 1].Hash1 * bas1 % mod1, (ll)Pow[i - 1].Hash2 * bas2 % mod2};//print(Pow[i]);
	for (int i = 2; i <= n; i++)
	{
		if(!vis[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt && prime[j] * i <= n; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
	for (int i = 1; i <= cnt; i++)
	{
		for (int j = 1; j < prime[i] && prime[i] * j <= n; j += 2)
		{
			sum[prime[i] * j] = sum[prime[i] * j] ^ Pow[prime[i]];
			sum[min(prime[i] * (j + 1), n + 1)] = sum[min(prime[i] * (j + 1), n + 1)] ^ Pow[prime[i]];
		}
	}
	sum[1] = (node){0, 0};
	for (int i = 2; i <= n; i++)
	{
		sum[i] = sum[i] ^ sum[i - 1];
//		sum[i] = sum[i - 1];
//		if(!vis[i]) sum[i] = sum[i] ^ Pow[i];
//		printf("%d %d\n", sum[i].Hash1, sum[i].Hash2);
	}
	for (int i = 1; i <= n; i++)
	{
		fac[i] = sum[i];// ^ sum[(int)sqrt(i)];
		for (int j = 1; j <= cnt; j++)
		{
			if(prime[j] * prime[j] > i) break;
			int num = 0;
			for (ll k = prime[j]; k <= i; k *= prime[j]) num += i / k;
			if(num & 1) fac[i] = fac[i] ^ Pow[prime[j]];//printf("%d %d\n", i, prime[j]);
		}
//		fac[i] = fac[i] ^ fac[i - 1];
//		printf("%d:\n", i);
//		for (int j = 1; j <= cnt; j++)
//		{
//			if((fac[i].Hash1 >> prime[j]) & 1) printf("%d ", prime[j]);
//		}
//		printf("\n");
	}
	if(n <= 3)
	{
		printf("1\n1\n");
		return 0;
	}
	tot = {0, 0};
	for (int i = 1; i <= n; i++) tot = tot ^ fac[i];
//		for (int j = 1; j <= cnt; j++)
//		{
//			if((tot.Hash1 >> prime[j]) & 1) printf("%d ", prime[j]);
//		}
//		printf("\n");
	if(check0()) return 0;
	if(check1()) return 0;
	if(check2()) return 0;
	if(n & 1) n--;
	if((n / 2) & 1) ok[2] = 1;
	ok[n / 2] = 1;
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += 1 - ok[i];
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++) (!ok[i]) && (printf("%d ", i));
	return 0;
}