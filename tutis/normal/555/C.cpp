/*input
10 6
2 9 U
10 1 U
1 10 U
8 3 L
10 1 L
6 5 U
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ST
{
	int l, r;
	ST *left;
	ST *right;
	int X = 0;
	int Y = 0;
	ST(int i, int j, const vector<int> &A)
	{
		l = A[i];
		r = A[j];
		if (i < j)
		{
			left = new ST(i, (i + j) / 2, A);
			right = new ST((i + j) / 2 + 1, j, A);
		}
	}
	void setX(int x, int y, int w)
	{
		if (x <= l && r <= y)
		{
			X = max(X, w);
			return;
		}
		if (r < x || y < l)
			return;
		left->setX(x, y, w);
		right->setX(x, y, w);
	}
	void setY(int x, int y, int w)
	{
		if (x <= l && r <= y)
		{
			Y = max(Y, w);
			return;
		}
		if (r < x || y < l)
			return;
		left->setY(x, y, w);
		right->setY(x, y, w);
	}
	int xx(int i)
	{
		if (l <= i && i <= r)
		{
			if (l < r)
			{
				return max({X, left->xx(i), right->xx(i)});
			}
			else
				return X;
		}
		else
			return 0;
	}
	int yy(int i)
	{
		if (l <= i && i <= r)
		{
			if (l < r)
			{
				return max({Y, left->yy(i), right->yy(i)});
			}
			else
				return Y;
		}
		else
			return 0;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	int x[q], y[q];
	char c[q];
	vector<int>A;
	for (int i = 0; i < q; i++)
	{
		cin >> x[i] >> y[i] >> c[i];
		A.push_back(x[i]);
		A.push_back(y[i]);
	}
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	ST X(0, A.size() - 1, A);
	for (int i = 0; i < q; i++)
	{
		if (c[i] == 'L')
		{
			int x1 = X.xx(y[i]);
			X.setY(x1, x[i], y[i]);
			X.setX(y[i], y[i], x[i]);
			cout << x[i] - x1 << "\n";
		}
		else
		{
			int y1 = X.yy(x[i]);
			X.setX(y1, y[i], x[i]);
			X.setY(x[i], x[i], y[i]);
			cout << y[i] - y1 << "\n";
		}
	}
}