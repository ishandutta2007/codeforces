#include <iostream>
#include <cstdio>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

const int MaxN = 500000;

typedef long long s64;

template <class T>
inline T prev(T p)
{
	return --p;
}
template <class T>
inline T next(T p)
{
	return ++p;
}

int main()
{
	int n;
	static int orz[MaxN + 1];
	static pair<int, int> a[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i].first), a[i].second = i, orz[i] = a[i].first;
	sort(a + 1, a + n + 1);

	set<int> seq;

	s64 res = 0;

	for (int i = n; i >= 1; i--)
	{
		pair<set<int>::iterator, bool> ret = seq.insert(a[i].second);
		set<int>::iterator it = ret.first;

		if (it != seq.begin() && (++it)-- != seq.end())
			res += min(orz[*(--it)++], orz[*(++it)--]);
		else
		{
			if (it != seq.begin() && prev(it) != seq.begin())
				res += min(orz[*prev(prev(it))], orz[*it]);
			if (next(it) != seq.end() && next(next(it)) != seq.end())
				res += min(orz[*next(next(it))], orz[*it]);
		}
	}
	cout << res << endl;

	return 0;
}