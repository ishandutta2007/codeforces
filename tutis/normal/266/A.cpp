/*input
3
RRG
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int ans = 0;
	string s;
	cin >> s;
	for (int i = 1; i < s.size(); i++)
		ans += (s[i] == s[i - 1]);
	cout << ans << "\n";
}