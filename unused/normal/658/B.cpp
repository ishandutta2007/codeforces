#include <stdio.h>
#include <set>
using namespace std;

int id[200000];

int main()
{
	int n, k, q;
	scanf("%d%d%d", &n, &k, &q);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &id[i]);
	}

	set<int> now;

	for (int i = 0; i < q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		if (a == 1)
		{
			now.insert(id[b]);
			if (now.size() > k) now.erase(now.begin());
		}
		else
		{
			if (now.find(id[b]) != now.end()) printf("YES\n");
			else printf("NO\n");
		}
	}
}