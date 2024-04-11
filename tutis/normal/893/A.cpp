/***
2
1
2
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int spec = 0;
	int r = 0;
	cin >> r;
	if (r == 1)
		spec = 2;
	if (r == 2)
		spec = 1;
	if (r == 3)
	{
		cout << "NO";
		return 0;
	}
	for (int i = 1; i < n; i++)
	{
		int a;
		cin >> a;
		if (a == spec)
		{
			cout << "NO";
			return 0;
		}
		spec = 6 - a - spec;
	}
	cout << "YES";
}