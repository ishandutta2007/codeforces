#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<string> a;
bool ok;
int main()
{
	cin >> n >> k;
	for (int i = 0; i < 4 * n; i++)
	{
		string s, t;
		cin >> s;
		int c = 0;
		for (int j = s.size() - 1; j >= 0 && c < k; j--)
		{
			if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
			{
				c++;
			}
			t += s[j];
		}
		if (c < k)
		{
			cout << "NO" << endl;
			return 0;
		}
		a.push_back(t);
	}
	ok = true;
	for (int i = 0; i < 4 * n; i += 4)
	{
		if (a[i] != a[i + 1] || a[i + 1] != a[i + 2] || a[i + 2] != a[i + 3])
		{
			ok = false;
			break;
		}
	}
	if (ok)
	{
		cout << "aaaa" << endl;
		return 0;
	}
	ok = true;
	for (int i = 0; i < 4 * n; i += 4)
	{
		if (a[i] != a[i + 1] || a[i + 2] != a[i + 3])
		{
			ok = false;
			break;
		}
	}
	if (ok)
	{
		cout << "aabb" << endl;
		return 0;
	}
	ok = true;
	for (int i = 0; i < 4 * n; i += 4)
	{
		if (a[i] != a[i + 2] || a[i + 1] != a[i + 3])
		{
			ok = false;
			break;
		}
	}
	if (ok)
	{
		cout << "abab" << endl;
		return 0;
	}
	ok = true;
	for (int i = 0; i < 4 * n; i += 4)
	{
		if (a[i] != a[i + 3] || a[i + 1] != a[i + 2])
		{
			ok = false;
			break;
		}
	}
	if (ok)
	{
		cout << "abba" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}