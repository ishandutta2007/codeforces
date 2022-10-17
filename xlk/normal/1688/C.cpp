#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		char z = 0;
		cin >> n;
		for (int i = 0; i <= 2 * n; i++)
		{
			cin >> s;
			for (char c : s)
			{
				z ^= c;
			}
		}
		cout << z << endl;
	}
	return 0;
}