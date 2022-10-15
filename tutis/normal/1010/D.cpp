/*input
10
AND 9 4
IN 1
IN 1
XOR 6 5
AND 3 7
IN 0
NOT 10
IN 1
IN 1
AND 2 8
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
vector<int>adj[1000000 + 1];
string x[1000000 + 1];
int val[1000000 + 1];
int siaip[1000000 + 1];
void dfs(int i)
{
	for (int j : adj[i])
		dfs(j);
	if (x[i] == "IN")
	{
		siaip[i] = val[i];
	}
	if (x[i] == "AND")
	{
		siaip[i] = siaip[adj[i][0]] & siaip[adj[i][1]];
	}
	if (x[i] == "OR")
	{
		siaip[i] = siaip[adj[i][0]] | siaip[adj[i][1]];
	}
	if (x[i] == "XOR")
	{
		siaip[i] = siaip[adj[i][0]] ^ siaip[adj[i][1]];
	}
	if (x[i] == "NOT")
	{
		siaip[i] = 1 - siaip[adj[i][0]];
	}
}
int kita[1000000 + 1];
vector<int>J[2];
void dfs1(int i, int p)
{
	if (x[i] == "IN")
	{
		int v = 0;
		for (int j : adj[p])
			if (j != i)
				v = siaip[j];
		int vx = 1 - val[i];
		if (x[p] == "NOT")
		{
			kita[i] = J[1 - vx].back();
		}
		if (x[p] == "XOR")
		{
			kita[i] = J[v ^ vx].back();
		}
		if (x[p] == "AND")
		{
			kita[i] = J[v & vx].back();
		}
		if (x[p] == "OR")
		{
			kita[i] = J[v | vx].back();
		}
		return;
	}
	if (i == 1)
	{
		J[0].push_back(0);
		J[1].push_back(1);
	}
	else
	{
		int v = 0;
		for (int j : adj[p])
			if (j != i)
				v = siaip[j];
		int a[2] = {J[0].back(), J[1].back()};
		if (x[p] == "NOT")
		{
			J[0].push_back(a[1]);
			J[1].push_back(a[0]);
		}
		if (x[p] == "XOR")
		{
			J[0].push_back(a[0 ^ v]);
			J[1].push_back(a[1 ^ v]);
		}
		if (x[p] == "AND")
		{
			J[0].push_back(a[0 & v]);
			J[1].push_back(a[1 & v]);
		}
		if (x[p] == "OR")
		{
			J[0].push_back(a[0 | v]);
			J[1].push_back(a[1 | v]);
		}
	}
	for (int j : adj[i])
	{
		dfs1(j, i);
	}
	J[0].pop_back();
	J[1].pop_back();
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cerr.tie(0);
	int n;
	cin >> n;
	vector<int>ins;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i];
		if (x[i] == "IN")
		{
			int c;
			cin >> c;
			val[i] = c;
			ins.push_back(i);
			continue;
		}
		int k = 2;
		if (x[i] == "NOT")
		{
			k = 1;
		}
		while (k--)
		{
			int j;
			cin >> j;
			adj[i].push_back(j);
		}
	}
	dfs(1);
	dfs1(1, 1);
	for (int i : ins)
		cout << kita[i];
}