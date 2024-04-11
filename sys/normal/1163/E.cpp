#include <bits/stdc++.h>
using namespace std;
const int Maxn = 200005;
int n, hb, tot, val[30], ans[30], now[30], a[Maxn], b[Maxn];
void work(int x, int res)
{
    if(!x) return ;
    hb = log2(x);
    if (!val[hb]) val[hb] = x, now[hb] = res;
    else
        work(val[hb] ^ x, res);
}
void cal(int l, int r, int xx)
{
	int mid = (l + r) / 2;
	b[mid] = ans[xx];
	if (l == r) return ;
	cal(l, mid - 1, xx - 1), cal(mid + 1, r, xx - 1);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		work(a[i], a[i]);
		if ((int) log2(a[i]) != (int) log2(a[i + 1]))
		{
			int hb = log2(a[i]);
			bool flag = true;
			for (int j = 0; j < hb; j++)
				if (!val[j]) flag = false;
			if (flag)
				memcpy(ans, now, sizeof(ans)), tot = hb + 1;
		}
	}
	if (!tot)
	{
		printf("0\n0");
		return 0;
	}
	int maxi = 1 << tot;
	cal(1, maxi - 1, tot - 1);
	printf("%d\n", tot);
	for (int i = 1; i < maxi; i++)
		b[i] = b[i - 1] ^ b[i];
	for (int i = 0; i < maxi; i++)
		printf("%d ", b[i]);
	return 0;
}