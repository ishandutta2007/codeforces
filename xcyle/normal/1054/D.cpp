#include <iostream>
#include <cstdio>
#include <map>
#define maxn 200005
using namespace std;
int n, a[maxn], k;
map<int, int> p;
int main()
{
	scanf("%d%d", &n, &k);
	map<int, int>::iterator it;
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d", &a[i]);
		a[i] ^= a[i - 1];
		if(a[i] * 2 >= (1 << k)) a[i] = (1 << k) - 1 - a[i];
		it = p.find(a[i]);
		if(it == p.end()) p.insert(make_pair(a[i], 1));
		else it->second++;
	}
	it = p.find(0);
	if(it == p.end()) p.insert(make_pair(0, 1));
	else it->second++;
	map<int, int>::reverse_iterator it2;
	long long ans = 0;
	for(it2 = p.rbegin(); it2 != p.rend(); it2++)
	{
		long long x = it2->second;
		ans += ((x / 2) * (x / 2 - 1) + (x - x / 2) * (x - x / 2 - 1)) / 2;
	}
	long long x = n;
	printf("%lld", x * (x + 1) / 2 - ans);
	return 0;
}