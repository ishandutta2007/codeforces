/*input
Hi!

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	string a;
	getline(cin, a);
	if (find(a.begin(), a.end(), 'H') != a.end())
	{
		cout << "YES\n";
		return 0;
	}
	if (find(a.begin(), a.end(), 'Q') != a.end())
	{
		cout << "YES\n";
		return 0;
	}
	if (find(a.begin(), a.end(), '9') != a.end())
	{
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";
}