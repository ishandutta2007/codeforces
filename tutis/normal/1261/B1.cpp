/*input
7
1 2 1 3 1 2 1
9
2 1
2 2
3 1
3 2
3 3
1 1
7 1
7 7
7 4

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
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int p[n];
	iota(p, p + n, 1);
	sort(p, p + n, [&](int i, int j) {if (a[i] != a[j])return a[i] > a[j]; else return i < j;});
	int m;
	cin >> m;
	while (m--)
	{
		int k, i;
		cin >> k >> i;
		set<int>b;
		for (int j = 0; j < k; j++)
		{
			b.insert(p[j]);
		}
		while (b.size() > i)
			b.erase(--b.end());
		cout << a[*(--b.end())] << "\n";
	}
}