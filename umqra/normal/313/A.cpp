#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int a;
	cin >> a;
	if (a >= 0)
		cout << a;
	else
	{
		int b = (a / 100) * 10 + a % 10;
		int c = a / 10;
		cout << max(b, c);
	}

	return 0;
}