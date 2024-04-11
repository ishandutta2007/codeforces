#include <bits/stdc++.h>
using namespace std;

const int Maxm = 2505, Maxn = 105, p = 1e9 + 7;
int n, m, cnt, x[Maxm], y[Maxm], c[Maxm], l[Maxm], type[Maxm], head[Maxn], G1[Maxn][Maxn], G2[Maxn][Maxn];
long long f[Maxn][Maxn][2];
vector <int> Ve[Maxm];
queue <int> Qu1, Qu2;
struct edg
{
	int nxt, to, w;
	bool s, e;
} edge[2 * Maxm];
void add(int x, int y, int w, bool s, bool e)
{
	edge[++cnt] = (edg){head[x], y, w, s, e};
	head[x] = cnt;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		l[i] = -1;
		scanf("%d%d%d", &x[i], &y[i], &c[i]);
		for (int j = 1; j <= c[i]; j++)
		{
			int u;
			scanf("%d", &u);
			Ve[i].push_back(u);
		}
		G1[x[i]][y[i]] = i, G2[y[i]][x[i]] = i;
		for (int j = 0; j < c[i] - 1; j++)
			if (Ve[i][j] == x[i] && Ve[i][j + 1] == y[i])
				l[i] = j;
		if (l[i] != -1)
		{
			type[i] = 1;
			goto END1;
		}
		for (int j = 0; j < c[i]; j++)
			if (Ve[i][j] == x[i]) l[i] = j;
		if (l[i] != -1)
		{
			type[i] = 2;
			goto END1;
		}
		for (int j = 0; j < c[i]; j++)
			if (Ve[i][j] == y[i]) l[i] = j;
		if (l[i] != -1)
		{
			type[i] = 3;
			goto END1;
		}
		l[i] = 0;
		END1:;
	}
	for (int i = 1; i <= m; i++)
	{
		if (l[i] == -1) continue;
		int S, E;
		if (type[i] == 1)
		{
			int tmp_len = 1;
			while (!Qu1.empty()) Qu1.pop();
			while (!Qu2.empty()) Qu2.pop();
			for (int j = l[i] - 1; ~j; j--)
				Qu1.push(Ve[i][j]);
			for (int j = l[i] + 2; j < (int) Ve[i].size(); j++)
				Qu2.push(Ve[i][j]);
			S = x[i];
			while (!Qu1.empty())
			{
				int u = Qu1.front();
				Qu1.pop();
				tmp_len++;
				if (tmp_len > 2 * n) goto END2;
				if (!G2[S][u]) goto END2;
				for (vector <int> :: reverse_iterator it = Ve[G2[S][u]].rbegin(); it != Ve[G2[S][u]].rend(); it++)
					Qu1.push(*it);
				S = u;
			}
			E = y[i];
			while (!Qu2.empty())
			{
				int u = Qu2.front();
				Qu2.pop();
				tmp_len++;
				if (tmp_len > 2 * n) goto END2;
				if (!G1[E][u]) goto END2;
				for (vector <int> :: iterator it = Ve[G1[E][u]].begin(); it != Ve[G1[E][u]].end(); it++)
					Qu2.push(*it);
				E = u;
			}
			add(S, E, tmp_len, 1, 1);
		}
		if (type[i] == 2)
		{
			if (*Ve[i].rbegin() != x[i]) goto END2;
			int tmp_len = 1;
			while (!Qu1.empty()) Qu1.pop();
			for (int j = Ve[i].size() - 2; ~j; j--)
				Qu1.push(Ve[i][j]);
			S = x[i], E = y[i];
			while (!Qu1.empty())
			{
				int u = Qu1.front();
				Qu1.pop();
				tmp_len++;
				if (tmp_len > 2 * n) goto END2;
				if (!G2[S][u]) goto END2;
				for (vector <int> :: reverse_iterator it = Ve[G2[S][u]].rbegin(); it != Ve[G2[S][u]].rend(); it++)
					Qu1.push(*it);
				S = u;
			}
			add(S, E, tmp_len, 1, 0);
		}
		if (type[i] == 3)
		{
			if (*Ve[i].begin() != y[i]) goto END2;
			int tmp_len = 1;
			while (!Qu2.empty()) Qu2.pop();
			for (int j = 1; j < (int) Ve[i].size(); j++)
				Qu2.push(Ve[i][j]);
			S = x[i], E = y[i];
			while (!Qu2.empty())
			{
				int u = Qu2.front();
				Qu2.pop();
				tmp_len++;
				if (tmp_len > 2 * n) goto END2;
				if (!G1[E][u]) goto END2;
				for (vector <int> :: iterator it = Ve[G1[E][u]].begin(); it != Ve[G1[E][u]].end(); it++)
					Qu2.push(*it);
				E = u;
			}
			add(S, E, tmp_len, 0, 1);
		}
		if (!Ve[i].size()) add(x[i], y[i], 1, 0, 0);
		END2:;
	}
	for (int i = 1; i <= n; i++)
		f[0][i][0] = 1;
	for (int l = 0; l <= 2 * n; l++)
		for (int u = 1; u <= n; u++)
			for (int i = head[u]; i; i = edge[i].nxt)
				(f[l + edge[i].w][edge[i].to][edge[i].e] += f[l][u][edge[i].s ^ 1]) %= p;
	for (int i = 1; i <= 2 * n; i++)
	{
		long long ans = 0;
		for (int j = 1; j <= n; j++)
			(ans += f[i][j][1]) %= p;
		printf("%lld\n", ans);
	}
	return 0;
}