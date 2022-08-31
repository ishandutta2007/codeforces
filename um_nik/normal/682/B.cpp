#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 100100;
int n;
int a[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= ans) ans++;
	}
	printf("%d\n", ans);

	return 0;
}