/*input
15 6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int ceiling(int a, int b)
{
	if (a % b == 0)
		return a / b;
	return a / b + 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	cout << ceiling(2 * n, k) + ceiling(5 * n, k) + ceiling(8 * n, k) << "\n";
}