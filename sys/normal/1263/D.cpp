#include <bits/stdc++.h>
using namespace std;
const int Maxn = 200005;
int n, ct, bel[Maxn];
bool vis[Maxn][27], Vis[Maxn];
string str[Maxn];
queue <int> Qu;
vector <int> Ve[26];
void bfs(int now)
{
	Qu.push(now);
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		for (int i = 0; i <= 25; i++)
			if (vis[u][i] && !Vis[i])
			{
				Vis[i] = true;
				for (vector <int> :: iterator it = Ve[i].begin(); it != Ve[i].end(); it++)
				{
					bel[*it] = bel[u];
					if (*it != u) Qu.push(*it);
				}
			}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		cin >> str[i];
		int siz = str[i].size();
		for (int j = 0; j < siz; j++)
			vis[i][str[i][j] - 'a'] = true;
		for (int j = 0; j <= 25; j++)
			if (vis[i][j]) Ve[j].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		if (!bel[i]) bel[i] = ++ct, bfs(i);
	printf("%d", ct);
	return 0;
}