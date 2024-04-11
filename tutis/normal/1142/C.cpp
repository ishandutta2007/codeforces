/*input
5
1 0
1 -1
0 -1
-1 0
-1 -1

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool blogai(pair<ll, ll>a, pair<ll, ll>b, pair<ll, ll>c)
{
	a.first -= b.first;
	a.second -= b.second;
	c.first -= b.first;
	c.second -= b.second;
	return (a.first * c.second - a.second * c.first <= 0);
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<ll, ll>>a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
		a[i].second -= a[i].first * a[i].first;
	}
	sort(a.begin(), a.end());
	vector<pair<ll, ll>>b;
	for (pair<ll, ll>i : a)
	{
		while (!b.empty() && b.back().first == i.first)
			b.pop_back();
		while (b.size() >= 2)
		{
			if (blogai(b[b.size() - 2], b.back(), i))
				b.pop_back();
			else
				break;
		}
		b.push_back(i);
	}
	cout << b.size() - 1 << "\n";
}