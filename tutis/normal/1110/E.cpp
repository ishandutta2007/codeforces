/*input
4
7 2 4 12
7 15 10 12

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
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int b[n];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	if (a[0] != b[0] || a[n - 1] != b[n - 1])
	{
		cout << "No\n";
		return 0;
	}
	vector<int>x, y;
	for (int i = 1; i < n; i++)
		x.push_back(a[i] - a[i - 1]);
	for (int i = 1; i < n; i++)
		y.push_back(b[i] - b[i - 1]);
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	if (x == y)
		cout << "Yes\n";
	else
		cout << "No\n";
}