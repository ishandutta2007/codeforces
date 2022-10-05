#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, a[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		bool flag11 = false, flag12 = false, flag21 = false, flag22 = false;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i += 2)
			if (a[i] & 1) flag11 = true;
			else flag12 = true;
		for (int i = 2; i <= n; i += 2)
			if (a[i] & 1) flag21 = true;
			else flag22 = true;
		puts(((flag11 && flag12) || (flag21 && flag22)) ? "NO" : "YES");
	}
	return 0;
}