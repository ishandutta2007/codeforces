#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int N = (int)4e4;
vector<int> g[N];
int deg[N];
int n;
string s;
int S;
int d1 = -1, d2 = -1;

vector<int> euler;

int getNum(string s)
{
	return 200 * (int)s[0] + (int)s[1];
}

string getStr(int x)
{
	string str;
	str.resize(2);
	str[0] = (char)(x / 200);
	str[1] = (char)(x % 200);
	return str;
}

void dfs(int v)
{
	while((int)g[v].size() > 0)
	{
		int to = g[v].back();
		g[v].pop_back();
		dfs(to);
	}
	euler.push_back(v);
	return;
}

void getEuler()
{
	dfs(S);
	reverse(euler.begin(), euler.end());
	euler.pop_back();
	return;
}

void badEnd()
{
	printf("NO\n");
	exit(0);
}

bool used[N];

void dfsU(int v)
{
	used[v] = 1;
	for (int i = 0; i < (int)g[v].size(); i++)
	{
		int to = g[v][i];
		if (!used[to]) dfsU(to);
	}
	return;
}

bool checkComp()
{
	dfsU(S);
	for (int i = 0; i < N; i++)
		if (!used[i] && (int)g[i].size() > 0)
			return false;
	return true;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		int v = getNum(s.substr(0, 2));
		int u = getNum(s.substr(1, 2));
		g[v].push_back(u);
		deg[v]++;
		deg[u]--;
		if (i == 0) S = v;
	}
	for (int i = 0; i < N; i++)
	{
		if (deg[i] == 0) continue;
		if (abs(deg[i]) > 1)
			badEnd();
		if (deg[i] == 1)
		{
			if (d2 != -1)
				badEnd();
			d2 = i;
		}
		else
		{
			if (d1 != -1)
				badEnd();
			d1 = i;
		}
	}
	if (d1 != -1)
		g[d1].push_back(d2);
	if (!checkComp())
		badEnd();
	getEuler();
	int sz = (int)euler.size();
//	for (int i = 0; i < sz; i++)
//		cerr << getStr(euler[i]) << endl;
	int idx = 0;
	if (d1 != -1)
	{
		while(euler[idx] != d1 || euler[(idx + 1) % sz] != d2)
			idx++;
	}
	int sidx = idx;
	if (d1 != -1)
		sidx = (sidx + 1) % sz;
	s = getStr(euler[sidx]);
	cout << "YES\n";
	cout << s;
	for (int i = sidx + 1; i != idx; i = (i + 1) % sz)
	{
		s = getStr(euler[i]);
		cout << s[1];
	}
	cout << getStr(euler[idx])[1];
	cout << endl;

	return 0;
}