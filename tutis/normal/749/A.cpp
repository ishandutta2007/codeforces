/*input
7
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << (n) / 2 << "\n";
	while (n >= 4)
	{
		cout << 2 << " ";
		n -= 2;
	}
	cout << n << "\n";
}