#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

const int MaxN = 100000;

// adjust variable
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tension(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

struct item
{
	int dis;
	int value;

	item(){}
	item(const int &_dis, const int &_value)
		: dis(_dis), value(_value){}

	friend inline bool operator<(const item &lhs, const item &rhs)
	{
		if (lhs.dis != rhs.dis)
			return lhs.dis < rhs.dis;
		return lhs.value < rhs.value;
	}
};

int main()
{
	int n;
	static int a[MaxN + 1], posA[MaxN + 1];
	static int b[MaxN + 1], posB[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		posA[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
		posB[b[i]] = i;
	}

	set<item> lS, rS;
	for (int i = 1; i <= n; i++)
	{
		if (posB[i] < posA[i])
			lS.insert(item(posA[i] - posB[i], i));
		else
			rS.insert(item(posB[i] - posA[i], i));
	}

	static int outcome[MaxN + 1];
	for (int i = 1; i <= n; i++)
	{
		int res = INT_MAX;
		if (!lS.empty())
			tension(res, lS.begin()->dis - i + 1);
		if (!rS.empty())
			tension(res, rS.begin()->dis + i - 1);
		int first = n - i + 2;
		if (first > n)
			first -= n;
		outcome[first] = res;

		int last = b[n - i + 1];
		int lastdis = n - posA[last] - i + 1;
		rS.erase(item(lastdis, last));
		if (posA[last] > 1)
			lS.insert(item(posA[last] - 1 + i, last));
		else
			rS.insert(item(-i, last));

		while (!lS.empty() && lS.begin()->dis == i)
		{
			rS.insert(item(-i, lS.begin()->value));
			lS.erase(lS.begin());
		}
	}

	for (int i = 1; i <= n; i++)
		printf("%d\n", outcome[i]);

	return 0;
}