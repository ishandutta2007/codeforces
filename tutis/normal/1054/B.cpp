/*input
4
0 1 2 239
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
	set<int>X;
	int mx = 0;
	for (int i = 0; i < n; i++)
	{
		while (X.count(mx))
			mx++;
		if (a[i] > mx)
		{
			cout << i + 1 << "\n";
			return 0;
		}
		X.insert(a[i]);
	}
	cout << "-1\n";
}