#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MaxN = 4000;
const int MaxB = 1000000;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

int main()
{
	int n;
	static int a[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	int len = 0;
	static int seq[MaxN];
	for (int i = 1; i <= n; i++)
		seq[len++] = a[i];
	sort(seq, seq + len);
	len = unique(seq, seq + len) - seq;

	static vector<int> pos[MaxN];
	for (int i = 1; i <= n; i++)
		pos[lower_bound(seq, seq + len, a[i]) - seq].push_back(i);

	int best = 1;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
		{
			if (i == j)
			{
				relax(best, (int)pos[i].size());
				continue;
			}
			int i1 = 0, i2 = 0;
			int s1 = pos[i].size(), s2 = pos[j].size();

			int res = 1;
			int cur;
			if (pos[i][0] < pos[j][0])
				cur = 2;
			else
				cur = 1;
			while (true)
			{
				if (cur == 1)
				{
					while (i1 < s1 && pos[i][i1] < pos[j][i2])
						i1++;
					if (i1 == s1)
						break;
					res++;
				}
				else
				{
					while (i2 < s2 && pos[j][i2] < pos[i][i1])
						i2++;
					if (i2 == s2)
						break;
					res++;
				}
				cur = 3 - cur;
			}
			relax(best, res);
		}

	cout << best << endl;

	return 0;
}