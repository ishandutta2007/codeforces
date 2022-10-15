/*input
3 7 0

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
char sgn(int x)
{
	if (x > 0)
		return '+';
	if (x < 0)
		return '-';
	return '0';
}
int main()
{
	ios_base::sync_with_stdio(false);
	int x, y, z;
	cin >> x >> y >> z;
	if (sgn(x - y + z) == sgn(x - y - z))
		cout << sgn(x - y + z);
	else
		cout << "?";
}