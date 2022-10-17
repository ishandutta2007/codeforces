#include <bits/stdc++.h>
using namespace std;
int n;
string a, b;
int main()
{
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++)
	{
		a[i] -= 'a';
		b[i] -= 'a';
		a[i] += b[i];
	}
	for (int i = n - 1; i > 0; i--)
	{
		a[i - 1] += a[i] / 26;
		a[i] %= 26;
	}
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		c = c * 26 + a[i];
		a[i] = c / 2 + 'a';
		c %= 2;
	}
	cout << a << endl;
	return 0;
}