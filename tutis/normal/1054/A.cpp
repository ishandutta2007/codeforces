/*input
1 6 6 2 1 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int x, y, z, t1, t2, t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;
	int kiekbe = abs(x - y) * t1;
	int kieksu = kiekbe + 1000;
	for (int a : {x})
	{
		int t = abs(a - z) * t2 + t3 * 2;
		t += abs(a - y) * t2;
		t += t3;
		kieksu = min(kieksu, t);
	}
	if (kieksu <= kiekbe)
	{
		cout << "YES\n";
	}
	else
		cout << "NO\n";
}