/*input
3 5
2 2
1 2
5 5
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
	set<int>X;
	for (int i = 1; i <= m; i++)
		X.insert(i);
	while (n--)
	{
		int l, r;
		cin >> l >> r;
		while (true)
		{
			auto it = X.lower_bound(l);
			if (it != X.end() && *it <= r)
			{
				X.erase(it);
			}
			else
				break;
		}
	}
	cout << X.size() << "\n";
	for (int i : X)
		cout << i << " ";
}