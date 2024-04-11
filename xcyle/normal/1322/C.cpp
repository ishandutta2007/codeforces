#include <iostream>
#include <cstdio>
#include <map>
#define maxn 1000005
using namespace std;
int t, n, m, x, y;
long long a[maxn], b[maxn];
struct Hash
{
	unsigned int hash1, hash2;
	bool friend operator == (Hash x, Hash y)
	{
		return x.hash1 == y.hash1 && x.hash2 == y.hash2; 
	}
	bool friend operator < (Hash x, Hash y)
	{
		return x.hash1 == y.hash1 ? x.hash2 < y.hash2 : x.hash1 < y.hash1; 
	}
}g[maxn];
unsigned int pow1[maxn], pow2[maxn];
map<Hash, long long> p;
long long gcd(long long x, long long y)
{
	if(y > x) swap(x, y);
	return y == 0 ? x : gcd(y, x % y);
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		p.clear();
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		pow1[0] = pow2[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			pow1[i] = pow1[i - 1] * 50331653;
			pow2[i] = pow2[i - 1] * 201326611;
		}
		for (int i = 1; i <= n; i++) g[i] = (Hash){0, 0};
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d", &x, &y);
			g[y].hash1 ^= pow1[x] * (unsigned int)x;
			g[y].hash2 += pow2[x] * (unsigned int)x;
		}
		map<Hash, long long>::iterator it;
		for (int i = 1; i <= n; i++)
		{
			if(g[i].hash1 == 0 && g[i].hash2 == 0) continue;
			it = p.find(g[i]);
			if(it == p.end()) p.insert(make_pair(g[i], a[i]));
			else it->second += a[i];
		}
		long long ans = 0;
		for (it = p.begin(); it != p.end(); it++) 
		{
			if(!ans) ans = it->second;
			else ans = gcd(ans, it->second);
		}
		printf("%lld\n", ans);
	}
	return 0;
}