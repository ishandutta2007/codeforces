/***
10 4
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, k;
	cin >> n >> k;
	ll g = n / k;
	if (g % 2 == 1)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}