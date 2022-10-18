#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

const int MaxN = 1000000;

template <class It>
It prev(It p)
{
	return --p;
}
template <class It>
It next(It p)
{
	return ++p;
}

int main()
{
	int n;
	static int fa[MaxN + 1];
	static int f[MaxN + 1];
	static multiset<int> sonS[MaxN + 1];

	cin >> n;

	fa[1] = 0;
	f[1] = 0;
	for (int cv = 2; cv <= n + 1; cv++)
	{
		scanf("%d", &fa[cv]);

		f[cv] = 1;
		int oldF = -1;
		int lastV = cv;
		for (int v = fa[cv]; v; v = fa[v])
		{
			if (oldF != -1)
				sonS[v].erase(sonS[v].find(oldF));
			sonS[v].insert(f[lastV]);

			oldF = f[v];
			if (v == 1)
				f[v] = *prev(sonS[v].end());
			else
			{
				if (prev(sonS[v].end()) == sonS[v].begin())
					f[v] = *prev(sonS[v].end());
				else
					f[v] = max(*prev(prev(sonS[v].end())) + 1, *prev(sonS[v].end()));
			}

			if (f[v] == oldF)
				break;

			lastV = v;
		}

		printf("%d ", f[1]);
	}
	printf("\n");

	return 0;
}