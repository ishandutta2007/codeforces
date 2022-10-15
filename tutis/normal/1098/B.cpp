/*input
3 5
AGCAG
AGCAG
AGCAG

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
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(123);
const ll mod = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	string A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];
	set<char>C = {'A', 'C', 'G', 'T'};
	char aa, bb, cc, dd;
	bool ww;
	int mn = n * m + 1;
	for (char a : C)
	{
		for (char b : C)
		{
			for (char c : C)
			{
				for (char d : C)
				{
					if (a == b || b == c || c == d || a == c || d == b || a == d)
						continue;
					for (bool w : {false, true})
					{
						if (w)
						{
							int sum = 0;
							for (int i = 0; i < n; i++)
							{
								int k0 = 0, k1 = 0;
								for (int j = 0; j < m; j++)
								{
									if (i % 2 == 0)
									{
										if (j % 2 == 0 && A[i][j] != a)
											k0++;
										if (j % 2 == 1 && A[i][j] != b)
											k0++;
										if (j % 2 == 0 && A[i][j] != b)
											k1++;
										if (j % 2 == 1 && A[i][j] != a)
											k1++;
									}
									else
									{
										if (j % 2 == 0 && A[i][j] != c)
											k0++;
										if (j % 2 == 1 && A[i][j] != d)
											k0++;
										if (j % 2 == 0 && A[i][j] != d)
											k1++;
										if (j % 2 == 1 && A[i][j] != c)
											k1++;
									}
								}
								sum += min(k0, k1);
							}
							if (sum < mn)
							{
								mn = sum;
								aa = a;
								bb = b;
								cc = c;
								dd = d;
								ww = w;
							}
						}
						else
						{
							int sum = 0;
							for (int j = 0; j < m; j++)
							{
								int k0 = 0, k1 = 0;
								for (int i = 0; i < n; i++)
								{
									if (j % 2 == 0)
									{
										if (i % 2 == 0 && A[i][j] != a)
											k0++;
										if (i % 2 == 1 && A[i][j] != b)
											k0++;
										if (i % 2 == 0 && A[i][j] != b)
											k1++;
										if (i % 2 == 1 && A[i][j] != a)
											k1++;
									}
									else
									{
										if (i % 2 == 0 && A[i][j] != c)
											k0++;
										if (i % 2 == 1 && A[i][j] != d)
											k0++;
										if (i % 2 == 0 && A[i][j] != d)
											k1++;
										if (i % 2 == 1 && A[i][j] != c)
											k1++;
									}
								}
								sum += min(k0, k1);
							}
							if (sum < mn)
							{
								mn = sum;
								aa = a;
								bb = b;
								cc = c;
								dd = d;
								ww = w;
							}
						}
					}
				}
			}
		}
	}
	if (ww)
	{
		for (int i = 0; i < n; i++)
		{
			int k0 = 0, k1 = 0;
			for (int j = 0; j < m; j++)
			{
				if (i % 2 == 0)
				{
					if (j % 2 == 0 && A[i][j] != aa)
						k0++;
					if (j % 2 == 1 && A[i][j] != bb)
						k0++;
					if (j % 2 == 0 && A[i][j] != bb)
						k1++;
					if (j % 2 == 1 && A[i][j] != aa)
						k1++;
				}
				else
				{
					if (j % 2 == 0 && A[i][j] != cc)
						k0++;
					if (j % 2 == 1 && A[i][j] != dd)
						k0++;
					if (j % 2 == 0 && A[i][j] != dd)
						k1++;
					if (j % 2 == 1 && A[i][j] != cc)
						k1++;
				}
			}
			if (k0 < k1)
			{
				for (int j = 0; j < m; j++)
				{
					if (i % 2 == 0)
					{
						if (j % 2 == 0)
							A[i][j] = aa;
						if (j % 2 == 1)
							A[i][j] = bb;
					}
					else
					{
						if (j % 2 == 0)
							A[i][j] = cc;
						if (j % 2 == 1)
							A[i][j] = dd;
					}
				}
			}
			else
			{
				for (int j = 0; j < m; j++)
				{
					if (i % 2 == 0)
					{
						if (j % 2 == 0)
							A[i][j] = bb;
						if (j % 2 == 1)
							A[i][j] = aa;
					}
					else
					{
						if (j % 2 == 0)
							A[i][j] = dd;
						if (j % 2 == 1)
							A[i][j] = cc;
					}
				}
			}
		}
	}
	else
	{
		for (int j = 0; j < m; j++)
		{
			int k0 = 0, k1 = 0;
			for (int i = 0; i < n; i++)
			{
				if (j % 2 == 0)
				{
					if (i % 2 == 0 && A[i][j] != aa)
						k0++;
					if (i % 2 == 1 && A[i][j] != bb)
						k0++;
					if (i % 2 == 0 && A[i][j] != bb)
						k1++;
					if (i % 2 == 1 && A[i][j] != aa)
						k1++;
				}
				else
				{
					if (i % 2 == 0 && A[i][j] != cc)
						k0++;
					if (i % 2 == 1 && A[i][j] != dd)
						k0++;
					if (i % 2 == 0 && A[i][j] != dd)
						k1++;
					if (i % 2 == 1 && A[i][j] != cc)
						k1++;
				}
			}
			if (k0 < k1)
			{
				for (int i = 0; i < n; i++)
				{
					if (j % 2 == 0)
					{
						if (i % 2 == 0)
							A[i][j] = aa;
						if (i % 2 == 1)
							A[i][j] = bb;
					}
					else
					{
						if (i % 2 == 0)
							A[i][j] = cc;
						if (i % 2 == 1)
							A[i][j] = dd;
					}
				}
			}
			else
			{
				for (int i = 0; i < n; i++)
				{
					if (j % 2 == 0)
					{
						if (i % 2 == 0)
							A[i][j] = bb;
						if (i % 2 == 1)
							A[i][j] = aa;
					}
					else
					{
						if (i % 2 == 0)
							A[i][j] = dd;
						if (i % 2 == 1)
							A[i][j] = cc;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << A[i] << "\n";
}