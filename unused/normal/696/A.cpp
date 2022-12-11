#include <stdio.h>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

map < pair<long long, long long>, long long > fee;

int main()
{
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int type;
		scanf("%d", &type);
		if (type == 1)
		{
			long long v, u, w;
			scanf("%lld%lld%lld", &v, &u, &w);
			set<pair<long long, long long>> route;
			while (v > 1)
			{
				route.emplace(v >> 1, v);
				v >>= 1;
			}
			while (u > 1)
			{
				if (route.emplace(u >> 1, u).second == false)
					route.erase({ u >> 1, u });
				u >>= 1;
			}

			for (auto &&elem : route)
			{
				fee[elem] += w;
			}
		}
		else
		{
			long long u, v;
			scanf("%lld%lld", &v, &u);
			set<pair<long long, long long>> route;

			while (v > 1)
			{
				route.emplace(v >> 1, v);
				v >>= 1;
			}
			while (u > 1)
			{
				if (route.emplace(u >> 1, u).second == false)
					route.erase({ u >> 1, u });
				u >>= 1;
			}

			long long ret = 0;
			for (auto &&elem : route)
			{
				ret += fee[elem];
			}

			printf("%lld\n", ret);
		}
	}
}