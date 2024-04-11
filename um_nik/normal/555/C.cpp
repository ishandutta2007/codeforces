#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

const int N = 200200;
int n, q;
int a[N][4];
set<int> xs;
map<int, int> getIdx;

int main()
{
//	freopen("input.txt", "r", stdin);

	scanf("%d%d", &n, &q);
	q += 2;
	a[0][0] = 0;
	a[0][1] = 1;
	a[0][2] = n + 1;
	xs.insert(0);
	getIdx[0] = 0;
	a[1][0] = n + 1;
	a[1][1] = 1;
	a[1][2] = 0;
	xs.insert(n + 1);
	getIdx[n + 1] = 1;
	for (int i = 2; i < q; i++)
	{
		int x, y;
		char t;
		scanf("%d %d %c", &x, &y, &t);
		a[i][0] = x;
		if (t == 'U')
			a[i][1] = 1;

		if (xs.find(x) != xs.end())
		{
			a[i][2] = 0;
			printf("0\n");
			continue;
		}
		auto it = xs.lower_bound(x);
		if (a[i][1] == 0)
			it--;
		y = *it;
		int c = getIdx[y];
		if (a[i][1] == a[c][1])
		{
			a[i][2] = a[c][2] + abs(x - y);
		}
		else
		{
			a[i][2] = abs(x - y);
		}

		xs.insert(x);
		getIdx[x] = i;
		printf("%d\n", a[i][2]);
	}


	return 0;
}