#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> s;
		int z = 0;
		for (int i = 0; i < s.size(); i++)
		{
			z += s[i] - '0';
			if (i + 1 < s.size() && s[i] > '0')
			{
				z++;
			}
		}
		cout << z << endl;
	}
	return 0;
}