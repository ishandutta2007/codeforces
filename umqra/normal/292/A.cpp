#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	int ansT;
	int lastT = 0;
	int maxCnt = 0;
	int curCnt = 0;
	for (int i = 0; i < n; i++)
	{
		int t, c;
		scanf("%d%d", &t, &c);
		curCnt = max(0, curCnt - (t - lastT)) + c;
		maxCnt = max(maxCnt, curCnt);
		lastT = t;
		if (i == n - 1)
			ansT = t + curCnt;
	}

	printf("%d %d", ansT, maxCnt);

	return 0;
}