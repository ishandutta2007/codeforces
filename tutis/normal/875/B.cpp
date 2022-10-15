/***
8
6 8 3 4 7 2 1 5
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct BIT
{
	vector<ll> A;
	void init()
	{
		for (int i = 0; i <= 310000; i++)
			A.push_back(0);
	}
	void add(ll i)
	{
		for (; i < 310000; i += (i) & (-i))
			A[i]++;
	}
	ll get(ll i)
	{
		ll ret = 0;
		for (; i > 0; i -= (i) & (-i))
			ret += A[i];
		return ret;
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	cout << 1 << " ";
	BIT A;
	A.init();
	ll N = n;
	bool yra[N + 2];
	fill_n(yra, N + 2, false);
	ll id = N + 1;
	ll kiek = 0;
	while (n--)
	{
		ll p;
		cin >> p;
		yra[p] = true;
		while (yra[id - 1])
		{
			id--;
			kiek++;
		}
		A.add(p);
		cout << A.get(N + 1) - kiek + 1 << " ";
	}
}