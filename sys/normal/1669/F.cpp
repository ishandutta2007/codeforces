#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, w1, w2, ans, a[Maxn], cnt1[Maxn], cnt2[Maxn];
string str;
map <int, int> Ma;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		Ma.clear();
		ans = w1 = w2 = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), cnt1[i] = cnt2[i] = 0;
		for (int i = 1; i <= n; i++)
			w1 += a[i], Ma[w1] = i;
		for (int i = n; i >= 1; i--)
		{
			w2 += a[i];
			if (Ma[w2] && 2ll * w2 <= w1) ans = max(ans, Ma[w2] + n - i + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}