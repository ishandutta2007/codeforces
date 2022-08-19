#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

int n;
ll m;
int a[100];
int l, r;

int main()
{
	cin >> n >> m;
	m--;
	l = 0;
	r = n - 1;
	for (int i = 1; i <= n; i++)
	{
		ll x = (i == n ? 0 : 1LL << (n - i - 1));
		if (x <= m)
		{
			a[r--] = i;
			m -= x;
		}
		else
			a[l++] = i;
	}
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}