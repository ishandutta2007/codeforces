#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int MaxN = 100000;

// adjust
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

int main()
{
	int n;
	static int ti[MaxN + 1];
	static int c[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &ti[i], &c[i]);
		ti[i]++;
	}

	int maxQ = 0;
	int curQ = 0;
	int curT = 0;

	int bot = 1;
	while (bot != n + 1 || curQ != 0)
	{
		if (bot == n + 1 || (curQ != 0 && curT + curQ < ti[bot]))
		{
			curT += curQ;
			curQ = 0;
		}
		else
		{
			int delta = ti[bot] - curT;
			curT += delta;
			if (curQ != 0)
				curQ -= delta;
			curQ += c[bot];
			relax(maxQ, curQ);

			bot++;
		}
	}

	cout << curT - 1 << " " << maxQ << endl;

	return 0;
}