/*input
7 10

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ld f(ll n)
{
	ld PI = acosl(-1);
	ld alfa = PI / (2 * n);
	ld beta = PI / n;
	ld gama = PI - PI / n - PI / (2 * n);
	return sinl(beta) * sinl(alfa) / sinl(gama) * n;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, r;
	cin >> n >> r;
	cout << fixed << setprecision(20) << ld(r)*ld(r)*f(n) << "\n";
}