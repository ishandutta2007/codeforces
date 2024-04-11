/*input
3 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	int c = min(a, b);
	a -= c;
	b -= c;
	cout << c << " " << a / 2 + b / 2 << "\n";
}