/**
3
1 1 2
2 3 1
6 4 1
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	ll a[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != 1)
			{
				bool ok = false;
				for (int s = 0; s < n; s++)
					for (int t = 0; t < n; t++)
						if (a[i][j] == a[i][s] + a[t][j])
							ok = true;
				if (!ok)
				{
					cout << "No";
					return 0;
				}
			}
	cout << "Yes";
}