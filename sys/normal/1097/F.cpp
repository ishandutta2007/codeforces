#include <bits/stdc++.h>
using namespace std;

int n, q, cnt, prim[7005];
bool vis[7005], mu[7005];
bitset <7005> emp[7005], M[7005], W[100005];
void init(void)
{
	mu[1] = true;
	for (int i = 2; i <= 7000; i++)
	{
		if (!vis[i]) prim[++cnt] = i, mu[i] = true;
		for (int j = 1; j <= cnt && i * prim[j] <= 7000; j++)
		{
			vis[i * prim[j]] = true;
			if (i % prim[j] == 0) break;
			mu[i * prim[j]] = mu[i];
		}
	}
}
int main()
{
	scanf("%d%d", &n, &q);
	init();
	for (int i = 1; i <= 7000; i++)
		for (int j = i; j <= 7000; j += i)
		{
			emp[j].set(i);
			if (mu[j / i]) M[i].set(j);
		}
	while (q--)
	{
		int opt;
		scanf("%d", &opt);
		if (opt == 1)
		{
			int x, v;
			scanf("%d%d", &x, &v);
			W[x] = emp[v];
		}
		if (opt == 2)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			W[x] = W[y] ^ W[z];
		}
		if (opt == 3)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			W[x] = W[y] & W[z];
		}
		if (opt == 4)
		{
			int x, v;
			scanf("%d%d", &x, &v);
			putchar(((W[x] & M[v]).count() & 1) + '0');
		}
	}
	return 0;
}