/***
4 5 3 1 5
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll s, v1, v2, t1, t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	ll k1 = s * v1 + t1 * 2;
	ll k2 = s * v2 + t2 * 2;
	if (k1 == k2)
		cout << "Friendship";
	else if (k1 < k2)
		cout << "First";
	else
		cout << "Second";

}