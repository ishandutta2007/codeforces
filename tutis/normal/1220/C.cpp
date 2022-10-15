/*input
abba
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	char mn = 'z' + 1;
	for (char c : s)
	{
		if (mn >= c)
			cout << "Mike\n";
		else
			cout << "Ann\n";
		mn = min(mn, c);
	}
}