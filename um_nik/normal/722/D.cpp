#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;

const int N = 100100;
const int C = (int)1e9 + 2;
int n;
int a[N];
int b[N];
set<int> setik;

bool solve(int x)
{
	setik.clear();
	for (int i = 0; i < n; i++)
	{
		int y = a[i];
		while(y > 0 && (y > x || setik.count(y) > 0)) y >>= 1;
		if (y == 0) return false;
		b[i] = y;
		setik.insert(y);
	}
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int l = 0, r = C;
	while(r - l > 1)
	{
		int x = (l + r) / 2;
		if (solve(x))
			r = x;
		else
			l = x;
	}
	if (!solve(r)) throw;
	for (int i = 0; i < n; i++)
		printf("%d ", b[i]);
	printf("\n");

	return 0;
}