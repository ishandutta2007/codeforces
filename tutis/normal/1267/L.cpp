/*input
3 2 2
bcaxxx
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, l, k;
	cin >> n >> l >> k;
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	string a[n];
	for (int i = 0; i < n; i++)
		a[i] = string(l, '?');
	vector<bool>gana(n, false);
	int x = 0;
	int y = 0;
	for (char c : s)
	{
		while (gana[x])
		{
			x++;
			if (x >= k)
			{
				x = 0;
				y++;
				if (y >= l)
					goto A;
			}
		}
		a[x][y] = c;
		if (x == k - 1)
		{
			for (int i = 0; i < x; i++)
				if (a[i][y] < a[k - 1][y])
					gana[i] = true;
		}
		x++;
		if (x >= k)
		{
			x = 0;
			y++;
			if (y >= l)
				goto A;
		}
	}
A:;
	map<char, int>M;
	for (char c : s)
		M[c]++;
	for (int i = 0; i < n; i++)
		for (char c : a[i])
			if (c != '?')
			{
				M[c]--;
				if (M[c] == 0)
					M.erase(c);
			}
	for (int i = 0; i < n; i++)
		for (char &c : a[i])
		{
			if (c == '?')
			{
				c = M.begin()->first;
				M[c]--;
				if (M[c] == 0)
					M.erase(c);
			}
		}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		cout << a[i] << "\n";
}