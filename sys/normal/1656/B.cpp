#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, k, a[Maxn];
set <int> Se;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		Se.clear();
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), Se.insert(a[i]);
		for (int i = 1; i <= n; i++)
			if (Se.find(a[i] + k) != Se.end())
			{
				puts("YES");
				goto END;
			}
		puts("NO");
		END:;
	}
	return 0;
}