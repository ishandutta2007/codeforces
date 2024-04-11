#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

vector<int> ans;
set<int> dat;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		dat.insert(tmp);
	}

	for (int i = 1; m >= i; i++)
	{
		if (dat.find(i) == dat.end())
		{
			m -= i;
			ans.push_back(i);
		}
	}

	printf("%d\n", (int)ans.size());
	for (int d : ans)
	{
		printf("%d ", d);
	}
}