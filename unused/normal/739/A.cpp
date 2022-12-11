#include "bits/stdc++.h"
using namespace std;

pair<int, int> dat[100005];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int minlen = 2e9;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &dat[i].first, &dat[i].second);
		minlen = min(minlen, dat[i].second - dat[i].first + 1);
	}
	printf("%d\n", minlen);
	for (int i = 0; i < n; i++) printf("%d ", i % minlen);
}