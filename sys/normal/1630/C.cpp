#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, ct, ans, a[Maxn], las[Maxn], pre[Maxn], f[Maxn];
set <int> Se;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		if (!pre[a[i]]) pre[a[i]] = i;
	for (int i = n; i >= 1; i--)
		if (!las[a[i]]) las[a[i]] = i;
	for (int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1];
		if ((i != pre[a[i]] && i != las[a[i]]) || (pre[a[i]] == las[a[i]])) continue;
		else if (i == pre[a[i]]) Se.insert(i), f[i] = max(f[i], f[*Se.begin()] - *Se.begin() + i - 1);
		else if (i == las[a[i]]) f[i] = max(f[i], f[pre[a[i]]] + (las[a[i]] - pre[a[i]] - 1)), Se.erase(pre[a[i]]);
	}
	printf("%d", f[n]);
	return 0;
}