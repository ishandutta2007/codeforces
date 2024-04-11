/*input
1
2
3
4
12
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int a, b, c, d, n;
	cin >> a >> b >> c >> d >> n;
	int x[n];
	fill_n(x, n, 0);
	for (int t : {a, b, c, d})
		for (int i = t - 1; i < n; i += t)
			x[i] = 1;
	cout << accumulate(x, x + n, 0) << "\n";
}