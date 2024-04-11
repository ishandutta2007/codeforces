#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair
#define X first
#define Y second

const int N = (int)2e5 + 100;
int n, q;
int a[N];
pii b[N];
int c[N];
int p, l;
int dir;

void solve2()
{
	while(true)
	{
		int x = a[p] + l * dir;
		int s;
		if (dir == 1)
			s = upper_bound(a, a + n, x) - a - 1;
		else
			s = lower_bound(a, a + n, x) - a;
		if (p == s) return;
		int k = abs(a[s] - a[p]);
		int r = l / k;
		if (r & 1)
		{
			p = s;
			dir *= -1;
		}
		l %= k;
	}
}

void solve()
{
	scanf("%d%d", &p, &l);
	p = c[p];
	dir = 1;
	int x = a[p] + l;
	int s = upper_bound(a, a + n, x) - a - 1;
	l -= abs(a[s] - a[p]);
	p = s;
	dir *= -1;
	solve2();
	printf("%d\n", b[p].Y);
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		b[i] = mp(a[i], i + 1);
	sort(b, b + n);
	for (int i = 0; i < n; i++)
		c[b[i].Y] = i;
	for (int i = 0; i < n; i++)
		a[i] = b[i].X;
	while(q--)
		solve();

	return 0;
}