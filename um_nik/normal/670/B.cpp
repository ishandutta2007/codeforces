#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 100100;
int n, m;
int a[N];

int main()
{

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int k = 1; k <= n; k++)
	{
		if (m > k)
		{
			m -= k;
			continue;
		}
		printf("%d\n", a[m - 1]);
		return 0;
	}
	throw;

	return 0;
}