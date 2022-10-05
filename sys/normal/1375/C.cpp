#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int T, n, done, a[Maxn], nxt[Maxn], las[Maxn];
struct cmp
{
	bool operator () (const int &x, const int &y) const
	{
		return a[x] < a[y];
	}
};
set <int, cmp> Se;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		Se.clear();
		done = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), Se.insert(i), nxt[i] = i + 1, las[i] = i - 1;
		while (done != n - 1)
		{
			int now = *Se.begin();
			if (nxt[now] == n + 1)
			{
				puts("No");
				goto END;
			}
			while (nxt[now] != n + 1)
			{
				Se.erase(now);
				nxt[las[now]] = nxt[now];
				las[nxt[now]] = las[now];
				now = nxt[now];
				done++;
			}
		}
		puts("Yes");
		END:;
	}
	return 0;
}