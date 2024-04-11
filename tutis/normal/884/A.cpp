/***
2 86400
0 86400
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, t;
	cin >> n >> t;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		t -= 86400 - a[i];
		if (t <= 0)
		{
			cout << i;
			return 0;
		}
	}
}