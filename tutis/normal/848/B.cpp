/***
3 2 3
1 1 2
2 1 1
1 1 5
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct dancer
{
	ll g, p, t, i;
};
#define MAX_N 200009
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, w, h;
	cin >> n >> w >> h;
	dancer X[n];
	map<ll, vector<dancer>>Y;
	for (ll i = 0; i < n; i++)
	{
		cin >> X[i].g >> X[i].p >> X[i].t;
		X[i].i = i;
		Y[X[i].p - X[i].t].push_back(X[i]);
	}
	pair<ll, ll>ans[n];
	for (ll c1 = -MAX_N; c1 <= MAX_N; c1++)
	{
		vector<dancer> suX;
		vector<dancer> suY;
		for (dancer c : Y[c1])
		{
			if (c.g == 1)
				suX.push_back(c);
			else
				suY.push_back(c);
		}
		sort(suX.begin(), suX.end(), [](dancer a, dancer b) {return a.p > b.p;});
		sort(suY.begin(), suY.end(), [](dancer a, dancer b) {return a.p < b.p;});
		vector<pair<ll, ll>>pos;
		for (dancer a : suX)
		{
			pos.push_back(make_pair(a.p, h));
		}
		for (dancer a : suY)
		{
			pos.push_back(make_pair(w, a.p));
		}
		sort(pos.begin(), pos.end(), [](pair<ll, ll>a, pair<ll, ll>b) {return a.first - a.second < b.first - b.second;});
		for (dancer a : suX)
		{
			ans[a.i] = pos.back();
			pos.pop_back();
		}
		for (dancer b : suY)
		{
			ans[b.i] = pos.back();
			pos.pop_back();
		}
	}
	for (ll i = 0; i < n; i++)
		cout << ans[i].first << " " << ans[i].second << "\n";
}