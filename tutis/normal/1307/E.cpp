/*input
5 2
1 1 1 1 1
1 2
1 3

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7;
int s[5050];
bitset<5050>A[5050];
int L[5050][5050];
vector<pair<int, int>>X[5050];
vector<pair<int, int>>Y[5050];
int SUM[5050][5050];
ll S[5050];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		S[s[i]]++;
	}
	for (int i = 0; i <= n + 1; i++)
	{
		if (i != 0)
			for (int k = 0; k < 5050; k++)
				L[i][k] = L[i - 1][k];
		L[i][s[i]]++;
	}
	for (int i = n - 1; i >= 0; i--)
		for (int i = 0; i < m; i++)
		{
			int f, h;
			cin >> f >> h;
			A[f][h] = true;
		}
	for (int x = 1; x <= n; x++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (s[i] == x && A[x][L[i][x]])
				X[x].push_back({i, L[i][x]});
			if (s[i] == x && A[x][S[x] - L[i - 1][x]])
				Y[x].push_back({i, S[x] - L[i - 1][x]});
		}
	}
	pair<ll, ll>ans = {0, 0};
	for (int x = 1; x <= n; x++)
	{
		for (pair<ll, ll>a : X[x])
		{
			for (pair<ll, ll>b : Y[x])
			{
				if (a.first > b.first || a.second == b.second)
					continue;
				SUM[x][a.first]++;
				SUM[x][b.first]--;
			}
		}
		for (int i = 1; i <= n; i++)
			SUM[x][i] += SUM[x][i - 1];
	}
	for (int mxl = 0; mxl <= n; mxl++)
	{
		if (mxl != 0 && A[s[mxl]][L[mxl][s[mxl]]] == 0)
			continue;
		ll kiek = 0;
		ll budu = 1;
		for (int x = 1; x <= n; x++)
		{
			if (x != s[mxl])
			{
				ll b1 = 0;
				ll b2 = SUM[x][mxl];
				for (pair<ll, ll>a : X[x])
				{
					if (a.first <= mxl)
						b1++;
				}
				for (pair<ll, ll>a : Y[x])
				{
					if (a.first > mxl)
						b1++;
				}
				if (b2 != 0)
				{
					kiek += 2;
					budu = (budu * b2) % mod;
				}
				else if (b1 != 0)
				{
					kiek++;
					budu = (budu * b1) % mod;
				}
			}
			else {
				if (A[x][L[mxl][x]] == 0)
				{
					budu = 0;
					break;
				}
				ll k = 0;
				for (pair<ll, ll>b : Y[x])
				{
					if (b.first > mxl && b.second != L[mxl][x])
						k++;
				}
				if (k != 0)
				{
					kiek += 2;
					budu = (budu * k) % mod;
				}
				else
					kiek++;
			}
		}
		if (budu == 0)
			kiek = -1;
		if (kiek < ans.first)
			continue;
		if (kiek == ans.first)
			ans.second = (ans.second + budu) % mod;
		else
			ans = {kiek, budu};
	}
	cout << ans.first << " " << ans.second << "\n";
}