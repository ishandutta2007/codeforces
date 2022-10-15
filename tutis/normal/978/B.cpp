/*input
10
xxxxxxxxxx
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 2; i < n; i++)
	{
		if (s[i] == s[i - 1] && s[i] == s[i - 2] && s[i] == 'x')
			ans++;
	}
	cout << ans << "\n";

}