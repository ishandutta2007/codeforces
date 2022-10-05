#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, a[7];
	scanf("%d", &n);
	int j = 0;
	while (n)
	{
		a[j++] = n % 10;
		n /= 10;
	}
	int ans = 0;
	for (int i = 0; i < j; i++)
		if (a[i] > ans)
			ans = a[i];
	printf("%d\n", ans);
	reverse(a, a + j);
	for (int i = 0; i < ans; i++)
	{
		int ans1 = 0;
		for (int k = 0; k < j; k++)
		{
			ans1 *= 10;
			if (a[k])
			{
				a[k]--;
				ans1 += 1;
			}
		}
		printf("%d ", ans1);
	}
	return 0;
}