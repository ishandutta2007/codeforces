/*input
2 2 1 2
1 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int>pos;
ll n, k, A, B;
ll answer(ll a, ll b)
{
	ll kiek = 0;
	for (auto it = lower_bound(pos.begin(), pos.end(), a); it != pos.end() && (*it) <= b; it++)
	{
		kiek++;
	}
	if (kiek == 0)
		return A;
	ll ret = B * kiek * (b - a + 1);
	if (a < b)
		ret = min(ret, answer(a, (a + b) / 2) + answer((a + b) / 2 + 1, b));
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> k >> A >> B;
	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		pos.push_back(a);
	}
	sort(pos.begin(), pos.end());
	cout << answer(1, 1 << n) << "\n";
}