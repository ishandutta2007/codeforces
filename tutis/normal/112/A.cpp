/*input
abs
Abz
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	for (char &x : a)
		x = tolower(x);
	for (char &x : b)
		x = tolower(x);
	if (a == b)
		cout << "0\n";
	if (a < b)
		cout << "-1\n";
	if (a > b)
		cout << "1\n";
}