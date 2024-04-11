/***
5 2 1
100 100 100 100 100
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, k, x;
	cin >> n >> k >> x;
	int a[n];
	for (int i = n - 1; i >= 0; i--)
		cin >> a[i];
	int ans = 0;
	for (int i = 0; i < k; i++)
		ans += x;
	for (int i = k; i < n; i++)
		ans += a[i];
	cout << ans;
}