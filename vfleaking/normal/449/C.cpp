#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MaxN = 100000;

int main()
{
	int n;
	cin >> n;

	vector< pair<int, int> > res;
	static bool book[MaxN + 1];
	for (int i = 2; i <= n; i++)
		if (!book[i] && i % 2 == 1)
		{
			int last = 0;
			for (int j = i * 3; j <= n; j += i + i)
				if (!book[j])
				{
					if (last)
						res.push_back(make_pair(last, j)), book[last] = book[j] = true, last = 0;
					else
						last = j;
				}
			if (last)
				res.push_back(make_pair(i, last)), book[last] = book[i] = true;
			else
			{
				if (i * 2 <= n)
					res.push_back(make_pair(i, i * 2)), book[i] = book[i * 2] = true;
			}
		}

	int last = 0;
	for (int i = 2; i <= n; i += 2)
		if (!book[i])
		{
			if (last)
				res.push_back(make_pair(last, i)), last = 0;
			else
				last = i;
		}

	cout << res.size() << endl;
	for (int i = 0; i < (int)res.size(); i++)
		printf("%d %d\n", res[i].first, res[i].second);

	return 0;
}