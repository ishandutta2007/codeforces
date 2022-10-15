/*input
7
2 -3
-2 -3
3 0
-3 -1
1 -2
2 -2
-1 0
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
template<typename A>
using  ordered_set = tree <A, ll, less<A>, rb_tree_tag, tree_order_statistics_node_update >;
struct DISSU
{
	vector<int>pa;
	DISSU(int n = 1)
	{
		pa = vector<int>(n + 3, -1);
	}
	int root(int i)
	{
		if (pa[i] < 0)
			return i;
		return pa[i] = root(pa[i]);
	}
	int size(int i)
	{
		return -pa[root(i)];
	}
	int merge(int a, int b)
	{
		a = root(a);
		b = root(b);
		if (a == b)
			return a;
		if (pa[a] < pa[b])
			swap(a, b);
		pa[b] += pa[a];
		pa[a] = b;
		return b;
	}
};
ll DIS[3000][3000];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	pair<ll, ll> x_y[n];
	for (int i = 0; i < n; i++)
		cin >> x_y[i].first >> x_y[i].second;
	random_shuffle(x_y, x_y + n);
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			DIS[i][j] = DIS[j][i] = (x_y[j].first - x_y[i].first) * (x_y[j].first - x_y[i].first) +
			                        (x_y[j].second - x_y[i].second) * (x_y[j].second - x_y[i].second);
	vector<pair<int, int>>X;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			X.push_back({i, j});
		}
	sort(X.begin(), X.end(), [&](pair<int, int> a, pair<int, int> b) {return DIS[a.first][a.second] > DIS[b.first][b.second];});
	bitset<3000>A[n];
	for (pair<int, int>a : X)
	{
		int i = a.first;
		int j = a.second;
		A[i][j] = true;
		A[j][i] = true;
		if ((A[i]&A[j]).any())
		{
			cout << fixed << setprecision(30) << sqrtl(DIS[i][j]) * 0.5 << "\n";
			return 0;
		}
	}
	cout << fixed << setprecision(30) << 0 << "\n";
}