/*input
.BAC.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string s;
	cin >> s;
	for (int i = 2; i < s.size(); i++)
	{
		if (s[i] == '.' || s[i - 1] == '.' || s[i - 2] == '.')
			continue;
		if (s[i] == s[i - 1])
			continue;
		if (s[i] == s[i - 2])
			continue;
		if (s[i - 1] == s[i - 2])
			continue;
		cout << "Yes\n";
		return 0;
	}
	cout << "No\n";

}