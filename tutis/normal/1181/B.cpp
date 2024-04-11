/*input
3
101
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
string add(const string &a, const string &b)
{
	string c(max(a.size(), b.size()), '0');
	for (int i = 0; i < (int)a.size(); i++)
	{
		c[i] += a[i] - '0';
	}
	for (int i = 0; i < (int)b.size(); i++)
	{
		c[i] += b[i] - '0';
	}
	for (int i = 0; i < (int)c.size(); i++)
	{
		if (c[i] > '9')
		{
			c[i] -= 10;
			if (i + 1 >= (int)c.size())
				c.push_back('0');
			c[i + 1]++;
		}
	}
	return c;
}
bool maziau(const string &a, const string &b)
{
	if (a.size() != b.size())
		return a.size() < b.size();
	for (int i = (int)a.size() - 1; i >= 0; i--)
		if (a[i] != b[i])
			return a[i] < b[i];
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	reverse(s.begin(), s.end());
	string mini = s;
	vector<int>g;
	for (int i = 1; i < (int)s.size(); i++)
		if (s[i - 1] != '0')
			g.push_back(i);
	sort(g.begin(), g.end(), [&](int a, int b) {return max(a, n - a) < max(b, n - b);});
	for (int i : g)
	{
		if (max(i, n - i) <= (int)mini.size())
		{
			string t = add(s.substr(0, i), s.substr(i, n - i));
			if (maziau(t, mini))
				mini = t;
		}
	}
	reverse(mini.begin(), mini.end());
	cout << mini << "\n";
}