/*input
4
0
1
14
24
9
19
4
0
1
14
24
9
19
4
0
1
14
24
9
19
4
0
1
14
24
9
19
4
0
1
14
24
9
19
4
0
1
14
24
9
19
4
0
1
14
24
9
19
4
0
1
14
24
9
19
4
0
1
14
24
9
19
4
0
1
14
24
9
19
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll RANDOM()
{
	return ((ll)rand()) +
	       1000ll * ((ll)rand()) +
	       100000ll * ((ll)rand()) +
	       10000000ll * ((ll)rand());
}
int main()
{
	ll n;
	cin >> n;
	srand(n + clock());
	ll lo = 0;
	ll hi = 1000000000;
	ll Q = 0;
	while (lo < hi)
	{
		ll m = (lo + hi) / 2;
		cout << "> " << m << endl;
		Q++;
		ll a;
		cin >> a;
		if (a > 0)
			lo = m + 1;
		else
			hi = m;
	}
	set<ll>X;
	while (X.size() + Q < 60 && X.size() < n)
	{
		X.insert((RANDOM() % n) + 1);
	}
	vector<ll>R;
	for (ll i : X)
	{
		cout << "? " << i << endl;
		ll a;
		cin >> a;
		R.push_back(a);
	}
	sort(R.begin(), R.end());
	ll d = 0;
	for (int i = 0; i < R.size(); i++)
	{
		for (int j = i + 1; j < R.size(); j++)
		{
			d = __gcd(d, R[j] - R[i]);
		}
	}
	cout << "! " << lo - d*(n - 1) << " " << d << endl;
}