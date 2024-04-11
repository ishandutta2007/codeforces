/*input
4 6
10 12 10 7 5 22
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int A[m];
	for (int &i : A)
		cin >> i;
	sort(A, A + m);
	int ans = A[m - 1];
	for (int i = 0; i + n - 1 < m; i++)
	{
		ans = min(ans, A[i + n - 1] - A[i]);
	}
	cout << ans << "\n";
}