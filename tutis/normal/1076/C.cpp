/*input
7
69
0
1
4
5
999
1000
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		ll d;
		cin >> d;
		// Ax^2+Bx+C
		ll A = 1;
		ll B = -d;
		ll C = d;
		ll D = B * B - 4 * A * C;
		if (D < 0)
		{
			cout << "N\n";
		}
		else
		{
			ld a = ld(-B + sqrtl(D)) * 0.5;
			ld b = ld(d) / a;
			if (d == 0)
				b = 0;
			cout << fixed << setprecision(10) << "Y " << a << " " << b << "\n";
		}
	}

}