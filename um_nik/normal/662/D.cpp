#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

typedef long long ll;

ll getNum(string s)
{
	ll res = 0;
	for (int i = 0; i < (int)s.length(); i++)
		res = res * 10 + (ll)(s[i] - '0');
	return res;
}

void solve()
{
	string s;
	cin >> s;
	s = s.substr(4, (int)s.length() - 4);
	ll x = getNum(s);
	ll y = 1989;
	ll z = 1;
	for (int i = 1; i < (int)s.length(); i++)
	{
		z *= 10;
		y += z;
	}
	z *= 10;
	while(x < y) x += z;
	cout << x << endl;
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	while(t--)
		solve();

	return 0;
}