/*input
100
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
	vector<int>divs[n + 2];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2 * i; j <= n; j += i)
			divs[j].push_back(i);
	}
	int a[n + 2];
	fill_n(a, n + 2, 0);
	int timer = 0;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] == 0)
		{
			timer++;
			for (int j = i; j <= n; j += i)
				a[j] = timer;
		}
		cout << a[i] << "\n";
	}
}