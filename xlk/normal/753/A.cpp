#include <bits/stdc++.h>
using namespace std;
int n;
int a[100], c;
int main()
{
	cin >> n;
	for (c = 0; c + 1 <= n;)
	{
		c++;
		a[c] = c;
		n -= c;
	}
	a[c] += n;
	cout << c << endl;
	for (int i = 1; i <= c; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}