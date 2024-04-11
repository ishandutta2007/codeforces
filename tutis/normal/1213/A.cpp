/*input

*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[2] = {0, 0};
	while (n--)
	{
		int x;
		cin >> x;
		a[x % 2]++;
	}
	cout << min(a[0], a[1]) << "\n";

}