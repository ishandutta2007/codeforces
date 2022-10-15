/*input
9 6
gfgf*gfgf
gfgfgf
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	if (n > m + 1)
	{
		cout << "NO\n";
		return 0;
	}
	if (s == t)
	{
		cout << "YES\n";
		return 0;
	}
	bool ok = false;
	for (char x : s)
		if (x == '*')
			ok = true;
	if (ok == false)
	{
		cout << "NO\n";
		return 0;
	}
	for (int i = 0;; i++)
	{
		if (s[i] == '*')
			break;
		if (i >= t.size() || s[i] != t[i])
		{
			cout << "NO\n";
			return 0;
		}
	}
	for (int i = 1;; i++)
	{
		if (s[n - i] == '*')
			break;
		if (m - i < 0 || s[n - i] != t[m - i])
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}