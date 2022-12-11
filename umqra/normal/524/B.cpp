#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 1010;
int n;
int a[N], b[N];
int ans = (int)1e9;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
		if (a[i] > b[i])
			swap(a[i], b[i]);
	}
	for (int H = 1; H < N; H++)
	{
		bool ok = true;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > H)
			{
				ok = false;
				break;
			}
			if (b[i] <= H)
				sum += a[i];
			else
				sum += b[i];
		}
		if (ok)
			ans = min(ans, H * sum);
	}
	printf("%d\n", ans);


	return 0;
}