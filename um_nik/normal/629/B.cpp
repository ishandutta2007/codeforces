#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 5050;
const int A = 400;
int ans;

int l[N], r[N];
char c[N];
int n;

int solve(int x)
{
	int a = 0, b = 0;
	for (int i = 0; i < n; i++)
	{
		if (x < l[i] || x > r[i]) continue;
		if (c[i] == 'M')
			a++;
		else
			b++;
	}
	return min(a, b);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf(" %c %d %d", &c[i], &l[i], &r[i]);
	ans = 0;
	for (int i = 0; i < A; i++)
		ans = max(ans, 2 * solve(i));
	printf("%d\n", ans);

	return 0;
}