/*input
8
NNN
NNN
BBNNBBBN
NNNBNN
B
NNN
NNNNBNN
NNNNNNNNNNNNNNNBNNNNNNNBNB

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int x[n], y[n];
	for (int i = 0; i < n; i++)
	{
		x[i] = 0;
		y[i] = 0;
		string s;
		cin >> s;
		for (char c : s)
		{
			if (c == 'B')
				x[i]++;
			else
				y[i]++;
		}
		//cout << x[i] << " " << y[i] << endl;
	}
	ll lo = 0;
	ll hi = 1e6;
	while (lo <= hi)
	{
		ll k = (lo + hi) / 2;
		bool zaibis = lo == hi;
		ll lox = 0;
		ll loy = 0;
		ll hix = 1e6;
		ll hiy = 1e6;
		ll lo1 = -1e8;
		ll hi1 = 1e8;
		for (int i = 0; i < n; i++)
		{
			lox = max(lox, x[i] - k);
			loy = max(loy, y[i] - k);

			hix = min(hix, x[i] + k);
			hiy = min(hiy, y[i] + k);

			lo1 = max(lo1, x[i] - y[i] - k);
			hi1 = min(hi1, x[i] - y[i] + k);
		}
		ll xx = hix;
		ll yy = hiy;
		if (xx - yy < lo1)
		{
			//xx-yy+d=lo1
			ll d = lo1 - xx + yy;
			yy -= d;
		}
		if (xx - yy > hi1)
		{
			//xx - yy+d = hi1;
			ll d = hi1 - xx + yy;
			xx += d;
		}
		if (xx >= 0 && yy >= 0 && xx + yy > 0 &&
		        lox <= xx && xx <= hix &&
		        loy <= yy && yy <= hiy &&
		        lo1 <= xx - yy && xx - yy <= hi1)
		{
			hi = k;
		}
		else
			lo = k + 1;
		if (zaibis)
		{
			cout << k << "\n";
			cout << string(xx, 'B') << string(yy, 'N') << "\n";
			return 0;
		}
	}
	return 0;
}