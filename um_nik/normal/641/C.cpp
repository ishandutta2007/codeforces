#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int a, b;
int n, q;
const int N = (int)2e6 + 100;
int p[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	a = 0;
	b = 1;
	while(q--)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			int x;
			scanf("%d", &x);
			a = (a + n + x) % n;
			b = (b + n + x) % n;
		}
		else
		{
			if (a & 1)
			{
				a--;
				b++;
			}
			else
			{
				a++;
				b--;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			p[(a + i) % n] = i;
		else
			p[(b + i - 1) % n] = i;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", p[i] + 1);
	printf("\n");

	return 0;
}