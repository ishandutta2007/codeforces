/*input
code
edoc
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	cout << (a == b ? "YES\n" : "NO\n");
}