#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, ans, a[8], b[Maxn], ind[Maxn];
set <pair <int, int> > Se;
set <int> Se2;
int main()
{
	for (int i = 1; i <= 6; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + 6);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]), Se.insert(make_pair(b[i] - a[1], i)), ind[i] = 1;
	ans = Se.rbegin() -> first - Se.begin() -> first;
	for (int i = 1; i <= 5 * n; i++)
	{
		A:int u = Se.rbegin() -> second;
		Se.erase(*Se.rbegin());
		if (ind[u] == 6)
		{
			Se2.insert(b[u] - a[6]);
			goto A;
		}
		Se.insert(make_pair(b[u] - a[++ind[u]], u));
		if (Se2.size()) ans = min(ans, max(*Se2.rbegin(), Se.rbegin() -> first) - min(*Se2.begin(), Se.begin() -> first));
		else ans = min(ans, Se.rbegin() -> first - Se.begin() -> first);
	}
	printf("%d", ans);
	return 0;
}