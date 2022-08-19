#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 111;
int n;
int a[N], b[N];

int solve(int x1, int y1, int x2, int y2)
{
	x1 *= 2;
	y1 *= 2;
	x2 *= 2;
	y2 *= 2;
	x1++;
	if (x1 > x2 && (x1 + y1) < (x2 + y2)) return 1;
	if (x1 < x2 && (x1 + y1) > (x2 + y2)) return 1;
	if (x1 > x2 && (x1 + y1) < x2) return 2;
	if (x1 > x2 && x1 < (x2 + y2)) return 2;
	if (x1 < x2 && (x1 + y1) > x2) return 2;
	if (x1 < x2 && x1 > (x2 + y2)) return 2;
	return 0;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i], &b[i]);
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			ans += solve(a[i], b[i], a[j], b[j]);
	printf("%d\n", ans);

	return 0;
}