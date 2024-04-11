#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, a[Maxn];
set <int> Se;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		bool flag = false;
		Se.clear();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), Se.insert(a[i]);
		for (int i = 1; i <= n; i++)
			if (Se.find(a[i] + 1) != Se.end()) flag = true;
		puts((Se.find(1) != Se.end() && flag) ? "NO" : "YES");
	}
	return 0;
}