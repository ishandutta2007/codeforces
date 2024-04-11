#include <bits/stdc++.h>
using namespace std;

int n;
int y[1005];

bool line(int a, int b, int c)
{
	return (y[b] - y[a]) * 1ll * (c - b) == (y[c] - y[b]) * 1ll * (b - a);
}

void check(int a, int b)
{
	vector<int> noline;
	for (int i = 0; i < n; i++)
	{
		if (i == a || i == b) continue;
		if (line(a, b, i) == false) noline.push_back(i);
	}

	if (noline.empty()) return;
	if (noline.size() == 1)
	{
		printf("Yes\n");
		exit(0);
	}

	if ((y[b] - y[a]) * 1ll * (noline[1] - noline[0]) != (y[noline[1]] - y[noline[0]]) * 1ll * (b - a))
		return;

	for (int i = 2; i < noline.size(); i++)
	{
		if (line(noline[0], noline[1], noline[i]) == false) return;
	}

	printf("Yes\n");
	exit(0);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &y[i]);

	for (int i = 1; i < n; i++) check(0, i);
	check(1, 2);
	printf("No\n");
}