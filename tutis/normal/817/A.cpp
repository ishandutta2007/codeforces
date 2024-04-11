/**
1 1 3 6
1 5
**/
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef double d;
typedef long l;
#define MOD 1
#define mod(x) ((x+MOD)%MOD)
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ll x, y;
	cin >> x >> y;
	if (abs(x1 - x2) % x == 0 && abs(y1 - y2) % y == 0)
		if (((abs(x1 - x2) / x) % 2 + (abs(y1 - y2) / y) % 2) % 2 == 0)
			cout << "YES";
		else
			cout << "NO";
	else
		cout << "NO";
	return 0;
}