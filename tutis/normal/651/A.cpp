/*input
3 5

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	int k = 0;
	while (a > 0 && b > 0)
	{
		if (a > b)
			swap(a, b);
		if (b == 1)
			break;
		k++;
		a++;
		b -= 2;
	}
	cout << k << "\n";
}