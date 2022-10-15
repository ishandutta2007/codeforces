/*input
2
1 1

*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<bool>c(2, false);
	for (int i = 0; i < n; i++)
		c[a[i] % 2] = true;
	if (c[0] && c[1])
	{
		sort(a, a + n);
	}
	for (int i : a)
		cout << i << " ";
}