/*input
3 1 -9
0 3 3 -1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ld dist(pair<ld, ld>a, pair<ld, ld>b)
{
	return sqrtl(
	           (a.first - b.first) * (a.first - b.first) +
	           (a.second - b.second) * (a.second - b.second));
}
int main()
{
	ll a, b, c;
	cin >> a >> b >> c;
	ll x1, y1;
	ll x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ld ans = abs(x1 - x2) + abs(y1 - y2);
	if (a == 0 || b == 0)
	{
		cout << fixed << setprecision(30) << ans << "\n";
		return 0;
	}
	vector<pair<ld, ld>>A;
	vector<pair<ld, ld>>B;
	pair<ld, ld>a_ = {x1, y1};
	pair<ld, ld>b_ = {x2, y2};
	{
		ld x = x1;
		ld y = ld(-c - a * x) / ld(b);
		A.push_back({x, y});
	}
	{
		ld y = y1;
		ld x = ld(-c - b * y) / ld(a);
		A.push_back({x, y});
	}
	{
		ld x = x2;
		ld y = ld(-c - a * x) / ld(b);
		B.push_back({x, y});
	}
	{
		ld y = y2;
		ld x = ld(-c - b * y) / ld(a);
		B.push_back({x, y});
	}
	for (pair<ld, ld>i : A)
	{
		for (pair<ld, ld>j : B)
		{
			ld D = dist(a_, i) + dist(i, j) + dist(j, b_);
			ans = min(ans, D);
		}
	}
	cout << fixed << setprecision(30) << ans << "\n";
}