/*input
4
43 28 1 91
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int &i : a)
		cin >> i;
	for (int i = 0; i < n; i++)
	{
		int kiek = 0;
		for (int j : a)
		{
			kiek += abs((a[i] - j + 1) % 2);
		}
		if (kiek == 1)
		{
			cout << i + 1 << "\n";
			return 0;
		}
	}
}