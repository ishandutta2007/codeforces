/*input
5
10 R
14 B
16 B
21 R
32 R
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	set<ll>A;
	set<ll>B;
	set<ll>C;
	while (n--)
	{
		ll x;
		char c;
		cin >> x >> c;
		if (c == 'B')
			A.insert(x);
		else if (c == 'R')
			B.insert(x);
		else
			C.insert(x);
	}
	if (C.empty())
	{
		ll ans = 0;
		if (!A.empty())
			ans += (*(--A.end())) - (*(A.begin()));
		if (!B.empty())
			ans += (*(--B.end())) - (*(B.begin()));
		cout << ans << "\n";
		return 0;
	}
	ll buvo = -1e15;
	ll ans = 0;
	bool nebuvoA = true, nebuvoB = true;
	for (ll i : C)
	{
		vector<ll>A_;
		vector<ll>B_;
		while (A.upper_bound(buvo) != A.end())
		{
			ll x = *A.upper_bound(buvo);
			if (x < i)
			{
				nebuvoA = false;
				A_.push_back(x);
				A.erase(x);
			}
			else
			{
				break;
			}
		}
		while (B.upper_bound(buvo) != B.end())
		{
			ll x = *B.upper_bound(buvo);
			if (x < i)
			{
				nebuvoB = false;
				B_.push_back(x);
				B.erase(x);
			}
			else
			{
				break;
			}
		}
		if (buvo >= -1e10)
		{
			if (A_.empty() && B_.empty())
			{
				ans += i - buvo;
			}
			else if (A_.empty())
			{
				ll mx1 = max(i - B_.back(), B_.front() - buvo);
				for (ll j = 1; j < B_.size(); j++)
					mx1 = max(mx1, B_[j] - B_[j - 1]);
				ans += 2 * (i - buvo) - mx1;
			}
			else if (B_.empty())
			{
				ll mx1 = max(i - A_.back(), A_.front() - buvo);
				for (ll j = 1; j < A_.size(); j++)
					mx1 = max(mx1, A_[j] - A_[j - 1]);
				ans += 2 * (i - buvo) - mx1;
			}
			else
			{
				ll gal = 2 * (i - buvo);
				ll mx1 = max(i - A_.back(), A_.front() - buvo);
				ll mx2 = max(i - B_.back(), B_.front() - buvo);
				for (ll j = 1; j < A_.size(); j++)
					mx1 = max(mx1, A_[j] - A_[j - 1]);
				for (ll j = 1; j < B_.size(); j++)
					mx2 = max(mx2, B_[j] - B_[j - 1]);
				gal = min(gal, 3 * (i - buvo) - mx1 - mx2);
				ans += gal;
			}
		}
		else
		{
			if (!A_.empty())
			{
				for (ll j = 1; j < A_.size(); j++)
					ans += A_[j] - A_[j - 1];
				ans += i - A_.back();
			}
			if (!B_.empty())
			{
				for (ll j = 1; j < B_.size(); j++)
					ans += B_[j] - B_[j - 1];
				ans += i - B_.back();
			}
		}

		buvo = i;
	}
	vector<ll>A_;
	vector<ll>B_;
	while (A.upper_bound(buvo) != A.end())
	{
		ll x = *A.upper_bound(buvo);
		A_.push_back(x);
		A.erase(x);
	}
	while (B.upper_bound(buvo) != B.end())
	{
		ll x = *B.upper_bound(buvo);
		B_.push_back(x);
		B.erase(x);
	}
	if (!A_.empty())
	{
		for (ll i = 1; i < A_.size(); i++)
			ans += A_[i] - A_[i - 1];
		ans += A_[0] - buvo;
	}
	if (!B_.empty())
	{
		for (ll i = 1; i < B_.size(); i++)
			ans += B_[i] - B_[i - 1];
		ans += B_[0] - buvo;
	}



	cout << ans << "\n";

}