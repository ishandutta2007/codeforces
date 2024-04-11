#include <bits/stdc++.h>
using namespace std;
int n, k, q, l, r;
int a[200020];
int main()
{
	cin >> n >> k >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> l >> r;
		a[l] += 1;
		a[r + 1] -= 1;
	}
	for (int i = 1; i <= 200000; i++)
	{
		a[i] += a[i - 1];
	}
	for (int i = 1; i <= 200000; i++)
	{
		a[i] = a[i - 1] + (a[i] >= k);
	}
	for (int i = 0; i < q; i++)
	{
		cin >> l >> r;
		cout << a[r] - a[l - 1] << endl;
	}
	return 0;
}