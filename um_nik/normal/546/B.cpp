#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 3030;
int n;
int a[N];
int ans;
int x;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	x = a[0];
	ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] > x)
		{
			x = a[i];
			continue;
		}
		x++;
		ans += x - a[i];
	}
	printf("%d\n", ans);

	return 0;
}