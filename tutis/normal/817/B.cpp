/**
4
1 1 1 1
**/
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef double d;
typedef long l;
#define MOD 1
#define mod(x) ((x+MOD)%MOD)
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	ll l = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == a[2])
			l++;
	if (a[1] == a[2] && a[2] == a[0])
	{
		cout << (l - 2)*(l - 1)*l / 6;
		return 0;
	}
	if (a[1] == a[2])
	{
		cout << l * (l - 1) / 2;
		return 0;
	}
	cout << l;
	return 0;
}