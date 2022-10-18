#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

typedef pair<int, int> PII;

const int MaxN = 300000;

int main()
{
	int n;
	static PII a[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i].first), a[i].second = i;

	sort(a + 1, a + n + 1);

	int cur = -1;
	static int res[MaxN + 1];

	for (int i = 1, j = 1; i <= n; i = j)
	{
		if (cur < a[i].first)
			cur = a[i].first;
		while (j <= n && a[i].first == a[j].first)
		{
			res[a[j].second] = cur++;
			j++;
		}
	}

	for (int i = 1; i <= n; i++)
		printf("%d ", res[i]);
	cout << endl;

	return 0;
}