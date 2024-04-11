#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> a;
int ans1, ans2;
int ans;
const int N = 200200;
int b[N], c[N];

int main()
{
	int n, m;
	scanf("%d", &n);
	ans = ans1 = ans2 = -1;
	while(n--)
	{
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &c[i]);
	for (int i = 0; i < m; i++)
	{
		int x = a[b[i]], y = a[c[i]];
		if (x > ans1 || (x == ans1 && y > ans2))
		{
			ans = i + 1;
			ans1 = x;
			ans2 = y;
		}
	}
	printf("%d\n", ans);

	return 0;
}