#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, shift, a[Maxn];
map <int, int> f, g;
multiset <int> f_val, g_val;
int main()
{
	f_val.insert(0), g_val.insert(0);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		f[i] = g[i] = 0x3f3f3f3f, f_val.insert(0x3f3f3f3f), g_val.insert(0x3f3f3f3f);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		int tmp1 = min(*f_val.begin() + 1, f[a[i]]), tmp2 = min(*g_val.begin() + 1, g[a[i]]);
		g_val.erase(g_val.find(g[a[i - 1]]));
		g[a[i - 1]] = tmp1 - (a[i] != a[i - 1]);
		g_val.insert(g[a[i - 1]]);
		f_val.erase(f_val.find(f[a[i - 1]]));
		f[a[i - 1]] = tmp2 - (a[i] != a[i - 1]);
		f_val.insert(f[a[i - 1]]);
		shift += (a[i] != a[i - 1]);
	}
	printf("%d", shift + min(*f_val.begin(), *g_val.begin()));
	return 0;
}