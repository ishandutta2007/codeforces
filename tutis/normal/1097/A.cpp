/*input
2
10
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	string c;
	while (cin >> c)
	{
		if (c[0] == s[0] || s[1] == c[1])
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}