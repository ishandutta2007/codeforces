#include <bits/stdc++.h>
using namespace std;
int n;
string s;
set<string> a;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		cout << (a.insert(s).second ? "NO" : "YES") << endl;
	}
	return 0;
}