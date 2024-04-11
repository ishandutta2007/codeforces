/*input
a
u
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	if (s.size() != t.size())
	{
		cout << "No\n";
		return 0;
	}
	set<char>X = {'a', 'e', 'i', 'o', 'u'};
	for (int i = 0; i < s.size(); i++)
	{
		if (X.count(s[i]) != X.count(t[i]))
		{
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}