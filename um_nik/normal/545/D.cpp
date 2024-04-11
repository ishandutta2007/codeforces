#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 100100;
int n;
int a[N];
int ans;
int sum;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	sum = ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < sum) continue;
		sum += a[i];
		ans++;
	}
	printf("%d\n", ans);

	return 0;
}