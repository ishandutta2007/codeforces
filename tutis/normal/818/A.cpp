/**
1000000000000 499999999999
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll n, k;
	cin >> n >> k;
	ll d = (n) / (2 * (k + 1));
	ll c = k * d;
	cout << d << " " << c << " " << n - d - c;
}