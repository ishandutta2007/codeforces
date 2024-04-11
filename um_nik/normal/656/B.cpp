#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int gcd(int x, int y)
{
	return (y == 0 ? x : gcd(y, x % y));
}
int lcm(int x, int y)
{
	return x * (y / gcd(x, y));
}

const int N = (int)1e6;
bool a[N];
int b[N], c[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int x = 1;
	for (int i = 1; i <= 16; i++)
		x = lcm(x, i);
//	printf("%d\n", x);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < n; i++)
	{
		int y;
		scanf("%d", &y);
		for (int j = 0; j < x; j++)
			if (j % b[i] == y)
				a[j] = 1;
	}
	int cnt = 0;
	for (int i = 0; i < x; i++)
		if (a[i])
			cnt++;
	printf("%.12lf\n", (double)cnt / x);

	return 0;
}