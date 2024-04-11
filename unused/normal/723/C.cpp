#include <stdio.h>
#include <vector>
using namespace std;

int dat[2005];
vector<int> pos[2005];
vector<int> vt;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);
		if (dat[i] <= m)
		{
			pos[dat[i]].push_back(i);
		}
		else vt.push_back(i);
	}

	int ans = n / m;
	int ans2 = 0;

	for (int i = 1; i <= m && vt.empty() == false; i++)
	{
		while (pos[i].size() < ans && vt.empty() == false)
		{
			dat[vt.back()] = i;
			pos[i].push_back(vt.back());
			vt.pop_back();
			ans2++;
		}
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == j) continue;
			while (pos[i].size() < ans && pos[j].size() > ans)
			{
				dat[pos[j].back()] = i;
				pos[i].push_back(pos[j].back());
				pos[j].pop_back();
				ans2++;
			}
		}
	}

	printf("%d %d\n", ans, ans2);
	for (int i = 0; i < n; i++) printf("%d ", dat[i]);
}