#include <bits/stdc++.h>
using namespace std;
int n, q, x, y;
long long p[200020];
int main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}
	sort(p + 1, p + n + 1, greater<long long>());
	for (int i = 1; i <= n; i++)
	{
		p[i] += p[i - 1];
	}
	for (int i = 0; i < q; i++)
	{
		cin >> x >> y;
		cout << p[x] - p[x - y] << endl;
	}
	return 0;
}