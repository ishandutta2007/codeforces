#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;

const int N = 300300;
int n;
int ans[N][2];
int m = 0;

int main()
{
	int l = 0;
	set<int> s;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		if (s.count(x) > 0)
		{
			ans[m][0] = l + 1;
			l = i + 1;
			ans[m][1] = l;
			m++;
			s.clear();
		}
		else
			s.insert(x);
	}
	if (m == 0)
		printf("-1\n");
	else
	{
		ans[m - 1][1] = n;
		printf("%d\n", m);
		for(int i = 0; i < m; i++)
			printf("%d %d\n", ans[i][0], ans[i][1]);
	}

	return 0;
}