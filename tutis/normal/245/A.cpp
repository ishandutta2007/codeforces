/*input
11
1 8 2
1 6 4
1 9 1
1 7 3
2 0 10
2 0 10
1 8 2
2 2 8
2 6 4
2 7 3
2 9 1
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
string f(int x)
{
	if (x >= 0)
		return "LIVE";
	else
		return "DEAD";
}
int main()
{
	int ans = 0;
	ios_base::sync_with_stdio(false);
	int A[2] = {0, 0};
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t, x, y;
		cin >> t >> x >> y;
		A[t - 1] += x;
		A[t - 1] -= y;
	}
	cout << f(A[0]) << "\n" << f(A[1]) << "\n";
}