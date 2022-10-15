/*input
5
10 40 20 50 30
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
	ll A[n];
	bool yra[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> A[i];
		yra[i] = true;
	}
	map<ll, vector<ll>>K;
	for (ll i = 0; i < n; i++)
	{
		K[A[i]].push_back(i);
	}
	ll i = 0;
	while (K.upper_bound(i) != K.end())
	{
		auto it = K.upper_bound(i);
		i = it->first;
		sort(((*it).second).begin(), ((*it).second).end());
		for (ll j = 1; j < ((*it).second).size(); j += 2)
		{
			A[((*it).second)[j]] *= 2;
			K[2 * i].push_back(((*it).second)[j]);
		}
		for (ll j = 0; j < ((*it).second).size() - ((*it).second).size() % 2; j += 2)
		{
			yra[((*it).second)[j]] = false;
		}
	}

	ll k = 0;
	for (ll i = 0; i < n; i++)
		k += yra[i];
	cout << k << "\n";
	for (ll i = 0; i < n; i++)
		if (yra[i])
			cout << A[i] << " ";



}