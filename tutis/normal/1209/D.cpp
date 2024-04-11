/*input
5 4
1 2
4 3
1 4
3 4

*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int pa[101010];
int root(int x)
{
	if (pa[x] == x)
		return x;
	return pa[x] = root(pa[x]);
}
int main()
{
	iota(pa, pa + 101010, 0);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		x = root(x);
		y = root(y);
		if (x != y)
		{
			pa[x] = y;
		}
		else
			ans++;
	}
	cout << ans << "\n";
}