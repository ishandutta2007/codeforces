/*input
1 2
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	ll r, c;
	cin >> r >> c;
	if (r == 1 && c == 1)
	{
		cout << "0\n";
		return 0;
	}
	if (r == 1)
	{
		for (int i = 1; i <= c; i++)
			cout << i + 1 << " ";
		cout << "\n";
		return 0;
	}
	ll A[r][c];
	for (int i = 0; i < r; i++)
	{
		A[i][0] = i + 2;
		for (int j = 1; j < c; j++)
		{
			A[i][j] = A[i][0] * ll(j + r + 1);
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
}