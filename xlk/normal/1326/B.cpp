#include <bits/stdc++.h>
using namespace std;
int n;
typedef long long ll;
ll mx;
ll a[200020];
ll b[200020];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] < 0)
		{
			b[i] = mx + a[i];
		}
		else
		{
			mx += a[i];
			b[i] = mx;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << b[i] << ' ';
	}
	cout << endl;
	return 0;
}