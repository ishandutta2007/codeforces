/*input

*/
#include <bits/stdc++.h>
using namespace std;
int ans = 1;
void solve(int a[], int l, int r)
{
	if (is_sorted(a + l, a + (r + 1)))
	{
		ans = max(ans, r - l + 1);
		return;
	}
	solve(a, l, (l + r) / 2);
	solve(a, (l + r) / 2 + 1, r);
}
int main()
{
	int n;
	cin >> n;
	int a[n];
for(int &i: a)
cin>>i;
	solve(a, 0, n - 1);
	cout << ans << "\n";
}