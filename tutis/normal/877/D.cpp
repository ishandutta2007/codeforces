/***
2 2 1
.#
#.
1 1 2 2
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll S[1009][1009];
bool yra(ll x1, ll y1, ll x2, ll y2)
{
	if (x1 == x2)
	{
		if (y1 > y2)
			swap(y1, y2);
	}
	if (y1 == y2)
	{
		if (x1 > x2)
			swap(x1, x2);
	}
	return (S[x2][y2] - S[x2][y1 - 1] - S[x1 - 1][y2] + S[x1 - 1][y1 - 1] == 0);
}
struct stru
{
	bool operator()(ll a, ll b)
	{
		return a > b;
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, m, k;
	cin >> n >> m >> k;
	set<ll>X1[n + 1];
	set<ll>Y1[m + 1];
	set<ll, stru>X2[n + 1];
	set<ll, stru>Y2[m + 1];
	for (ll i = 0; i <= n; i++)
	{
		for (ll j = 0; j <= m; j++)
		{
			S[i][j] = 0;
		}
	}
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= m; j++)
		{
			char x;
			cin >> x;
			if (x == '.')
			{
				X1[i].insert(j);
				X2[i].insert(j);
				Y1[j].insert(i);
				Y2[j].insert(i);
				S[i][j] = 0;
			}
			else
				S[i][j] = 1;
			S[i][j] += S[i - 1][j];
			S[i][j] += S[i][j - 1];
			S[i][j] -= S[i - 1][j - 1];
		}
	}
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	queue<ll>xx;
	queue<ll>yy;
	queue<ll>di;
	xx.push(x1);
	yy.push(y1);
	di.push(0);
	while (!xx.empty())
	{
		ll a = xx.front();
		ll b = yy.front();
		ll c = di.front();
		xx.pop();
		yy.pop();
		di.pop();
		if (a == x2 && b == y2)
		{
			cout << c << "\n";
			return 0;
		}
		while (X1[a].upper_bound(b) != X1[a].end() && abs((*X1[a].upper_bound(b)) - b) <= k)
		{
			ll b_ = *X1[a].upper_bound(b);
			if (yra(a, b, a, b_))
			{
				X1[a].erase(b_);
				X2[a].erase(b_);
				xx.push(a);
				yy.push(b_);
				di.push(c + 1);
			}
			else
				break;
		}
		while (X2[a].upper_bound(b) != X2[a].end() && abs((*X2[a].upper_bound(b)) - b) <= k)
		{
			ll b_ = *X2[a].upper_bound(b);
			if (yra(a, b, a, b_))
			{
				X1[a].erase(b_);
				X2[a].erase(b_);
				xx.push(a);
				yy.push(b_);
				di.push(c + 1);
			}
			else
				break;
		}
		while (Y1[b].upper_bound(a) != Y1[b].end() && abs((*Y1[b].upper_bound(a)) - a) <= k)
		{
			ll a_ = *Y1[b].upper_bound(a);
			if (yra(a, b, a_, b))
			{
				Y1[b].erase(a_);
				Y2[b].erase(a_);
				xx.push(a_);
				yy.push(b);
				di.push(c + 1);
			}
			else
				break;
		}
		while (Y2[b].upper_bound(a) != Y2[b].end() && abs((*Y2[b].upper_bound(a)) - a) <= k)
		{
			ll a_ = *Y2[b].upper_bound(a);
			if (yra(a, b, a_, b))
			{
				Y1[b].erase(a_);
				Y2[b].erase(a_);
				xx.push(a_);
				yy.push(b);
				di.push(c + 1);
			}
			else
				break;
		}
	}
	cout << -1;
}