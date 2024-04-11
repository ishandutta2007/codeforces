#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = (int)5e6 + 200;
int p[N];
int d[N];

int main()
{
	for (int x = 2; x < N; x++)
	{
		if (p[x] != 0) continue;
		for (int y = x; y < N; y += x)
			if (p[y] == 0)
				p[y] = x;
	}
	d[1] = 0;
	for (int x = 2; x < N; x++)
		d[x] = 1 + d[x / p[x]];
	for (int x = 2; x < N; x++)
		d[x] += d[x - 1];

	int t;
	scanf("%d", &t);
	while(t--)
	{
		int l, r;
		scanf("%d%d", &r, &l);
		printf("%d\n", d[r] - d[l]);
	}

	return 0;
}