#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 1010;
int n;
int k;
int y;
int s;
int p;
int a[N];
int cnt;

int main()
{
	scanf("%d%d%d%d%d", &n, &k, &p, &s, &y);
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &a[i]);
		s -= a[i];
	}
	s -= n - k;
	if (s < 0)
	{
		printf("-1\n");
		return 0;
	}
	while(k + cnt < n && s >= y - 1)
	{
		a[k + cnt] = y;
		cnt++;
		s -= y - 1;
	}
	for (int i = k + cnt; i < n; i++)
		a[i] = 1;
	sort(a, a + n);
	if (a[n / 2] < y)
	{
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < cnt; i++)
		printf("%d ", y);
	for (int i = 0; i < n - k - cnt; i++)
		printf("1 ");
	printf("\n");

	return 0;
}