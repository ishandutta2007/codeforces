/*input
13 3 6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int a, b, c;
	cin >> a >> b >> c;
	int d = min({a, b - 1, c - 2});
	cout << 3 * d + 1 + 2 << endl;
}