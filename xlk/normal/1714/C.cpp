#include <bits/stdc++.h>
using namespace std;
int t, s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> s;
		string z;
		for (int i = 9; s > i; i--)
		{
			z = char(i + '0') + z;
			s -= i;
		}
		z = char(s + '0') + z;
		cout << z << endl;
	}
}