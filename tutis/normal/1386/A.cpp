/*input
2
1
5
0
0
0
0
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll mini(ll n)
{
	ll cur = 0;
	ll ret = 0;
	ll lo = 1;
	ll hi = n;
	ll kiek = 0;
	while (lo < hi)
	{
		kiek++;
		ll del = (lo + hi - 1) / 2;
		if (kiek % 2 == 1)
			cur += del;
		else
			cur -= del;
		ret = min(ret, cur);
		lo = del + 1;
	}
	return ret;
}
ll ask(ll n, vector<ll>x, vector<ll>y)
{
	assert(x.size() < n);
	assert(x.size() == y.size());
	ll lo = 1;
	ll hi = n;
	for (int i = 1; i < (int)x.size(); i++)
	{
		if (y[i] == 1)
			hi = min(hi, abs(x[i - 1] - x[i]));
		else
			lo = max(lo, abs(x[i - 1] - x[i]) + 1);
	}
	if (x.empty())
		return -mini(n) + 1;
	else
	{
		ll del = (lo + hi - 1) / 2;
		if (x.size() % 2 == 1)
			return x.back() + del;
		else
			return x.back() - del;
	}
}
// void test()
// {
// 	for (int n = 1; n <= 1000; n++)
// 	{
// 		ll lo1 = 100000;
// 		ll hi1 = -100000;
// 		for (int c = 1; c <= n; c++)
// 		{
// 			//cout << n << " " << c << endl;
// 			vector<ll>x;
// 			vector<ll>ans;
// 			ll lo = 1;
// 			ll hi = n;
// 			ll last = -1;
// 			vector<int>A;
// 			while (lo < hi)
// 			{
// 				ll v = ask(n, x, ans);
// 				//cout << "? " << v << endl;
// 				lo1 = min(lo1, v);
// 				hi1 = max(hi1, v);
// 				for (int w : A)
// 					assert(v != w);
// 				A.push_back(v);
// 				int k = 0;
// 				if (last != -1 && abs(last - v) >= c)
// 					k = 1;
// 				x.push_back(v);
// 				ans.push_back(k);
// 				if (last != -1)
// 				{
// 					if (k == 1)
// 						hi = min(hi, abs(last - v));
// 					else
// 						lo = max(lo, abs(last - v) + 1);
// 				}
// 				last = v;
// 			}
// 			// if ((lo + hi) / 2 != c)
// 			// {
// 			// 	cout << n << ", " << c << " " << (lo + hi) / 2 << endl;
// 			// }
// 			// else
// 			// 	cout << "ok\n";
// 		}
// 		assert(hi1 - lo1 + 1 <= n);
// 		cout << "::" << n << " " << lo1 << " " << hi1 << endl;
// 	}
// }
int main()
{
	//test();
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cerr.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		vector<ll>x;
		vector<ll>ans;
		ll lo = 1;
		ll hi = n;
		ll last = -1;
		while (lo < hi)
		{
			ll v = ask(n, x, ans);
			cout << "? " << v << endl;
			ll k;
			cin >> k;
			x.push_back(v);
			ans.push_back(k);
			if (last != -1)
			{
				if (k == 1)
					hi = min(hi, abs(last - v));
				else
					lo = max(lo, abs(last - v) + 1);
			}
			last = v;
			if (x.size() == 64)
				break;
		}
		cout << "= " << (lo + hi) / 2 << endl;
	}
}