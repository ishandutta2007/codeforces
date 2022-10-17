#include <bits/stdc++.h>
using namespace std;
int t, a, b, c, n;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> a >> b >> c >> n;
		n -= 3 * max(a, max(b, c)) - a - b - c;
		puts(n % 3 == 0 && n >= 0 ? "YES" : "NO");
	}
	return 0;
}