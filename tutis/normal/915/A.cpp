/***
6 7
1 2 3 4 5 6
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	int ans = k;
	while (n--)
	{
		int a;
		cin >> a;
		if (k % a == 0)
			ans = min(ans, k / a);
	}
	cout << ans;
}