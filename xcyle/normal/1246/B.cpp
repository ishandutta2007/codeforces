#include <iostream>
#include <cstdio>
#include <map>
#define maxn 100005
#define uint unsigned int
using namespace std;
int n, k, a[maxn];
uint pow1[maxn], pow2[maxn];
struct node
{
	uint hash1, hash2;
	bool friend operator < (node a, node b)
	{
		return a.hash1 == b.hash1 ? a.hash2 < b.hash2 : a.hash1 < b.hash1;
	} 
	bool friend operator == (node a, node b)
	{
		return a.hash1 == b.hash1 && a.hash2 == b.hash2;
	} 
};
map<node, int> p;
map<node, int>::iterator it;
int main()
{
	scanf("%d%d", &n, &k);
	pow1[0] = pow2[0] = 1;
	for (int i = 1; i < maxn; i++)
	{
		pow1[i] = pow1[i - 1] * 998244353;
		pow2[i] = pow2[i - 1] * 4103982379;
	} 
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		uint h1 = 0, h2 = 0;
		uint h3 = 0, h4 = 0;
		int tmp = a[i];
		for (int j = 2; j * j <= tmp; j++)
		{
			int cnt = 0;
			while(tmp % j == 0)
			{
				cnt++;
				tmp /= j;
			}
			cnt %= k;
			h1 += pow1[j] * cnt;
			h3 += pow1[j] * ((k - cnt) % k);
			h2 += pow2[j] * cnt;
			h4 += pow2[j] * ((k - cnt) % k);
		}
		if(tmp > 1)
		{
			int cnt = 1;
			h1 += pow1[tmp] * cnt;
			h3 += pow1[tmp] * ((k - cnt) % k);
			h2 += pow2[tmp] * cnt;
			h4 += pow2[tmp] * ((k - cnt) % k);
		}
		it = p.find((node){h3, h4});
		if(it != p.end()) ans += (it -> second);
		it = p.find((node){h1, h2});
		if(it == p.end()) p.insert(make_pair((node){h1, h2}, 0));
		it = p.find((node){h1, h2});
		(it->second)++;
	}
	printf("%lld\n", ans);
	return 0;
}