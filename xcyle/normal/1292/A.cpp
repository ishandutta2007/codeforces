#include <iostream>
#include <cstdio>
#define maxn 100005
using namespace std;
int n, q, a[2][maxn], cnt1, cnt2, r, c;
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d", &r, &c);
		r--;
		if(a[r][c] == 0)
		{
			a[r][c] = 1;
			cnt2 += a[r ^ 1][c - 1] + a[r ^ 1][c + 1];
			cnt1 += a[r ^ 1][c];
		}
		else
		{
			a[r][c] = 0;
			cnt2 -= a[r ^ 1][c - 1] + a[r ^ 1][c + 1];
			cnt1 -= a[r ^ 1][c];
		}
		if(cnt1 == 0 && cnt2 == 0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}