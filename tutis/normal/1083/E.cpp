/*input
3
4 4 8
1 5 0
5 2 10
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct A
{
	ll x, y, a;
	ll ans()
	{
		return x * y - a;
	}
};
ld susikerta(pair<ll, ll>a, pair<ll, ll>b)
{
	return ld((b.second - a.second)) / ld((a.first - b.first));
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	A a[n];
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].x >> a[i].y >> a[i].a;
	}
	sort(a, a + n, [](A a, A b) {
		return a.x < b.x;
	});
	ll ANS[n];
	vector<pair<ll, ll>>J;
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		ANS[i] = a[i].x * a[i].y - a[i].a;
		while (t + 1 < J.size())
		{
			pair<ll, ll>X1 = J[t];
			pair<ll, ll>X2 = J[t + 1];
			if (X2.first * a[i].y + X2.second >= X1.first * a[i].y + X1.second)
				t++;
			else
				break;
		}
		if (t < J.size())
		{
			pair<ll, ll>X = J[t];
			ANS[i] = max(ANS[i], a[i].x * a[i].y - a[i].a + X.first * a[i].y + X.second);
		}
		pair<ll, ll>X = { -a[i].x, ANS[i]};
		while (J.size() >= 2 && susikerta(J[J.size() - 1], X) > susikerta(J[J.size() - 2], X))
			J.pop_back();
		J.push_back(X);
	}
	cout << *max_element(ANS, ANS + n) << "\n";
}