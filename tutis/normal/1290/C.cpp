/*input
8 6
00110011
3
1 3 8
5
1 2 5 6 7
2
6 8
2
3 5
2
4 7
1
2

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,aes,avx,avx2")
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename A, typename B>
using Map = tree<A, B, less<A>, rb_tree_tag, tree_order_statistics_node_update>;
int pa[303030];
int k[2][303030];
vector<int>com[303030];
bool valdo[303030];
int vald[303030];
int col[303030];
int smn = 0;
int root(int i)
{
	if (pa[i] == i)
		return i;
	return pa[i] = root(pa[i]);
}
void merge(int a, int b, int d)
{
	d ^= col[a];
	d ^= col[b];
	a = root(a);
	b = root(b);
	if (a == b)
	{
		//assert(d == 0);
		return;
	}
	if (com[b].size() > com[a].size())
		swap(a, b);
	if (valdo[b])
		smn -= k[vald[b]][b];
	else
		smn -= min(k[0][b], k[1][b]);
	if (valdo[a])
		smn -= k[vald[a]][a];
	else
		smn -= min(k[0][a], k[1][a]);
	pa[b] = a;
	valdo[a] |= valdo[b];
	if (valdo[b])
	{
		if (valdo[a])
		{
			//assert(vald[a] == (vald[b] ^ d));
		}
		vald[a] = vald[b] ^ d;
	}
	for (int i : com[b])
	{
		col[i] ^= d;
		k[col[i]][a]++;
		com[a].push_back(i);
	}
	com[b] = {};
	if (valdo[a])
		smn += k[vald[a]][a];
	else
		smn += min(k[0][a], k[1][a]);
}
void sett(int c, int a)
{
	a = root(a);
	if (!valdo[a])
	{
		smn -= min(k[0][a], k[1][a]);
		valdo[a] = true;
		vald[a] = c;
		smn += k[vald[a]][a];
	}
	else
	{
		//assert(vald[a] == c);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, kiek;
	cin >> n >> kiek;
	string s;
	cin >> s;
	vector<int>se[n];
	for (int i = 0; i < kiek; i++)
	{
		int c;
		cin >> c;
		while (c--)
		{
			int x;
			cin >> x;
			x--;
			se[x].push_back(i);
		}
	}
	for (int i = 0; i <= kiek; i++)
	{
		pa[i] = i;
		col[i] = 0;
		com[i] = {i};
		k[col[i]][i]++;
	}
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '1')
		{
			if (se[i].size() == 2)
				merge(se[i][0], se[i][1], 0);
			else if (se[i].size() == 1)
			{
				sett(col[se[i][0]] ^ 1, se[i][0]);
			}
		}
		else
		{
			if (se[i].size() == 2)
				merge(se[i][0], se[i][1], 1);
			else if (se[i].size() == 1)
			{
				sett(col[se[i][0]], se[i][0]);
			}
			else
			{
				assert(false);
			}
		}
		cout << smn << "\n";
	}
}