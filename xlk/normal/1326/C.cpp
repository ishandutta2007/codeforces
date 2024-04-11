#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int n, m, l, x;
ll z = 1, s = 0;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		if (x > n - m)
		{
			if (l > 0)
			{
				z = z * (i - l) % mod;
			}
			l = i;
			s += x;
		}
	}
	cout << s << ' ' << z << endl;
	return 0;
}