#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

const int MaxN = 100000;

int main()
{
	int n;
	static int a[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	static bool book[1 << 20];
	static vector<int> pos[20];
	for (int i = n; i >= 1; i--)
		for (int j = 0; j < 20; j++)
			if (a[i] & 1 << j)
				pos[j].push_back(i);

	for (int i = 1; i <= n; i++)
	{
		int seqLen = 0;
		pair<int, int> seq[20];
		for (int j = 0; j < 20; j++)
		{
			if (!pos[j].empty() && pos[j].back() < i)
				pos[j].pop_back();
			if (!pos[j].empty())
				seq[seqLen++] = make_pair(pos[j].back(), j);
		}
		sort(seq, seq + seqLen);

		int cur = 0;
		for (int i = 0, j = 0; i < seqLen; i = j)
		{
			while (j < seqLen && seq[j].first == seq[i].first)
			{
				cur |= 1 << seq[j].second;
				j++;
			}
			book[cur] = true;
		}
	}

	int res = count(book, book + (1 << 20), true);
	if (find(a + 1, a + n + 1, 0) != a + n + 1)
		res++;
	cout << res << endl;

	return 0;
}