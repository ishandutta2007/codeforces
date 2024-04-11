#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
std::map<int, int> mp;
int n,l[301],c[301];
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&l[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&c[i]);
	}
	mp[0]=0;
	for (int i = 0; i < n; ++i)
	{
		for (std::map<int, int>::iterator it=mp.begin(); it != mp.end(); ++it)
		{
			int GCD=std::__gcd((*it).first,l[i]),cost=(*it).second+c[i];
			if (mp.count(GCD))
			{
				mp[GCD]=std::min(mp[GCD],cost);
			}
			else
			{
				mp[GCD]=cost;
			}
		}
	}
	if (!mp.count(1))
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", mp[1]);
	}
	return 0;
}