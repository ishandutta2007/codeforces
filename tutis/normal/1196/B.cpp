/*input
3
5 3
7 18 3 14 1
5 4
1 2 3 4 5
6 2
1 2 8 4 10 2
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll q;
	cin >> q;
	while (q--)
	{
		int n, k;
		cin >> n >> k;
		int a[n + 1];
		int suma = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			a[i] %= 2;
			suma += a[i];
		}
		vector<int>r;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 1)
				r.push_back(i);
		}
		while (r.size() >= k)
			r.pop_back();
		r.push_back(n);
		if (r.size() != k || suma % 2 != k % 2)
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (int i : r)
			cout << i << " ";
		cout << "\n";
	}
}