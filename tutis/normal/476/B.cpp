/*input
++-+-
+-+-+
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ld F(ll n)
{
	ld ans = 1;
	for (int i = 1; i <= n; i++)
		ans *= i;
	return ans;
}
ld C(ll n, ll k)
{
	if (n < 0 || k < 0 || n - k < 0)
		return 0;
	return F(n) / F(k) / F(n - k);
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string a, b;
	cin >> a >> b;
	int x = 0;
	int c = 0;
	for (char i : a)
		if (i == '+')
			x++;
		else
			x--;
	for (char i : b)
		if (i == '+')
			x--;
		else if (i == '-')
			x++;
		else
			c++;
	x = abs(x);
	cout << fixed << setprecision(30) << C(c, (c + x) / 2) * pow(0.5, c) << "\n";


}