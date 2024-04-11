/***
1
3 3
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	int a[n * 2];
	for (int i = 0; i < 2 * n; i++)
		cin >> a[i];
	sort(a, a + n * 2);
	for (int i = 0; i < n; i++)
	{
		for (int j = n; j < 2 * n; j++)
		{
			if (a[i] >= a[j])
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
}