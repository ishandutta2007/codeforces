#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
int T, n, k;
int x[maxn];

void solve()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}
	sort(x, x + n);
	vector<int> low, up;
	for (int i = 0; i < n; i++)
	{
		if (x[i] <= 0)
			low.push_back(-x[i]);
		else 
			up.push_back(x[i]);
	}
	reverse(up.begin(), up.end());
	long long ans = 0;
	for (int i = 0; i < low.size(); i += k)
	{
		ans += 2 * low[i];
	}
	for (int i = 0; i < up.size(); i += k)
	{
		ans += 2 * up[i];
	}
	int mx = 0;
	if (!low.empty())
		mx = max(mx, low[0]);
	if (!up.empty())
		mx = max(mx, up[0]);
	printf("%lld\n", ans - mx);
}

int main()
{
	scanf("%d", &T);
	while (T--) 
	{
		solve();
	}
}