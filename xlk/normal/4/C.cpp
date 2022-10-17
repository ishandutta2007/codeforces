#include <bits/stdc++.h>
using namespace std;
int n;
string s;
map<string, int> m;
int main()
{
	for (cin >> n; n--;)
	{
		cin >> s;
		if (m[s])
		{
			cout << s << m[s] << endl;
		}
		else
		{
			cout << "OK" << endl;
		}
		m[s]++;
	}
	return 0;
}