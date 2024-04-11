#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[200020];
int c[200020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			c[a[i]]++;
		}
		vector<int> z;
		set<int> s;
		int x = 0;
		for (int i = 0; i < n; i++)
		{
			s.insert(a[i]);
			c[a[i]]--;
			while (s.find(x) != s.end())
			{
				x++;
			}
			if (c[x] == 0)
			{
				z.push_back(x);
				s.clear();
				x = 0;
			}
		}
		printf("%d\n", int(z.size()));
		for (int i : z)
		{
			printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}