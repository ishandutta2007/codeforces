/*input
{a, b, c}
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	set<char>x;
	char a;
	while (cin >> a)
		x.insert(a);
	x.erase('{');
	x.erase('}');
	x.erase(',');
	cout << x.size() << "\n";
}