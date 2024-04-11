/*input
2
abcDCE
htQw27
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool ok(string x)
{
	vector<bool>ok(3, false);
	for (char a : x)
	{
		if (isupper(a))
			ok[0] = true;
		else if (islower(a))
			ok[1] = true;
		else
			ok[2] = true;
	}
	for (bool i : ok)
		if (i == false)
			return false;
	return true;
}
void solve(string s)
{
	if (ok(s))
	{
		cout << s << "\n";
		return;
	}
	set<char>x;
	for (char a = 'a'; a <= 'z'; a++)
		x.insert(a);
	for (char a = 'A'; a <= 'Z'; a++)
		x.insert(a);
	for (char a = '0'; a <= '9'; a++)
		x.insert(a);
	for (int i = 0; i < s.size(); i++)
	{
		string c = s;
		for (char j : x)
		{
			c[i] = j;
			if (ok(c))
			{
				cout << c << "\n";
				return;
			}
		}
	}
	for (int i = 0; i + 1 < s.size(); i++)
	{
		string c = s;
		for (char j : x)
		{
			c[i] = j;
			for (char k : x)
			{
				c[i + 1] = k;
				if (ok(c))
				{
					cout << c << "\n";
					return;
				}
			}
		}
	}
	for (int i = 0; i + 2 < s.size(); i++)
	{
		string c = s;
		for (char j : x)
		{
			c[i] = j;
			for (char k : x)
			{
				c[i + 1] = k;
				for (char l : x)
				{
					c[i + 2] = l;
					if (ok(c))
					{
						cout << c << "\n";
						return;
					}
				}
			}
		}
	}
	cout << s << "Fuck\n";
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		solve(s);
	}

}