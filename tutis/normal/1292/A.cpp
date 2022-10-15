/*input
5 5
2 3
1 4
2 4
2 3
1 4
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1000000007;
struct ST
{
	bool ok = true;
	bool A[2][2] = {{true, true}, {true, true}};
	int l, r;
	ST *left, *right;
	ST(int l, int r): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2);
			right = new ST((l + r) / 2 + 1, r);
		}
	}
	void toggle(int h, int x)
	{
		if (l == r)
		{
			A[h][0] ^= true;
			A[h][1] ^= true;
			ok = A[0][0] | A[1][1];
		}
		else
		{
			if (x <= (l + r) / 2)
				left->toggle(h, x);
			else
				right->toggle(h, x);
			ok = (left->A[0][1] && right->A[0][0]) || (left->A[1][1] && right->A[1][0]);
			ok &= left->ok && right->ok;
			A[0][0] = left->A[0][0];
			A[1][0] = left->A[1][0];
			A[0][1] = right->A[0][1];
			A[1][1] = right->A[1][1];
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	ST medis(0, n - 1);
	for (int i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		medis.toggle(x, y);
		if (medis.ok && medis.A[0][0] && medis.A[1][1])
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}