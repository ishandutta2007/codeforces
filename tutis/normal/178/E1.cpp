/***
1
1
***/
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
template<int N>
struct DSU
{
	pair<int, int> pa[N][N];
	int sz[N][N];
	DSU()
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				pa[i][j] = make_pair(i, j);
				sz[i][j] = 1;
			}
	}
	pair<int, int> &par(pair<int, int>i)
	{
		return pa[i.first][i.second];
	}
	int &size(pair<int, int>i)
	{
		return sz[root(i).first][root(i).second];
	}
	pair<int, int> root(pair<int, int>i)
	{
		if (i == par(i))
			return i;
		return par(i) = root(par(i));
	}
	void merge(pair<int, int>a, pair<int, int>b)
	{
		if (root(a) == root(b))
			return;
		if (size(a) > size(b))
			swap(a, b);
		size(b) += size(a);
		par(root(a)) = root(b);
	}
};
ld atstum(pair<int, int>a, pair<int, int>b)
{
	return sqrtl(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}
bool circle(vector<pair<int, int>>x)
{
	ld d = 0;
	pair<int, int>a = x[0];
	for (pair<int, int>b : x)
		if (b.first < a.first)
			a = b;
	for (pair<int, int>b : x)
	{
		d = max(d, atstum(a, b));
	}
	ld exp = 0.785398163397 * (d * d);
	if (exp / ld(x.size()) < 0.95)
		return false;
	if (exp / ld(x.size()) > 1.05)
		return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	int A[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	DSU<2000> X;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] == 1)
			{
				if (i + 1 < n)
					if (A[i + 1][j] == 1)
						X.merge(make_pair(i, j), make_pair(i + 1, j));
				if (j + 1 < n)
					if (A[i][j + 1] == 1)
						X.merge(make_pair(i, j), make_pair(i, j + 1));
				if (i + 1 < n && j + 1 < n)
					if (A[i + 1][j + 1] == 1)
						X.merge(make_pair(i, j), make_pair(i + 1, j + 1));
			}
		}
	}
	vector<pair<int, int>>Y[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			Y[X.root(make_pair(i, j)).first][X.root(make_pair(i, j)).second].push_back(make_pair(i, j));
		}
	int sqr = 0;
	int cir = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Y[i][j].size() >= 100)
			{
				if (circle(Y[i][j]))
					cir++;
				else
					sqr++;
			}
		}
	}
	cout << cir << " " << sqr << endl;
}