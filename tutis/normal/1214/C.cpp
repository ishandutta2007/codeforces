/*input
2
)(
*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == ')')
		{
			s.erase(s.begin() + i);
			s.push_back(')');
			break;
		}
	}
	int k = 0;
	for (char c : s)
	{
		if (c == '(')
			k++;
		else
		{
			k--;
			if (k < 0)
			{
				cout << "NO\n";
				return 0;
			}
		}
	}
	if (k != 0)
	{
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
}