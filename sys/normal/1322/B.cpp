#include <bits/stdc++.h>
using namespace std;

const int Maxn = 400005;
int n, a[Maxn], ans;
bool sum[20000005];
int lowbit(int x)
{
	return x & -x;
}
void add(int x)
{
	x++;
	for (int i = x; i <= 20000001; i += lowbit(i))
		sum[i] ^= 1;
}
bool ask(int x)
{
	x++;
	x = min(x, 20000001);
	x = max(x, 0);
	bool tmp = false;
	for (int i = x; i; i -= lowbit(i))
		tmp ^= sum[i];
	return tmp;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 30; i > 0; i--)
	{
		memset(sum, 0, sizeof(sum));
		bool now = false;
		for (int j = 1; j <= n; j++)
		{
			now ^= ask(((1 << i) - 1) - (a[j] & ((1 << i) - 1))) ^ ask((1 << (i - 1)) - (a[j] & ((1 << i) - 1)) - 1);
			now ^= ask(((1 << (i + 1)) - 1) - (a[j] & ((1 << i) - 1))) ^ ask((1 << (i - 1)) + (1 << i) - (a[j] & ((1 << i) - 1)) - 1);
			add(a[j] & ((1 << i) - 1));
		}
		ans ^= now << (i - 1);
	}
	printf("%d", ans);
	return 0;
}