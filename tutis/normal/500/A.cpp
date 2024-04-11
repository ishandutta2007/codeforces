/*input
8 5
1 2 1 2 1 1 1

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, t;
	cin >> n >> t;
	int a[n];
	for (int i = 1; i < n; i++)
		cin >> a[i];
	bool ok[n + 1];
	fill_n(ok, n + 1, false);
	ok[t] = true;
	for (int i = n - 1; i >= 1; i--)
		ok[i] |= ok[i + a[i]];
	if (ok[1])
		cout << "YES\n";
	else
		cout << "NO\n";
}