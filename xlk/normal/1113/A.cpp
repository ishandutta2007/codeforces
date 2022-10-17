#include <bits/stdc++.h>
using namespace std;
int n, v;
int main()
{
	cin >> n >> v;
	if (v >= n - 1)
	{
		cout << n - 1 << endl;
	}
	else
	{
		cout << v + (n - v + 2) * (n - v - 1) / 2 << endl;
	}
	return 0;
}