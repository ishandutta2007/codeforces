/***
1 9
10

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
	int s = 0;
	int liko = 0;
	int i = 0;
	while (n--)
	{
		i++;
		int a;
		cin >> a;
		liko += a;
		if (liko > 8)
		{
			liko -= 8;
			s += 8;
		}
		else
		{
			s += liko;
			liko = 0;
		}
		if (s >= k)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << -1;
}