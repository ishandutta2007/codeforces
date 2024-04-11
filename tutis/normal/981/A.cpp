/*input
qqqqqqqq
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
string s;
bool Npalindrome(int a, int b)
{
	for (int i = 0; i <= b - a; i++)
	{
		if (s[a + i] != s[b - i])
			return true;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	int ans = 0;
	for (int l = 0; l < s.size(); l++)
		for (int r = l; r < s.size(); r++)
			if (Npalindrome(l, r))
				ans = max(ans, r - l + 1);
	cout << ans << "\n";
}