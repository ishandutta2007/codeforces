#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
#define mp make_pair

pii a[5];

int solve()
{
	sort(a, a + 3);
	if (a[0].first == a[1].first && a[1].first == a[2].first) return 1;
	if (a[0].first == a[1].first)
	{
		if (a[0].second < a[2].second && a[2].second < a[1].second) return 3;
		return 2;
	}
	if (a[1].first == a[2].first)
	{
		if (a[1].second < a[0].second && a[0].second < a[2].second) return 3;
		return 2;
	}
	return 3;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < 3; i++)
		scanf("%d%d", &a[i].first, &a[i].second);
	int ans = solve();
	for (int i = 0; i < 3; i++)
		swap(a[i].first, a[i].second);
	ans = min(ans, solve());
	printf("%d\n", ans);

	return 0;
}