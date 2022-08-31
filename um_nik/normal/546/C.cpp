#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int M = (int)25e6 - 30;
const int N = (int)25e6;
int a[N], b[N];
int l1, r1, l2, r2;
int ans;

int main()
{
	scanf("%d%d", &r1, &r1);
	for (int i = 0; i < r1; i++)
		scanf("%d", &a[i]);
	scanf("%d", &r2);
	for (int i = 0; i < r2; i++)
		scanf("%d", &b[i]);
	l1 = l2 = 0;
	while(ans < M)
	{
		if (l1 == r1)
		{
			printf("%d 2\n", ans);
			return 0;
		}
		if (l2 == r2)
		{
			printf("%d 1\n", ans);
			return 0;
		}
		if (a[l1] < b[l2])
		{
			b[r2++] = a[l1];
			b[r2++] = b[l2];
		}
		else
		{
			a[r1++] = b[l2];
			a[r1++] = a[l1];
		}
		l1++;
		l2++;
		ans++;
	}
	printf("-1\n");

	return 0;
}