#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, m;
const int INF = (int)1e7;

bool check(int r)
{
	int x = r / 2;
	int y = r / 3;
	int z = r / 6;
	x -= z;
	y -= z;
	return max(0, n - x) + max(0, m - y) <= z;
}

int main()
{
	scanf("%d%d", &n, &m);
	int l = 0, r = INF;
	while(r - l > 1)
	{
		int x = (l + r) / 2;
		if (check(x))
			r = x;
		else
			l = x;
	}
	printf("%d\n", r);

	return 0;
}