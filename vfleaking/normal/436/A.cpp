#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 2000;

struct item
{
	int t, h, m;
};

int calc(int h, int n, item *a, int t)
{
	int res = 0;
	static bool book[MaxN];
	fill(book, book + n, false);
	while (true)
	{
		int p = -1;
		for (int i = 0; i < n; i++)
			if (!book[i] && a[i].t == t && a[i].h <= h && (p == -1 || a[i].m > a[p].m))
				p = i;
		if (p == -1)
			break;
		book[p] = true;
		h += a[p].m;
		t = !t;
		res++;
	}
	return res;
}

int main()
{
	int n, h0;
	static item a[MaxN];

	cin >> n >> h0;
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &a[i].t, &a[i].h, &a[i].m);

	cout << max(calc(h0, n, a, 0), calc(h0, n, a, 1)) << endl;

	return 0;
}