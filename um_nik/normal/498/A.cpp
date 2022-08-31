#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef long long ll;

int n;
int ans;
ll xx1, xx2, yy1, yy2;
ll a, b, c;

int sgn(ll x)
{
	if (x > 0) return 1;
	if (x == 0) return 0;
	return -1;
}

int main()
{
	cin >> xx1 >> yy1 >> xx2 >> yy2;
	cin >> n;
	ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		ans += (int)( sgn(a * xx1 + b * yy1 + c) != sgn(a * xx2 + b * yy2 + c) );
	}
	cout << ans << endl;

	return 0;
}