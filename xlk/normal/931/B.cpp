#include <bits/stdc++.h>
using namespace std;
int n, a, b, z;
int main()
{
	cin >> n >> a >> b;
	a--;
	b--;
	while (a != b)
	{
		a /= 2;
		b /= 2;
		n /= 2;
		z++;
	}
	if (n == 1)
	{
		cout << "Final!" << endl;
	}
	else
	{
		cout << z << endl;
	}
	return 0;
}