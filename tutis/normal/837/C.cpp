/***
2 2 2
1 2
2 1
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, a, b;
	cin >> n >> a >> b;
	int x[n], y[n];
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			if (x[i] <= a && y[i] <= b && ((x[j] <= a - x[i] && y[j] <= b) || (x[j] <= a && y[j] <= b - y[i])))
				ans = max(ans, x[i] * y[i] + x[j] * y[j]);
			swap(x[j], y[j]);
			if (x[i] <= a && y[i] <= b && ((x[j] <= a - x[i] && y[j] <= b) || (x[j] <= a && y[j] <= b - y[i])))
				ans = max(ans, x[i] * y[i] + x[j] * y[j]);

			swap(x[i], y[i]);
			if (x[i] <= a && y[i] <= b && ((x[j] <= a - x[i] && y[j] <= b) || (x[j] <= a && y[j] <= b - y[i])))
				ans = max(ans, x[i] * y[i] + x[j] * y[j]);

			swap(x[j], y[j]);
			if (x[i] <= a && y[i] <= b && ((x[j] <= a - x[i] && y[j] <= b) || (x[j] <= a && y[j] <= b - y[i])))
				ans = max(ans, x[i] * y[i] + x[j] * y[j]);
		}
	cout << ans;
}