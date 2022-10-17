#include <iostream>
#include <cstdio>
#include <map>
#define maxn 500005
using namespace std;
int t, n, cnt[maxn];
char s[maxn];
map<pair<int, int>, int> p;
int gcd(int x, int y)
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
		scanf("%d", &n);
		scanf("%s", s + 1);
		cnt[0] = cnt[1] = 0;
		for (int i = 1; i <= n; i++)
		{
			if(s[i] == 'D') cnt[0]++;
			else cnt[1]++;
			if(cnt[0] == 0 || cnt[1] == 0)
			{
				printf("%d ", i);
				continue;
			}
			int x = gcd(cnt[0], cnt[1]);
			pair<int, int> a = make_pair(cnt[0] / x, cnt[1] / x);
       		map<pair<int, int>, int>::iterator iter = p.find(a);
       		if(iter != p.end())
       		{
       			iter->second++;
				 printf("%d ", iter->second);	
			}
			else
			{
				p.insert({a, 1});
				printf("1 ");
			}
		}
		printf("\n");
	}
	return 0;
}