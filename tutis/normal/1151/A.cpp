/*input
6
AFBAKC

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int f(char a, char b)
{
	if (a > b)
		swap(a, b);
	int ans = min(int(b - a), 26 - (int)(b - a));
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = n * 1000;
	for (int i = 3; i < n; i++)
	{
		ans = min(ans, f(s[i - 3], 'A') + f(s[i - 2], 'C') + f(s[i - 1], 'T') + f(s[i], 'G'));
	}
	cout << ans << "\n";
}