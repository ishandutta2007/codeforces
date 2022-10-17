#include <bits/stdc++.h>
using namespace std;
int n, q, l, r;
string s;
int a[100020];
int main()
{
	cin >> n >> q >> s;
	for (int i = 0; i < n; i++)
	{
		a[i + 1] = a[i] + (s[i] - 96);
	}
	for (int i = 0; i < q; i++)
	{
		cin >> l >> r;
		cout << a[r] - a[l - 1] << endl;
	}
	return 0;
}