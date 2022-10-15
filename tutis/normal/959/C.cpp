/*input
6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;

	for (int t = 0; t < 1; t++) {	//incorrect
		if (n <= 5)
		{
			cout << -1 << "\n";
			break;
		}
		int k = (n + 2) / 2;
		for (int i = 2; i <= k; i++)
		{
			cout << 1 << " " << i << "\n";
		}
		for (int i = k + 1; i <= n; i++)
		{
			cout << 2 << " " << i << "\n";
		}


	}
	{	//correct
		for (int i = 1; i < n; i++)
			cout << i << " " << i + 1 << "\n";
	}
}