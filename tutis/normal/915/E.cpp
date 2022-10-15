/***
4
6
1 2 1
3 4 1
2 3 2
1 3 2
2 4 1
1 4 2
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct medis
{
	int l, r;
	medis *left, *right;
	int kiek = 0;
	int lazy = false;
	int x = 1;
	int w = 0;
	medis() {}
	medis(vector<int> &a, int i, int j)
	{
		l = a[i];
		r = a[j];
		if (l < r)
		{
			int sz = 1;
			while (2 * sz < (j - i + 1))
				sz *= 2;
			left = new medis(a, i, i + sz - 1);
			right = new medis(a, i + sz, j);
			w = right->l - left->r - 1;
			kiek = left->kiek + right->kiek + w * x;
		}
		else
		{
			kiek = 1;
		}
	}
	void fix()
	{
		if (lazy)
		{
			kiek = (r - l + 1) * x;
			if (l < r)
			{
				left->lazy = true;
				left->x = x;
				right->lazy = true;
				right->x = x;
			}
			lazy = false;
		}
	}
	void set(int a, int b, int k)
	{
		if (a <= l && r <= b)
		{
			lazy = true;
			x = k;
			fix();
			return;
		}
		fix();
		if (r < a || b < l)
			return;
		left->set(a, b, k);
		right->set(a, b, k);
		if (a <= left->r && right->l <= b)
			x = k;
		kiek = left->kiek + right->kiek + w * x;
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int q;
	cin >> q;
	int l[q], r[q], k[q];
	vector<int>A;
	for (int i = 0; i < q; i++)
	{
		cin >> l[i] >> r[i] >> k[i];
		A.push_back(l[i]);
		A.push_back(r[i]);
	}
	A.push_back(1);
	A.push_back(n);
	sort( A.begin(), A.end() );
	A.erase( unique( A.begin(), A.end() ), A.end() );
	medis XX(A, 0, int(A.size() - 1));
	for (int i = 0; i < q; i++)
	{
		if (k[i] == 1)
			XX.set(l[i], r[i], 0);
		else
			XX.set(l[i], r[i], 1);
		cout << XX.kiek << '\n';
	}
}