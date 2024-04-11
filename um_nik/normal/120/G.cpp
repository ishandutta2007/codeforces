#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 105;
int a[N][2];
int b[N][2];
int c[N];
int d[N][N];
bool used[N];
vector<string> answer[N];
string words[N];
int n, m;
int t;
int lst;

void read()
{
	scanf("%d%d", &n, &t);
	for (int i = 0; i < n; i++)
		scanf("%d%d%d%d", &a[i][0], &b[i][0], &a[i][1], &b[i][1]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		cin >> words[i] >> c[i];
	lst = m;
	return;
}

bool checkEnd()
{
	return lst == 0;
}

void solve()
{
	int pos = 0;
	for (int it = 0; !checkEnd(); it++)
	{
		int team = it % n;
		int pl = (it % (2 * n) >= n ? 1 : 0);
		int tm = t;
		while(tm > 0)
		{
			if (checkEnd()) break;
			while(used[pos])
				pos = (pos < m - 1 ? pos + 1 : 0);
			int delta = max(1, c[pos] - a[team][pl] - b[team][pl ^ 1] - d[team][pos]);
			if (delta <= tm)
			{
				answer[team].push_back(words[pos]);
				used[pos] = 1;
				tm -= delta;
				lst--;
			}
			else
			{
				d[team][pos] += tm;
				tm = 0;
				pos = (pos < m - 1 ? pos + 1 : 0);
			}
		}
	}
	return;
}

void printAns()
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", (int)answer[i].size());
		for (int j = 0; j < (int)answer[i].size(); j++)
			cout << " " << answer[i][j];
		cout << endl;
	}
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