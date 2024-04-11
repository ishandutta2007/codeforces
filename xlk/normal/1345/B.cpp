#include <bits/stdc++.h>
using namespace std;
int F(int x)
{
	return (3 * x * x + x) / 2;
}
int main()
{
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		int n, c = 0;
		cin >> n;
		for (int i = 25820; i > 0; i--)
		{
			while (n >= F(i))
			{
				n -= F(i);
				c++;
			}
		}
		cout << c << endl;
	}
	return 0;
}