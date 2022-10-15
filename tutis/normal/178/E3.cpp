/*input
2000
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
	if (exp / ld(x.size()) < 0.9)
		return false;
	if (exp / ld(x.size()) > 1.1)
		return false;
	return true;
}
int B[700][700];
int A[2000][2000];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	srand(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			B[i / 4][j / 4] += A[i][j];
	for (int i = 0; i < 700; i++)
		for (int j = 0; j < 700; j++)
			if (B[i][j] >= 8)
				B[i][j] = 1;
			else
				B[i][j] = 0;
	int sqr = 0;
	int cir = 0;
	int dx[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1};
	int dy[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1};
	for (int i = 0; i < 666; i++)
	{
		for (int j = 0; j < 666; j++)
		{
			if (B[i][j])
			{
				vector<pair<int, int>>Y;
				B[i][j] = 0;
				queue<pair<int, int>>Q;
				Q.push({i, j});
				while (!Q.empty())
				{
					int x = Q.front().first;
					int y = Q.front().second;
					Y.push_back(Q.front());
					Q.pop();
					for (int t = 0; t < 9; t++)
					{
						if (x + dx[t] >= 0 && y + dy[t] >= 0 && B[x + dx[t]][y + dy[t]])
						{
							B[x + dx[t]][y + dy[t]] = 0;
							Q.push({x + dx[t], y + dy[t]});
						}
					}
				}
				if (Y.size() >= 7)
				{
					if (circle(Y))
						cir++;
					else
						sqr++;
				}
			}
		}
	}
	cout << cir << " " << sqr << endl;
}