/*input
9
10 8 15 3 3 10 3 20 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct Fenwick
{
	vector<ll>A;
	int n;
	Fenwick(int n = 1): n(n)
	{
		A = vector<ll>(n + 1, 0);
	}
	inline int lsb(int x)
	{
		return ((x) & (-x));
	}
	void add(int i, ll w)
	{
		for (; i <= n; i += lsb(i))
		{
			A[i] += w;
		}
	}
	ll get(int i)
	{
		i = min(i, n);
		ll ret = 0;
		for (; i > 0; i -= lsb(i))
		{
			ret += A[i];
		}
		return ret;
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cerr.tie(0);
	vector<int>ans;
	int n;
	cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	Fenwick X(n + 1);
	map<int, vector<int>>occ;
	int r = 0;
	for (int i = 1; i <= n; i++)
	{
		if (occ.count(a[i]))
		{
			if (X.get(occ[a[i]].back()) > 0)
			{
				bool radom = false;
				for (pair<int, vector<int>>j : occ)
				{
					int k = j.second.front();
					if (radom == false && j.first != a[i] && k < occ[a[i]].back() && occ[a[i]].back() < j.second.back())
					{
						ans.push_back(j.first);
						ans.push_back(a[i]);
						ans.push_back(j.first);
						ans.push_back(a[i]);
						radom = true;
					}
				}
				if (radom)
				{
					for (pair<int, vector<int>>j : occ)
					{
						int k = j.second.front();
						if (j.second.back() != k)
						{
							X.add(k + 1, -1);
							X.add(j.second.back(), 1);
						}
					}
					occ.clear();
					continue;
				}
			}
		}
		if (occ.count(a[i]) && occ[a[i]].size() >= 2)
		{
			X.add(occ[a[i]].front() + 1, -1);
			X.add(occ[a[i]].back(), 1);
		}
		occ[a[i]].push_back(i);
		if (occ[a[i]].size() >= 2)
		{
			X.add(occ[a[i]].front() + 1, 1);
			X.add(occ[a[i]].back(), -1);
		}
		if (occ[a[i]].size() >= 4)
		{
			ans.push_back(a[i]);
			ans.push_back(a[i]);
			ans.push_back(a[i]);
			ans.push_back(a[i]);
			for (pair<int, vector<int>>j : occ)
			{
				int k = j.second.front();
				if (j.second.back() != k)
				{
					X.add(k + 1, -1);
					X.add(j.second.back(), 1);
				}
			}
			occ.clear();
			continue;
		}
	}
	cout << ans.size() << "\n";
	for (int i : ans)
		cout << i << " ";
}