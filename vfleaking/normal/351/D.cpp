#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int MaxV = 100000;
const int MaxN = 100000;
const int MaxNQ = 100000;

struct interval
{
	int num;
	int le, ri;

	friend inline bool operator<(const interval &lhs, const interval &rhs)
	{
		return lhs.ri < rhs.ri;
	}
};

int n;

inline void bit_add(int *bit, const int &pos, const int &val)
{
	if (pos == 0)
		bit[0] += val;
	else
	{
		for (int i = pos; i <= n; i += i & (-i))
			bit[i] += val;
	}
}
inline int bit_query(const int *bit, const int &pos)
{
	int res = bit[0];
	for (int i = pos; i >= 1; i -= i & (-i))
		res += bit[i];
	return res;
}

int main()
{
	static int a[MaxN + 1];
	static int prevA[MaxN + 1];
	static int prev[MaxV + 1];
	static int bitOccur[MaxN + 1];
	static int bitCover[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	int nQ;
	static interval q[MaxNQ + 1];

	cin >> nQ;
	for (int i = 1; i <= nQ; i++)
		q[i].num = i, scanf("%d %d", &q[i].le, &q[i].ri);
	sort(q + 1, q + nQ + 1);

	static int res[MaxNQ + 1];

	static int minOrzP[MaxV + 1];
	for (int ri = 1, curQ = 1; ri <= n; ri++)
	{
		if (prev[a[ri]] != 0)
			bit_add(bitOccur, prev[a[ri]], -1);
		bit_add(bitOccur, ri, 1);
		prevA[ri] = prev[a[ri]];
		prev[a[ri]] = ri;

		if (prevA[ri] == 0)
			minOrzP[a[ri]] = 1;
		else
		{
			bit_add(bitCover, minOrzP[a[ri]] - 1, -1), bit_add(bitCover, prevA[ri], 1);
			if (prevA[prevA[ri]] != 0 && prevA[ri] - prevA[prevA[ri]] != ri - prevA[ri])
				minOrzP[a[ri]] = prevA[prevA[ri]] + 1;
		}
		bit_add(bitCover, minOrzP[a[ri]] - 1, 1), bit_add(bitCover, ri, -1);

		while (curQ <= nQ && q[curQ].ri == ri)
		{
			int num = q[curQ].num;
			int c = bit_query(bitCover, q[curQ].le - 1);
			res[num] = bit_query(bitOccur, q[curQ].ri) - bit_query(bitOccur, q[curQ].le - 1);
			if (c == 0)
				res[num]++;
			curQ++;
		}
	}

	for (int num = 1; num <= nQ; num++)
		printf("%d\n", res[num]);

	return 0;
}