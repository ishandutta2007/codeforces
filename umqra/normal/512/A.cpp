#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = 300;
const int A = 26;

vector <int> g[A];
string str[N];

void addEdge(int a, int b)
{
	g[a].push_back(b);
}

vector <int> order;

bool used[A];

void dfs(int v)
{
	used[v] = 1;
	for (int i = 0; i < (int)g[v].size(); i++)
	{
		int to = g[v][i];
		if (!used[to])
			dfs(to);
	}
	order.push_back(v);
}

int getNum(char c)
{
	for (int i = 0; i < (int)order.size(); i++)
	{
		if (order[i] + 'a' == c)
			return i;
	}
	throw;
}

bool check(int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int len = min((int)str[i].length(), (int)str[i + 1].length());
		bool ok = false;
		for (int s = 0; s < len; s++)
		{
			if (str[i][s] != str[i + 1][s])
			{
				if (getNum(str[i][s]) > getNum(str[i + 1][s]))
					return false;
				ok = true;
				break;
			}
		}
		if (!ok && (int)str[i].length() > (int)str[i + 1].length())
			return false;
	}
	return true;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		int len = min((int)str[i].length(), (int)str[i + 1].length());
		for (int s = 0; s < len; s++)
		{
			if (str[i][s] != str[i + 1][s])
			{
				addEdge(str[i][s] - 'a', str[i + 1][s] - 'a');
				break;
			}
		}
	}
	for (int i = 0; i < A; i++)
	{
		if (!used[i])
			dfs(i);
	}

	reverse(order.begin(), order.end());
	if (!check(n))
	{
		puts("Impossible");
		return 0;
	}
	for (int i = 0; i < A; i++)
		printf("%c", order[i] + 'a');

	return 0;
}