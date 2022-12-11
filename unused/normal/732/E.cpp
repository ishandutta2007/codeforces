#include "bits/stdc++.h"
using namespace std;

unordered_map<int, vector<int>> powers;
pair<int,int> skts[200005];
int ans[200005];
int ans2[200005];

int main()
{
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d",&tmp);
		powers[tmp].push_back(i);
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d",&skts[i].first);
		skts[i].second = i + 1;
	}

	sort(skts,skts+m);
	int total = 0;
	int ans3 = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = skts[i].first, sock = 0; j >= 1;
				j = (j + 1) >> 1, sock++)
		{
			auto itr = powers.find(j);
			if (itr != powers.end())
			{
				ans[itr->second.back()] = skts[i].second;
				itr->second.pop_back();
				if (itr->second.empty()) powers.erase(itr);
				total += sock;
				ans2[skts[i].second] = sock;
				ans3++;
				break;
			}

			if (j == 1) break;
		}
	}

	printf("%d %d\n", ans3, total);
	for (int i = 1; i <= m; i++) printf("%d ", ans2[i]);
	printf("\n");
	for (int i = 0 ; i < n; i++) printf("%d ", ans[i]); 
}