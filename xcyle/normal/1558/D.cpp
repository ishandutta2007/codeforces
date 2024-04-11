#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define ll long long
#define maxn 400005
using namespace std;
const int mo = 998244353;
int T;
inline int read()
{
	int w = 0, x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') 
	{
		w |= ch == '-';
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar(); 
	}
	return w ? -x : x;
}
vector<int> ans;
int t[maxn], t2[maxn], n, m, a[maxn];
int x[maxn], y[maxn];
int fac[maxn], ifac[maxn], inv[maxn];
inline int calc(int x, int y)
{
	if(y < 0 || x < y) return 0;
	return (ll)fac[x] * ifac[y] % mo * ifac[x - y] % mo;
}
void add(int x, int data)
{
	for (; x <= n; x += (x & (-x))) t[x] += data;
}
int find(int x)
{
	int pos = 0, now = 0;
	for (int i = 20; i >= 0; i--)
	{
		if(pos + (1 << i) > n) continue;
		if(pos + (1 << i) - t[pos + (1 << i)] - now >= x) continue;
		pos += (1 << i);
		now += t[pos];
//		printf("%d %d %d\n", x, pos, now);
	} 
	return pos + 1;
}
void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) 
	{
		scanf("%d%d", &x[i], &y[i]);
		swap(x[i], y[i]);
	}
	int cnt = 0;
	for (int i = m; i >= 1; i--)
	{
		int k = find(x[i]);
//		printf("!!!!!!%d\n", k);
		if(find(x[i] + 1) == k + 1) cnt++;
		add(k, 1);
		x[i] = k;
	}
//	for (int i = 1; i <= m; i++) printf("%d ", x[i]);
//	printf("\n");
	for (int i = m; i >= 1; i--)
	{
		add(x[i], -1);
	}
	printf("%d\n", calc(n + n - cnt - 1, n - cnt - 1));
}
int main()
{
	inv[1] = ifac[0] = ifac[1] = fac[0] = fac[1] = 1;
	for (int i = 2; i < maxn; i++)
	{
		fac[i] = (ll)fac[i - 1] * i % mo;
		inv[i] = (ll)(mo - mo / i) * inv[mo % i] % mo;
		ifac[i] = (ll)ifac[i - 1] * inv[i] % mo;
	}
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}