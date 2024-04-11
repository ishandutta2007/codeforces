/*input
1 7 3 3

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
	int x;
	set<int>a;
	while (cin >> x)
		a.insert(x);
	cout << 4 - a.size() << "\n";
}