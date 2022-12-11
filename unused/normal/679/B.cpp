#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

long long cubes[100005];
map<long long, pair<long long, int>> d;

pair<long long, int> D(long long t)
{
	if (t <= 7) return{ t, t };
	auto itr = d.emplace(t, make_pair(0, 0));
	if (itr.second)
	{
		int lo = 1, hi = 100000, mid;
		while (lo <= hi)
		{
			mid = (lo + hi) / 2;
			if (cubes[mid] <= t && t < cubes[mid + 1])
			{
				break;
			}
			else if (t < cubes[mid])
			{
				hi = mid - 1;
			}
			else
			{
				lo = mid + 1;
			}
		}

		long long m = mid;

		auto a = D(t - m * m * m), b = D(m * m * m - 1);
		a.first += m * m * m;
		a.second += 1;

		if (a.second < b.second || (a.second == b.second && a.first < b.first))
		{
			itr.first->second = b;
		}
		else
		{
			itr.first->second = a;
		}
	}
	return itr.first->second;
}

int main()
{
	for (long long i = 1; i <= 100000; i++)
	{
		cubes[i] = i * i * i;
	}

	long long m;
	scanf("%lld", &m);

	printf("%d %lld\n", D(m).second, D(m).first);
}