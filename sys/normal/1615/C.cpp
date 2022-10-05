#include <bits/stdc++.h>
using namespace std;

int T, n, ans;
string A, B;
int even(void)
{
	int res = 0;
	for (int i = 0; i < n; i++)
		if (A[i] != B[i]) res++;
	if (res % 2) return 0x3f3f3f3f;
	return res;
}
int odd(void)
{
	int res = 0;
	for (int i = 0; i < n; i++)
		if (A[i] == B[i]) res++;
	if (res % 2 == 0) return 0x3f3f3f3f;
	return res;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ans = 0x3f3f3f3f;
		int totA0 = 0, totA1 = 0, totB0 = 0, totB1 = 0;
		scanf("%d", &n);
		cin >> A >> B;
		for (int i = 0; i < n; i++)
		{
			totA0 += A[i] == '0', totA1 += A[i] == '1';
			totB0 += B[i] == '0', totB1 += B[i] == '1';
		}
		if (totA1 == totB1)
			ans = min(ans, even());
		if (totA1 - 1 == totB0)
			ans = min(ans, odd());
		printf("%d\n", ans == 0x3f3f3f3f ? -1 : ans);
	}
	return 0;
}