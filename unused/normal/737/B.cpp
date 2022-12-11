#include "bits/stdc++.h"
using namespace std;

char dat[200005];
vector<pair<int, int>> vt;

int main()
{

	int n, a, b, k;
	scanf("%d%d%d%d%s", &n, &a, &b, &k, dat);

	int total = 0;

	for (char * p = strtok(dat,"1"); p; p = strtok(nullptr, "1"))
	{
		vt.emplace_back(strlen(p), p - dat + 1);
		total += vt.back().first / b;
	}

	vector<int> pick;

	for (auto &&e : vt)
	{
		for (int i = 0; i < e.first / b; i++)
		{
			pick.push_back(e.second + b * i + b - 1);
			if (total - pick.size() < a)
			{
				printf("%d\n", (int)pick.size());
				for (auto t : pick) printf("%d ", t);
				return 0;
			}
		}
	}
}