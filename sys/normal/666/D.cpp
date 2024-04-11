#include <bits/stdc++.h>
using namespace std;
 
int T, ans, x[5], y[5], posx[5], posy[5], nowx[5], nowy[5], ans_posx[5], ans_posy[5];
bool vis[5];
vector <int> Ve1, Ve2;
void cal(void)
{
	int tot = 0;
	for (int i = 0; i < 4; i++)
	{
		if (x[i] != nowx[i] && y[i] != nowy[i]) return ;
		tot = max(tot, abs(x[i] - nowx[i]) + abs(y[i] - nowy[i]));
	}
	if (tot < ans)
	{
		ans = tot;
		for (int i = 0; i < 4; i++)
			ans_posx[i] = nowx[i], ans_posy[i] = nowy[i];
	}
}
void dfs(int u)
{
	if (u == 4) cal();
	else
	{
		for (int i = 0; i < 4; i++)
			if (!vis[i])
			{
				nowx[u] = posx[i], nowy[u] = posy[i];
				vis[i] = true;
				dfs(u + 1);
				vis[i] = false;
			}
	}
}
void work(void)
{
	memset(vis, 0, sizeof(vis));
	dfs(0);
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ans = 0x3f3f3f3f;
		for (int i = 0; i < 4; i++)
			scanf("%d%d", &x[i], &y[i]);
		for (int i = 0; i <= 15; i++)
		{
			Ve1.clear(), Ve2.clear();
			for (int j = 0; j < 4; j++)
				if (i & (1 << j)) Ve1.push_back(x[j]);
				else Ve2.push_back(y[j]);
			sort(Ve1.begin(), Ve1.end()), sort(Ve2.begin(), Ve2.end());
			Ve1.resize(unique(Ve1.begin(), Ve1.end()) - Ve1.begin());
			Ve2.resize(unique(Ve2.begin(), Ve2.end()) - Ve2.begin());
			if (Ve1.size() == 2 && Ve2.size() == 2 && Ve1[1] - Ve1[0] == Ve2[1] - Ve2[0])
			{
				posx[0] = posx[1] = Ve1[0], posx[2] = posx[3] = Ve1[1];
				posy[0] = posy[2] = Ve2[0], posy[1] = posy[3] = Ve2[1];
				work();
			}
			if (Ve1.size() == 1 && Ve2.size() == 2)
			{
				posx[0] = posx[1] = Ve1[0], posx[2] = posx[3] = Ve1[0] - (Ve2[1] - Ve2[0]);
				posy[0] = posy[2] = Ve2[0], posy[1] = posy[3] = Ve2[1];
				work();
				posx[2] = posx[3] = Ve1[0] + (Ve2[1] - Ve2[0]);
				work();
			}
			if (Ve1.size() == 2 && Ve2.size() == 1)
			{
				posx[0] = posx[1] = Ve1[0], posx[2] = posx[3] = Ve1[1];
				posy[0] = posy[2] = Ve2[0], posy[1] = posy[3] = Ve2[0] - (Ve1[1] - Ve1[0]);
				work();
				posy[1] = posy[3] = Ve2[0] + (Ve1[1] - Ve1[0]);
				work();
			}
			if (Ve1.size() == 2 && !Ve2.size())
			{
				posx[0] = posx[1] = Ve1[0], posx[2] = posx[3] = Ve1[1];
				for (int j = 0; j < 4; j++)
					for (int k = j + 1; k < 4; k++)
					{
						posy[0] = posy[2] = (y[j] + y[k] - (Ve1[1] - Ve1[0])) / 2, posy[1] = posy[3] = (y[j] + y[k] + Ve1[1] - Ve1[0]) / 2;
						work();
						posy[0] = posy[2] = (y[j] + y[k]) / 2, posy[1] = posy[3] = (y[j] + y[k]) / 2 + Ve1[1] - Ve1[0];
						work();
						posy[0] = posy[2] = (y[j] + y[k] + 1) / 2, posy[1] = posy[3] = (y[j] + y[k] + 1) / 2 + Ve1[1] - Ve1[0];
						work();
						posy[0] = posy[2] = (y[j] + y[k]) / 2 - (Ve1[1] - Ve1[0]), posy[1] = posy[3] = (y[j] + y[k]) / 2;
						work();
						posy[0] = posy[2] = (y[j] + y[k] + 1) / 2 - (Ve1[1] - Ve1[0]), posy[1] = posy[3] = (y[j] + y[k] + 1) / 2;
						work();
					}
			}
			if (!Ve1.size() && Ve2.size() == 2)
			{
				posy[0] = posy[2] = Ve2[0], posy[1] = posy[3] = Ve2[1];
				for (int j = 0; j < 4; j++)
					for (int k = j + 1; k < 4; k++)
					{
						posx[0] = posx[1] = (x[j] + x[k] - (Ve2[1] - Ve2[0])) / 2, posx[2] = posx[3] = (x[j] + x[k] + Ve2[1] - Ve2[0]) / 2;
						work();
						posx[0] = posx[1] = (x[j] + x[k]) / 2, posx[2] = posx[3] = (x[j] + x[k]) / 2 + Ve2[1] - Ve2[0];
						work();
						posx[0] = posx[1] = (x[j] + x[k] + 1) / 2, posx[2] = posx[3] = (x[j] + x[k] + 1) / 2 + Ve2[1] - Ve2[0];
						work();
						posx[0] = posx[1] = (x[j] + x[k]) / 2 - (Ve2[1] - Ve2[0]), posx[2] = posx[3] = (x[j] + x[k]) / 2;
						work();
						posx[0] = posx[1] = (x[j] + x[k] + 1) / 2 - (Ve2[1] - Ve2[0]), posx[2] = posx[3] = (x[j] + x[k] + 1) / 2;
						work();
					}
			}
		}
		if (ans == 0x3f3f3f3f)
			puts("-1");
		else
		{
			printf("%d\n", ans);
			for (int i = 0; i < 4; i++)
				printf("%d %d\n", ans_posx[i], ans_posy[i]);
		}
	}
	return 0;
}