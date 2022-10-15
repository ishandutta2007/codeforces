/*input
4 5
300 10001 20 20
2 1 3
1 1 310
2 1 3
2 3 3
2 3 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mx = 15;
struct ST
{
	vector<int>mn;
	int l, r;
	ST *left, *right;
	void merg()
	{
		mn = vector<int>(left->mn.size() + right->mn.size());
		merge(left->mn.begin(), left->mn.end(),
		      right->mn.begin(), right->mn.end(),
		      mn.begin());
		while (mn.size() > mx)
			mn.pop_back();
	}
	ST(int l, int r, int a[]): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2, a);
			right = new ST((l + r) / 2 + 1, r, a);
			merg();
		}
		else
		{
			mn = {a[l]};
		}
	}
	void set(int i, int w)
	{
		if (l < r)
		{
			if (i <= (l + r) / 2)
				left->set(i, w);
			else
				right->set(i, w);
			merg();
		}
		else
		{
			mn = {w};
		}
	}
	void get(int x, int y, vector<int>&v)
	{
		if (x <= l && r <= y)
		{
			auto v_ = v;
			v = vector<int>(v.size() + mn.size());
			merge(v_.begin(), v_.end(),
			      mn.begin(), mn.end(),
			      v.begin());
			while (v.size() > mx)
				v.pop_back();
			return;
		}
		if (r < x || y < l)
			return;
		left->get(x, y, v);
		right->get(x, y, v);
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ST medis(1, n, a);
	while (m--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int i, x;
			cin >> i >> x;
			medis.set(i, x);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			vector<int>v;
			medis.get(l, r, v);
			int ans = 2e9 + 100;
			for (int i = 0; i < (int)v.size(); i++)
			{
				for (int j = 0; j < i && v[i] + v[j] < ans; j++)
				{
					int a = v[i];
					int b = v[j];
					int c = a + b;
					bool ok = false;
					while (c > 0 && ok == false)
					{
						int a_ = a % 10;
						if (a == 0)a_ = -1;
						int b_ = b % 10;
						if (b == 0)b_ = -1;
						if (c % 10 != a_ && c % 10 != b_)
							ok = true;
						a /= 10;
						b /= 10;
						c /= 10;
					}
					if (ok)
					{
						ans = v[i] + v[j];
					}
				}
			}
			if (ans > (int)2e9 + 5)
				ans = -1;
			cout << ans << "\n";
		}
	}
}