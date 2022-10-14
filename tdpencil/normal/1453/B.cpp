#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int MAX_N = 200000;
int a[MAX_N + 5];
 
void solve()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
 
	ll ans = 0;
	for (int i = 2; i <= n; i++)
		ans += abs(a[i] - a[i - 1]);
 
	int mx = max(abs(a[1] - a[2]), abs(a[n] - a[n - 1]));
	for (int i = 2; i < n; i++)
		mx = max(mx, abs(a[i] - a[i - 1]) + abs(a[i + 1] - a[i]) - abs(a[i + 1] - a[i - 1]));
 
	cout << ans - mx << '\n';
}
 
int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
}