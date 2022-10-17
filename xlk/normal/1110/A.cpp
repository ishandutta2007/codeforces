#include <bits/stdc++.h>
using namespace std;
int b, n, x, s;
int main()
{
	cin >> b >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s += x;
	}
	if (b & 1)
	{
		x = s;
	}
	cout << (x & 1 ? "odd" : "even") << endl;
	return 0;
}