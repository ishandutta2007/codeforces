/*input
3
-3 -3 2

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int sgn(int x)
{
	if (x < 0)
		return -1;
	else if (x > 0)
		return 1;
	else
		return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	int s = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (abs(-a[i] - 1) > abs(a[i]))//a[i] >= 0
			a[i] = -a[i] - 1;
		s = sgn(s * a[i]);
	}
	if (s == -1)
	{
		int i = min_element(a, a + n) - a;
		a[i] = -a[i] - 1;
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}