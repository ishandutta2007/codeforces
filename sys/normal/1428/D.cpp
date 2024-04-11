#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, h, ans, a[Maxn], p[Maxn];
stack <int> St;
vector <int> Ve[Maxn];
bool vis[Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = n; i >= 1; i--)
	{
		if (a[i] == 1) St.push(i);
		if (a[i] == 2)
		{
			if (St.empty())
			{
				puts("-1");
				return 0;
			}
			p[i] = St.top();
			vis[p[i]] = true;
			St.pop();
		}
	}
	while (!St.empty()) St.pop();
	for (int i = n; i >= 1; i--)
	{
		if (a[i] == 3)
		{
			if (St.empty())
			{
				puts("-1");
				return 0;
			}
			p[i] = St.top();
			St.pop();
		}
		if (a[i] && !vis[i]) St.push(i);
	}
	int h = 0;
	for (int i = n; i >= 1; i--)
	{
		if (a[i] == 1)
			Ve[i].push_back(++h);
		if (a[i] == 2)
			Ve[i].push_back(Ve[p[i]][0]);
		if (a[i] == 3)
			Ve[i].push_back(++h), Ve[p[i]].push_back(h);
	}
	for (int i = 1; i <= n; i++)
		ans += Ve[i].size();
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
		for (vector <int> :: iterator it = Ve[i].begin(); it != Ve[i].end(); it++)
			printf("%d %d\n", n + 1 - *it, i);
	return 0;
}