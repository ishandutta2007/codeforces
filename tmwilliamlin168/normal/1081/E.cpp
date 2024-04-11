#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100005], b[100005];
const ll m = 1e13;

bool check(ll x)
{
	ll s = sqrt(x);
	return s * s == x;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n / 2; i++) cin >> a[i];
		ll p = 1;
		while (p * p <= m && !check(p * p + a[1])) p++;
		if (p * p > m) { cout << "No" << endl; continue; }
		b[1] = p * p;
		ll sum = b[1] + a[1];
		int i = 2;
		for ( ; i <= n / 2; i++)
		{
			while (p * p <= sum + m && (p * p <= sum || !check(p * p + a[i]))) p++;
			if (p * p > sum + m) break;
			b[i] = p * p - sum;
			sum = p * p + a[i];
		}
		if (i != n / 2 + 1) { cout << "No" << endl; continue; }
		cout << "Yes" << endl;
		for (int i = 1; i <= n / 2; i++) cout << b[i] << " " << a[i] << " ";
		cout << endl;
	}
}