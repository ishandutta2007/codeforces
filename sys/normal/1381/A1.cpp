#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int T, ct, n, L, R, ans[2 * Maxn], A[Maxn], B[Maxn];
bool tag;
int ask(int x)
{
	if (L <= R) return A[L + x - 1] ^ tag;
	else return A[L - x + 1] ^ tag;
}
void dec(void)
{
	if (L <= R) L++;
	else L--;
	swap(L, R);
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ct = tag = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%1d", &A[i]);
		for (int i = 1; i <= n; i++)
			scanf("%1d", &B[i]);
		L = 1, R = n;
		for (int i = n; i >= 1; i--)
		{
			if (ask(i) == B[i])
			{
				if (L <= R) R--;
				else R++;
				continue;
			}
			if (ask(1) == B[i]) ans[++ct] = 1, A[L] ^= 1;
			ans[++ct] = i;
			tag ^= 1;
			dec();
		}
		printf("%d ", ct);
		for (int i = 1; i <= ct; i++)
			printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}