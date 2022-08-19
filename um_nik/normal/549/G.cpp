#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 200200;
int n;
int a[N];

int main()
{
	scanf("%d", &n);
	for (int i = n - 1; i >= 0; i--)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		a[i] -= i;
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < n; i++)
		a[i] += i;
	bool ok = true;
	for (int i = 0; i < n - 1; i++)
		ok &= a[i] >= a[i + 1];
	if (!ok)
	{
		printf(":(\n");
		return 0;
	}
	reverse(a, a + n);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}