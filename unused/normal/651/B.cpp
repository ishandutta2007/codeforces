#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vt;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		vt.push_back(tmp);
	}

	int ans = 0;
	for (;;)
	{
		vector<int> newvt;
		bool visited[1005] = {};
		int cnt = 0;
		for (int i = 0; i < vt.size(); i++)
		{
			if (visited[vt[i]] == false)
			{
				cnt++;
				visited[vt[i]] = true;
			}
		}
		if (cnt <= 1) break;
		ans += cnt - 1;
		for (int i = 0; i < vt.size(); i++)
		{
			if (visited[vt[i]]) visited[vt[i]] = false;
			else newvt.push_back(vt[i]);
		}

		vt = move(newvt);
	}
	printf("%d\n", ans);
}