/*input
4
5 3 4
2 1 0
3 5 5
4 10 6

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int r = a - b + c;
		int l = a - b - c;
		l = max(l, 1);
		cout << max(0, (r - l + 1 + 1) / 2) << "\n";
	}
}