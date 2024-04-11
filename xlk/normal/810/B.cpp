#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int a[100020];
long long z;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		z += min(x, y);
		a[i] = min(2 * x, y) - min(x, y);
	}
	sort(a, a + n);
	for (int i = n - m; i < n; i++)
	{
		z += a[i];
	}
	cout << z << endl;
	return 0;
}