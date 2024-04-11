#include <bits/stdc++.h>
using namespace std;
vector<char> a;
string s;
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (a.size() > 0 && s[i] == a.back())
		{
			a.pop_back();
		}
		else
		{
			a.push_back(s[i]);
		}
	}
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
	}
	return 0;
}