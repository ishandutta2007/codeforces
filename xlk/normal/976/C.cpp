#include <bits/stdc++.h>
using namespace std;
struct N
{
	int l, r, i;
} a[300020];
bool operator<(const N&a, const N&b)
{
	if (a.l != b.l)
	{
		return a.l < b.l;
	}
	return a.r > b.r;
}
int n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].l >> a[i].r;
		a[i].i = i + 1;
	}
	sort(a, a + n);
	for (int i = 1; i < n ; i++)
	{
		if (a[i-1].r >= a[i].r)
		{
			cout << a[i].i << " " << a[i-1].i << endl;
			return 0;
		}
	}
	cout << "-1 -1" << endl;
	return 0;
}