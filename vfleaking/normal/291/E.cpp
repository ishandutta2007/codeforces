#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long s64;

const int MaxN = 100000;
const int MaxLen = 300000;

int n;
int fa[MaxN + 1];
string str[MaxN + 1];

string pat;
s64 patH1, patH2;

int dist[MaxN + 1];
vector<int> adj[MaxN + 1];

const int Base = 31;
const int Mod1 = 1000000007;
const int Mod2 = 1000000009;

int sta_n = 0;
char sta[MaxLen];

s64 hash_pow1, hash_pow2;

int outcome = 0;

void dfs(const int &v, s64 lastH1, s64 lastH2)
{
	for (int i = 0; i < (int)str[v].size(); i++)
	{
		sta[sta_n] = str[v][i];
		lastH1 = (lastH1 * Base + str[v][i] - 'a') % Mod1;
		if (sta_n >= pat.size())
		{
			lastH1 -= ((sta[sta_n - pat.size()] - 'a') * hash_pow1) % Mod1;
			if (lastH1 < 0)
				lastH1 += Mod1;
		}

		lastH2 = (lastH2 * Base + str[v][i] - 'a') % Mod2;
		if (sta_n >= pat.size())
		{
			lastH2 -= ((sta[sta_n - pat.size()] - 'a') * hash_pow2) % Mod2;
			if (lastH2 < 0)
				lastH2 += Mod2;
		}
		sta_n++;

		if (sta_n >= pat.size() && lastH1 == patH1 && lastH2 == patH2)
			outcome++;
	}

	for (vector<int>::iterator u = adj[v].begin(); u != adj[v].end(); u++)
		dfs(*u, lastH1, lastH2);

	sta_n -= str[v].size();
}

int main()
{
	cin >> n;
	fa[1] = 0;
	for (int i = 2; i <= n; i++)
		cin >> fa[i] >> str[i];
	cin >> pat;

	for (int v = 2; v <= n; v++)
		adj[fa[v]].push_back(v);

	hash_pow1 = 1;
	for (int i = 1; i <= (int)pat.size(); i++)
		hash_pow1 = (hash_pow1 * Base) % Mod1;
	hash_pow2 = 1;
	for (int i = 1; i <= (int)pat.size(); i++)
		hash_pow2 = (hash_pow2 * Base) % Mod2;

	patH1 = 0;
	for (int i = 0; i < (int)pat.size(); i++)
		patH1 = (patH1 * Base + pat[i] - 'a') % Mod1;
	patH2 = 0;
	for (int i = 0; i < (int)pat.size(); i++)
		patH2 = (patH2 * Base + pat[i] - 'a') % Mod2;

	dfs(1, 0, 0);

	cout << outcome << endl;

	return 0;
}