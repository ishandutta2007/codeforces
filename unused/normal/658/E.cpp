#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dat[200005];
pair<int, int> nd[200005];

int n, k, b, c;

struct pred
{
	bool operator()(pair<int, int> p1, pair<int, int> p2)
	{
		return p1.second - p2.second < ((long long)p1.first - p2.first) / 5 * b;
	}
};

int main()
{
	scanf("%d%d%d%d", &n, &k, &b, &c);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);
	}

	if (b > c * 5) b = c * 5;

	long long ans = 0x7fFFffFFffFFffFF;

	sort(dat, dat + n);
	if (dat[0] < 0)
	{
		for (int i = 1; i < n; i++) dat[i] -= dat[0];
		dat[0] = 0;
	}

	for (int mod = 0; mod < 5; mod++)
	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, pred> pq;
		long long presum = 0;
		long long possum = 0;

		for (int i = 0; i < n; i++)
		{
			int adv = (mod + 5 - dat[i] % 5) % 5;
			nd[i] = { dat[i] + adv, adv * c };
		}

		for (int i = 0; i < n; i++)
		{
			int tpos = nd[i].first;
			presum += nd[i].second;
			possum += nd[i].first;
			pq.push(nd[i]);
			if (i == n - 1 || nd[i].first != nd[i + 1].first)
			{
				while (pq.size() > k)
				{
					auto t = pq.top();
					pq.pop();
					presum -= t.second;
					possum -= t.first;
				}

				if (pq.size() == k)
				{
					long long res = (tpos * (long long)k - possum) / 5 * b + presum;
					ans = min(ans, res);
				}
			}
		}
	}

	printf("%lld\n", ans);
}