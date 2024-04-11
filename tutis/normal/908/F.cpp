/***
7
0 R
1 G
2 R
3 B
10 G
11 R
13 R
***/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	ll ans = 0;
	deque<ll>X[256];
	while (n--)
	{
		ll x;
		char c;
		cin >> x >> c;
		X[c].push_back(x);
	}
	if (X['G'].empty())
	{
		for (ll i = 1; i < X['R'].size(); i++)
			ans += X['R'][i] - X['R'][i - 1];
		for (ll i = 1; i < X['B'].size(); i++)
			ans += X['B'][i] - X['B'][i - 1];
		cout << ans;
		return 0;
	}
	{
		vector<ll>A;
		vector<ll>B;
		int a = X['G'].front();
		while (!X['R'].empty() && X['R'].front() < a)
		{
			A.push_back(X['R'].front());
			X['R'].pop_front();
		}
		while (!X['B'].empty() && X['B'].front() < a)
		{
			B.push_back(X['B'].front());
			X['B'].pop_front();
		}
		A.push_back(a);
		B.push_back(a);
		for (ll i = 1; i < A.size(); i++)
			ans += A[i] - A[i - 1];
		for (ll i = 1; i < B.size(); i++)
			ans += B[i] - B[i - 1];
	}
	{
		vector<ll>A;
		vector<ll>B;
		while (!X['R'].empty() && X['R'].back() > X['G'].back())
		{
			A.push_back(X['R'].back());
			X['R'].pop_back();
		}
		while (!X['B'].empty() && X['B'].back() > X['G'].back())
		{
			B.push_back(X['B'].back());
			X['B'].pop_back();
		}
		A.push_back(X['G'].back());
		B.push_back(X['G'].back());
		for (ll i = 1; i < A.size(); i++)
			ans += A[i - 1] - A[i];
		for (ll i = 1; i < B.size(); i++)
			ans += B[i - 1] - B[i];
	}
	for (ll i = 1; i < X['G'].size(); i++)
	{
		ll a = X['G'][i - 1];
		ll b = X['G'][i];
		vector<ll>A;
		vector<ll>B;
		A.push_back(a);
		B.push_back(a);
		while (!X['R'].empty() && X['R'].front() < b)
		{
			A.push_back(X['R'].front());
			X['R'].pop_front();
		}
		while (!X['B'].empty() && X['B'].front() < b)
		{
			B.push_back(X['B'].front());
			X['B'].pop_front();
		}
		A.push_back(b);
		B.push_back(b);
		if (A.size() + B.size() == 4)
		{
			ans += b - a;
			continue;
		}
		ll ret = 2 * (b - a);
		ll ret1 = ret + b - a;
		ll a1 = 0;
		ll a2 = 0;
		for (ll i = 1; i < A.size(); i++)
			a1 = max(a1, A[i] - A[i - 1]);
		for (ll i = 1; i < B.size(); i++)
			a2 = max(a2, B[i] - B[i - 1]);
		ret1 -= a1 + a2;
		ans += min(ret1, ret);
	}
	cout << ans;
}