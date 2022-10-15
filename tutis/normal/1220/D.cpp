/*input
2
2 6

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
pair<int, set<ll>> maxi(vector<pair<ll, ll>>x)
{
	if (x.empty())
		return {0, {}};
	vector<pair<ll, ll>>a[2];
	for (pair<ll, ll> i : x)
	{
		a[i.first % 2].push_back(i);
	}
	for (pair<ll, ll> &i : a[0])
		i.first /= 2;
	set<ll>A;
	for (pair<ll, ll> i : a[1])
		A.insert(i.second);
	return max({(int)A.size(), A}, maxi(a[0]));
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<ll, ll>>b(n);
	set<ll>A;
	for (pair<ll, ll>&i : b)
	{
		cin >> i.first;
		i.second = i.first;
		A.insert(i.first);
	}
	auto x = maxi(b);
	for (ll i : x.second)
		A.erase(i);
	cout << A.size() << "\n";
	for (ll i : A)
		cout << i << " ";
}