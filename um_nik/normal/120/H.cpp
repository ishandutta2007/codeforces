#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
using namespace std;

const int N = 220;
int n, m;
map<string, int> names;
string names2[N * N];
vector<int> g[N];

vector<string> getStr(string s)
{
	vector<string> res;
	int l = (int)s.length();
	for (int i = 0; i < l; i++)
		res.push_back(s.substr(i, 1));
	for (int i = 0; i < l; i++)
		for (int j = i + 1; j < l; j++)
			res.push_back(s.substr(i, 1) + s.substr(j, 1));
	for (int i = 0; i < l; i++)
		for (int j = i + 1; j < l; j++)
			for (int k = j + 1; k < l; k++)
				res.push_back(s.substr(i, 1) + s.substr(j, 1) + s.substr(k, 1));
	for (int i = 0; i < l; i++)
		for (int j = i + 1; j < l; j++)
			for (int k = j + 1; k < l; k++)
				for (int p = k + 1; p < l; p++)
					res.push_back(s.substr(i, 1) + s.substr(j, 1) + s.substr(k, 1) + s.substr(p, 1));
	return res;
}

int getNum(string s)
{
	if (names.count(s) == 0)
	{
		names[s] = m;
		names2[m] = s;
		return m++;
	}
	else
		return names[s];
}

void read()
{
	cin >> n;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		vector<string> tmp = getStr(s);
		for (int j = 0; j < (int)tmp.size(); j++)
		{
			int x = getNum(tmp[j]);
			g[i].push_back(x);
		}
	}
	if (m >= N * N) throw;
	return;
}

int xdouble[N], ydouble[N * N];
bool xlabel[N];

bool dfs(int x)
{
	if (xlabel[x]) return false;
	xlabel[x] = 1;
	for (int i = 0; i < (int)g[x].size(); i++)
	{
		int y = g[x][i];
		if (ydouble[y] == -1 || dfs(ydouble[y]))
		{
			xdouble[x] = y;
			ydouble[y] = x;
			return true;
		}
	}
	return false;
}

void solve()
{
	for (int i = 0; i < n; i++)
		xdouble[i] = -1;
	for (int i = 0; i < m; i++)
		ydouble[i] = -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			xlabel[j] = 0;
		dfs(i);
	}
	return;
}

void printAns()
{
	bool ok = true;
	for (int i = 0; i < n; i++)
		if (xdouble[i] == -1)
			ok = false;
	if (!ok)
	{
		printf("-1\n");
		return;
	}
	for (int i = 0; i < n; i++)
		cout << names2[xdouble[i]] << endl;
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	read();
	solve();
	printAns();

	return 0;
}