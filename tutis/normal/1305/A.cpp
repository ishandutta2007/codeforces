/*input
2
3
1 8 5
8 4 5
3
1 7 5
6 1 2

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,aes,avx,avx2")
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename A, typename B>
using Map = tree<A, B, less<A>, rb_tree_tag, tree_order_statistics_node_update>;
const ll mod = 1000000000 + 7;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		int b[n];
		for (int &i : a)
			cin >> i;
		for (int &i : b)
			cin >> i;
		sort(a, a + n);
		sort(b, b + n);
		for (int &i : a)
			cout << i << " ";
		cout << "\n";
		for (int &i : b)
			cout << i << " ";
		cout << "\n";
	}
}