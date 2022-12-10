#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) (void)0
#endif

typedef long long ll;

int n;
vector<pair<ll, ll>> segs;

void solve()
{
	segs.emplace_back(-1, 0);
	segs.emplace_back((ll)4e9, (ll)4e9 + 1);

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		sort(segs.begin(), segs.end());

		ll s, d;
		scanf("%lld%lld", &s, &d);

		for (int j = 1; j < (int)segs.size(); j++)
			if (s < segs[j].first)
			{
				if (segs[j - 1].second < s && s + d - 1 < segs[j].first)
					segs.emplace_back(s, s + d - 1);
				else
				{
					for (int k = 1; k < (int)segs.size(); k++)
					{
						if (segs[k - 1].second + d < segs[k].first)
						{
							segs.emplace_back(segs[k - 1].second + 1, segs[k - 1].second + d);
							break;
						}
					}
				}
				break;
			}

		printf("%lld %lld\n", segs.back().first, segs.back().second);
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif

	solve();

	eprintf("\n\ntime: %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

	return 0;
}