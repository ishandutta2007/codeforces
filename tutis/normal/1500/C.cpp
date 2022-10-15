/*input
3 3
2 3 2
1 3 3
1 1 2
1 1 2
1 3 3
2 3 2

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using ordered_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using fast_map = cc_hash_table<T, X>;
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(456456);
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
const ll mod = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>>a, b = vector<vector<int>>(n, vector<int>(m));
	a = b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> b[i][j];
	}
	int S[n][m];
	int V[n][m];
	for (int j = 0; j < m; j++)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			S[i][j] = i;
			V[i][j] = i;
			if (i + 1 < n)
			{
				if (b[i][j] <= b[i + 1][j])
					S[i][j] = S[i + 1][j];
				if (b[i][j] == b[i + 1][j])
					V[i][j] = V[i + 1][j];
			}
		}
	}
	vector<pair<int, int>>X;
	X.push_back({0, n - 1});
	vector<int>ans;
	bool ok = true;
	vector<int>cntS(m, 0);
	for (int i = 0; i < m; i++)
		if (S[0][i] >= n - 1)
			cntS[i]++;
	vector<int>cntZ(m, 0);
	for (int i = 0; i < m; i++)
		if (V[0][i] < n - 1)
			cntZ[i]++;
	vector<int>ger;
	for (int i = 0; i < m; i++)
		if (cntS[i] == (int)X.size() && cntZ[i] > 0)
			ger.push_back(i);
	while (!ger.empty())
	{
		int i = ger.back();
		vector<pair<int, int>>X_;
		for (const pair<int, int> &v : X)
		{
			if (V[v.first][i] >= v.second)
				X_.push_back(v);
			else
			{
				for (int ii = 0; ii < m; ii++)
				{
					if (S[v.first][ii] >= v.second)
						cntS[ii]--;
					if (S[v.first][ii] >= V[v.first][i])
						cntS[ii]++;
					if (S[V[v.first][i] + 1][ii] >= v.second)
						cntS[ii]++;
					if (V[v.first][ii] < v.second)
						cntZ[ii]--;
					if (V[v.first][ii] < V[v.first][i])
						cntZ[ii]++;
					if (V[V[v.first][i] + 1][ii] < v.second)
						cntZ[ii]++;
				}
				X_.push_back({v.first, V[v.first][i]});
				X_.push_back({V[v.first][i] + 1, v.second});
			}
		}
		X = X_;
		ans.push_back(i);
		ger.clear();
		for (int i = 0; i < m; i++)
			if (cntS[i] == (int)X.size() && cntZ[i] > 0)
				ger.push_back(i);
	}
	reverse(ans.begin(), ans.end());
	for (int i : ans)
	{
		stable_sort(a.begin(), a.end(), [&](const vector<int>& x, const vector<int>& y) {return x[i] < y[i];});
	}
	if (a == b)
	{
		cout << ans.size() << "\n";
		for (int i : ans)
			cout << i + 1 << " ";
	}
	else
	{
		cout << "-1\n";
	}
}