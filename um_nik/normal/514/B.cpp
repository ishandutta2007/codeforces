#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 1010;
int n;
int xx, yy;
set<pii> a;

int gcd(int x, int y)
{
	return (y == 0 ? x : gcd(y, x % y));
}

void getNext()
{
	int x, y;
	scanf("%d%d", &x, &y);
	x -= xx;
	y -= yy;
	if (y < 0)
	{
		x *= -1;
		y *= -1;
	}
	if (y == 0 && x < 0)
	{
		x *= -1;
	}
	int g = gcd(abs(x), abs(y));
	x /= g;
	y /= g;
	a.insert(mp(x, y));
	return;
}

int main()
{
	scanf("%d%d%d", &n, &xx, &yy);
	for (int i = 0; i < n; i++)
		getNext();
	printf("%d\n", (int)a.size());

	return 0;
}