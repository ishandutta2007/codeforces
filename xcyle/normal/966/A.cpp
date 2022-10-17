#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 100010
using namespace std;
const int INF = 5e8;
int n, m, cnt1, cnt2, v, q;
int xa, ya, xb, yb, ans1, ans2;
int a[maxn], b[maxn];
inline int Abs(int x)
{
	return x > 0 ? x : -x;
}
int main()
{
	scanf("%d%d%d%d%d", &n, &m, &cnt1, &cnt2, &v);
	for (int i = 1; i <= cnt1; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= cnt2; i++) scanf("%d", &b[i]);
	sort(a + 1, a + cnt1 + 1);
	a[0] = -INF, a[cnt1 + 1] = INF;
	sort(b + 1, b + cnt2 + 1);
	b[0] = -INF, b[cnt2 + 1] = INF;
	cnt1++, cnt2++;
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d%d%d%d", &ya, &xa, &yb, &xb);
		if(ya == yb)
		{
			printf("%d\n", Abs(xa - xb));
			continue;
		}
		int loc1 = lower_bound(a + 1, a + cnt1 + 1, xa) - a;
		int loc2 = lower_bound(b + 1, b + cnt2 + 1, xa) - b;
		ans1 = min(Abs(a[loc1] - xa) + Abs(a[loc1] - xb), Abs(a[loc1 - 1] - xa) + Abs(a[loc1 - 1] - xb)) + Abs(yb - ya);
		ans2 = min(Abs(b[loc2] - xa) + Abs(b[loc2] - xb), Abs(b[loc2 - 1] - xa) + Abs(b[loc2 - 1] - xb)) + (Abs(yb - ya) + v - 1) / v;
		printf("%d\n", min(ans1, ans2));
	}
	return 0;
}