#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

const int TSIZE = 100000;
long long tree[TSIZE + 1];
// Returns the sum from index 1 to p, inclusive
long long query(int p) {
	long long ret = 0;
	for (; p > 0; p -= p & -p) ret += tree[p];
	return ret;
}
// Adds val to element with index pos
void add(int p, int val) {
	for (; p <= TSIZE; p += p & -p) tree[p] += val;
}

int dat[TSIZE + 1];
int destroy[TSIZE + 1];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &dat[i]);
		add(i, dat[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &destroy[i]);
	}

	multiset<long long> interval;
	map<pair<int, int>, long long> value;

	value.emplace(make_pair(1, n), query(n));
	interval.insert(query(n));

	for (int i = 1; i <= n - 1; i++)
	{
		auto itr = value.lower_bound({ destroy[i], 0 });
		if (itr == value.end() || itr->first.first > destroy[i]) itr--;
		int sx = itr->first.first, ex = itr->first.second;
		interval.erase(interval.find(itr->second));
		value.erase(itr);

		if (sx < destroy[i])
		{
			long long sum = query(destroy[i] - 1) - query(sx - 1);
			interval.insert(sum);
			value.emplace(make_pair(sx, destroy[i] - 1), sum);
		}

		if (destroy[i] < ex)
		{
			long long sum = -query(destroy[i]) + query(ex);
			interval.insert(sum);
			value.emplace(make_pair(destroy[i] + 1, ex), sum);
		}

		printf("%lld\n", *interval.rbegin());
	}

	printf("0\n");
}