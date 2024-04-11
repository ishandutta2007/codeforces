/*input
4
1 2 3 4
3
2 3
1 2 2
2 1
*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct ST
{
	int l, r;
	ST *left, *right;
	int bent = -1;
	ST(int l, int r): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2);
			right = new ST((l + r) / 2 + 1, r);
		}
		else
		{
			cin >> bent;
		}
	}
	void set(int i, int v)
	{
		if (l < r)
		{
			left->bent = max(left->bent, bent);
			right->bent = max(right->bent, bent);
			bent = -1;
			if (i <= (l + r) / 2)
				left->set(i, v);
			else
				right->set(i, v);
		}
		else
		{
			bent = v;
		}
	}
	void print()
	{
		if (l < r)
		{
			left->bent = max(left->bent, bent);
			right->bent = max(right->bent, bent);
			left->print();
			right->print();
		}
		else
		{
			cout << bent << " ";
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ST medis(1, n);
	int q;
	cin >> q;
	while (q--)
	{
		int t, p;
		cin >> t >> p;
		if (t == 1)
		{
			int v;
			cin >> v;
			medis.set(p, v);
		}
		else
		{
			medis.bent = max(medis.bent, p);
		}
	}
	medis.print();
}