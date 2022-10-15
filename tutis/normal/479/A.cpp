/*input
1
2
3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool composite(int n)
{
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int a, b, c;
	cin >> a >> b >> c;
	cout << max({
		a + b + c,
		a * b * c,
		a * (b + c),
		(a + b) * c,
		a * b + c,
		a + b * c
	}) << endl;
}