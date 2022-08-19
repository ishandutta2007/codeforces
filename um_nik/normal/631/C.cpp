#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 200200;
int a[N];
int st[N][2];
int n, m;
int k;
int b[N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	k = 0;
	while(m--)
	{
		int t, x;
		scanf("%d%d", &t, &x);
		while(k > 0 && st[k - 1][0] <= x) k--;
		if (k > 0 && st[k - 1][1] == t) continue;
		st[k][0] = x;
		st[k][1] = t;
		k++;
	}
	st[k][0] = 0;
	st[k][1] = 1;
	for (int i = 0; i < st[0][0]; i++)
		b[i] = a[i];
	sort(b, b + st[0][0]);
	int l = 0, r = st[0][0];
	int p = r;
	for (int i = 0; i < k; i++)
	{
		while(p > st[i + 1][0])
		{
			p--;
			if (st[i][1] == 1)
				a[p] = b[--r];
			else
				a[p] = b[l++];
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}