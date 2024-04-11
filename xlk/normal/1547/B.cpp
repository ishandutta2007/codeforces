#include <bits/stdc++.h>
using namespace std;
int t;
string s;
bool ok()
{
	int a = s.find('a');
	if (a == -1)
	{
		return false;
	}
	int l = a, r = a;
	for (int i = 1; i < s.size(); i++)
	{
		if (l > 0 && s[l - 1] == ('a' + i))
		{
			l--;
		}
		else if (r + 1 < s.size() && s[r + 1] == ('a' + i))
		{
			r++;
		}
		else
		{
			return false;
		}
	}
	return true;
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> s;
		cout << (ok() ? "Yes" : "No") << endl;
	}
}