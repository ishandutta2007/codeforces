/*input
9 9
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	set<char>M;
	while (n--)
	{
		char x;
		cin >> x;
		x = tolower(x);
		M.insert(x);
	}
	if (M.size() == 26)
		cout << "YES\n";
	else
		cout << "NO\n";

}