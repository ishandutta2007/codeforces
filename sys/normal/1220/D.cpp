#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, cnt[70], pnt, ct[Maxn];
long long b[Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &b[i]);
		long long tmp = b[i];
		while (tmp % 2 == 0) tmp >>= 1, ct[i]++;
		cnt[ct[i]]++;
	}
	for (int i = 1; i <= 63; i++)
		if (cnt[i] > cnt[pnt]) pnt = i;
	printf("%d\n", n - cnt[pnt]);
	for (int i = 1; i <= n; i++)
		if (ct[i] != pnt) printf("%lld\n", b[i]);
	return 0;
}