/*input
9
1 3 3 6 7 6 8 8 9
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
template<typename A>
using ordered_set = tree<A, null_type, less<A>, rb_tree_tag, tree_order_statistics_node_update>;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int i = 1;
	int ans = 0;
	while (i <= n)
	{
		int j = i;
		while (i <= j)
		{
			int a;
			cin >> a;
			j = max(j, a);
			i++;
		}
		ans++;
	}
	cout << ans << "\n";
}