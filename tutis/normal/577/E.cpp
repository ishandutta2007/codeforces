/*input
5
0 7
8 10
3 4
5 0
9 12
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int x[n];
	int y[n];
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	int a[n];
	iota(a, a + n, 0);
	sort(a, a + n, [&](int i, int j) {
		if (x[i] / 1000 != x[j] / 1000)
			return (x[i] / 1000) < (x[j] / 1000);
		if ((x[i] / 1000) % 2 == 0)
			return y[i] < y[j];
		return y[i] > y[j];
	});
	for (int i = 0; i < n; i++)
		cout << 1 + a[i] << " ";
}/**/