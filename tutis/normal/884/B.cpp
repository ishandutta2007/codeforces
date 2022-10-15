/***
2 10
1 3
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, x;
	cin >> n >> x;
	int a[n];
	int kiek1 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		kiek1 += a[i];
	}
	int ilgis = kiek1 + n - 1;
	if (ilgis == x)
		cout << "YES";
	else
		cout << "NO";
}