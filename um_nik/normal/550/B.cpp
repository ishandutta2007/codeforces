#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 20;
int n;
int l, r;
int d;
int a[N];
int ans;

bool check(int mask)
{
	int k = 0;
	for (int i = 0; i < n; i++)
		if ((mask >> i) & 1)
			k++;
	if (k < 2) return false;
	int sum = 0;
	int m1 = (int)1e8;
	int m2 = -1;
	for (int i = 0; i < n; i++)
	{
		if (((mask >> i) & 1) == 0) continue;
		sum += a[i];
		m1 = min(m1, a[i]);
		m2 = max(m2, a[i]);
	}
	return !(sum < l || sum > r || m2 - m1 < d);
}

int main()
{
	scanf("%d%d%d%d", &n, &l, &r, &d);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	ans = 0;
	for (int mask = 1; mask < (1 << n); mask++)
		ans += (int)check(mask);
	printf("%d\n", ans);

	return 0;
}