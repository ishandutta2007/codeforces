/*input
6 4
()(())
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	bool a[n];
	fill_n(a, n, false);
	int c = k / 2;
	for (int i = 0; i < n; i++)
		if (s[i] == '(' && c > 0)
		{
			a[i] = true;
			c--;
		}
	c = k / 2;
	for (int i = n - 1; i >= 0; i--)
		if (s[i] == ')' && c > 0)
		{
			a[i] = true;
			c--;
		}
	for (int i = 0; i < n; i++)
		if (a[i])
			cout << s[i];
}