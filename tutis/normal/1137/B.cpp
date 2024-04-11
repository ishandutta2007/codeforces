/*input
11000000
0
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	int k = 0;
	bitset<500000>x;
	bitset<500000>y;
	for (int sz = (int)t.size() - 1; sz >= 0; sz--)
	{
		bool ok = true;
		for (int i = 0; i <= (sz - 1) / 2; i++)
		{
			i = sz - 1 - i;
			if (t[i] != t[t.size() - sz + i])
			{
				ok = false;
				break;
			}
			i = sz - 1 - i;
			if (t[i] != t[t.size() - sz + i])
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			k = sz;
			break;
		}
	}
	k = t.size() - k;
	while (t.size() < s.size())
	{
		int l = t.size() - k;
		int r = t.size() - 1;
		for (int i = l; i <= r; i++)
			t.push_back(t[i]);
	}
	int k0 = 0, k1 = 0;
	for (char &i : s)
	{
		if (i == '0')
			k0++;
		else
			k1++;
	}
	string naujas = "";
	for (char i : t)
	{
		if (i == '0' && k0 > 0)
		{
			naujas.push_back('0');
			k0--;
		}
		else if (i == '1' && k1 > 0)
		{
			naujas.push_back('1');
			k1--;
		}
		else if (k0 > 0)
		{
			naujas.push_back('0');
			k0--;
		}
		else if (k1 > 0)
		{
			naujas.push_back('1');
			k1--;
		}
	}
	cout << naujas << "\n";
}