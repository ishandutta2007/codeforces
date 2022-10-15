/*input
1 1
-1 -1
2
0 1 0
1 0 0
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct point
{
	ll x, y;
	void skaityk()
	{
		long long a, b;
		cin >> a >> b;
		x = a;
		y = b;
	}
	point()
	{

	}
	point(ll x, ll y): x(x), y(y)
	{

	}
};
ll sgn(ll a)
{
	if (a < 0)
		return -1;
	if (a > 0)
		return 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	point A, B;
	A.skaityk();
	B.skaityk();
	int ans = 0;
	int n;
	cin >> n;
	while (n--)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		ll k = 0;
		//ax+by+c=0
		vector<point>C;
		if (b != 0)
		{
			set<int>SGN;
			for (point C : {A, B})
			{
				ll x = (-c - a * C.x);
				ll y = b;
				if (y < 0)
				{
					x *= -1;
					y *= -1;
				}
				SGN.insert(sgn(C.y * y - x));
			}
			if (SGN.size() > 1)
				ans++;
		}
		else
		{
			set<int>SGN;
			for (point C : {A, B})
			{
				ll x = (-c - b * C.y);
				ll y = a;
				if (y < 0)
				{
					x *= -1;
					y *= -1;
				}
				SGN.insert(sgn(C.x * y - x));
			}
			if (SGN.size() > 1)
				ans++;
		}
	}
	cout << ans << "\n";
}