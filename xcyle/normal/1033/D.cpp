#include <iostream>
#include <cstdio>
#include <map>
#define maxn 2005
#define ll long long
using namespace std;
const int mo = 998244353;
int n;
long long a[maxn];
map<long long, int> p; 
int vis[maxn], type[maxn];
long long tmp[maxn];
int cnt;
int num[maxn];
int check(long long x)
{
	long long l = 1, r = 40000, mid;
	while(l < r)
	{
		mid = (l + r + 1) / 2;
		if(mid * mid * mid * mid <= x) l = mid;
		else r = mid - 1;
	}
	if(l * l * l * l == x)
	{
		map<long long, int>::iterator it = p.find(l);
		if(it == p.end()) p.insert(make_pair(l, 4));
		else it->second += 4;
		return 1;
	}
	l = 1, r = 2e9, mid;
	while(l < r)
	{
		mid = (l + r + 1) / 2;
		if(mid * mid <= x) l = mid;
		else r = mid - 1;
	}
	if(l * l == x)
	{
		map<long long, int>::iterator it = p.find(l);
		if(it == p.end()) p.insert(make_pair(l, 2));
		else it->second += 2;
		return 1;
	}
	l = 1, r = 2e6, mid;
	while(l < r)
	{
		mid = (l + r + 1) / 2;
		if(mid * mid * mid <= x) l = mid;
		else r = mid - 1;
	}
	if(l * l * l == x)
	{
		map<long long, int>::iterator it = p.find(l);
		if(it == p.end()) p.insert(make_pair(l, 3));
		else it->second += 3;
		return 1;
	}
	return 0;
}
inline long long gcd(long long x, long long y)
{
	if(x < y) swap(x, y);
	return y == 0ll ? x : gcd(y, x % y);
}
map<int, int> p2;
int main()
{
	map<long long, int>::iterator it;
	map<int, int>::iterator itt;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		if(check(a[i])) type[i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
//	printf("!");
//			long long ttt = gcd(a[i], a[j]);
			if(gcd(a[i], a[j]) != 1ll && a[i] != a[j]) 
			{
				tmp[++cnt] = gcd(a[i], a[j]);
				itt = p2.find(tmp[cnt]);
				if(itt != p2.end()) cnt--;
				else p2.insert(make_pair(tmp[cnt], 1));
			}
		}
	}
	for (int i = 1; i <= cnt; i++)
	{
		vis[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if(tmp[i] == tmp[j] && vis[j]) vis[i] = 0;
		}
	}
	for (int i = 1; i <= cnt; i++)
	{
		if(!vis[i]) continue;
		it = p.find(tmp[i]);
		if(it == p.end()) p.insert(make_pair(tmp[i], 0));
	}
	for (int i = 1; i <= n; i++)
	{
		if(type[i]) continue;
		for (int j = 1; j <= cnt; j++)
		{
			if(!vis[j]) continue;
			if(a[i] % tmp[j] == 0) 
			{
				it = p.find(tmp[j]);
				it->second++;
				
				it = p.find(a[i] / tmp[j]);
				if(it == p.end()) p.insert(make_pair(a[i] / tmp[j], 1));
				else it->second++;
				type[i] = 1;
				break;
			}
		}
	}
	for (int i = n; i >= 1; i--)
	{
		if(type[i]) continue;
		num[i] = 1;
		for (int j = i + 1; j <= n; j++)
		{
			if(type[i]) continue;
			if(a[i] == a[j])
			{
				num[i] += num[j];
				type[j] = 1;
				break;
			}
		}
	}
	long long ans = 1;
	for (int i = 1; i <= n; i++)
	{
		if(type[i]) continue;
		ans = (ll)ans * (num[i] + 1) % mo * (num[i] + 1) % mo;
	}
	map<long long, int>::iterator it2;
	for(it2 = p.begin(); it2 != p.end(); it2++)
	{
		ans = (ll)ans * (it2->second + 1) % mo; 
	}
	printf("%d", ans);
	return 0;
}