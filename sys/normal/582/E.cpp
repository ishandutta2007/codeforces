#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505, Maxs = 1 << 16 | 5, p = 1e9 + 7;
string str;
int n, ct, cnt, now, maxi = 1 << 16, S[2], fa[Maxn], head[Maxn];
long long ans, f[Maxn][Maxs];
char ch[Maxn];
vector <int> Ve[Maxn];
struct edg
{
	int nxt, to;
} edge[Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void FWT_or(long long A[], int len, bool type = false)
{
	for (int i = 1; i < len; i <<= 1)
		for (int j = 0; j < len; j += (i << 1))
			for (int k = j; k < i + j; k++)
				(A[i + k] += type ? p - A[k] : A[k]) %= p;
}
void FWT_and(long long A[], int len, bool type = false)
{
	for (int i = 1; i < len; i <<= 1)
		for (int j = 0; j < len; j += (i << 1))
			for (int k = j; k < i + j; k++)
				(A[k] += type ? p - A[i + k] : A[i + k]) %= p;
}
void dfs(int u)
{
	if (!u) return ;
	if (!Ve[u].size())
	{
		if (ch[u] != '?')
		{
			int id = ch[u] >= 'A' && ch[u] <= 'D' ? ch[u] - 'A' : ch[u] - 'a', sta = 0;
			for (int i = 0; i < 16; i++)
				if (i & (1 << id)) sta |= 1 << i;
			if (ch[u] >= 'A' && ch[u] <= 'D') f[u][sta] = 1;
			else f[u][sta ^ (maxi - 1)] = 1;
		}
		else
			for (int id = 0; id < 4; id++)
			{
				int sta = 0;
				for (int i = 0; i < 16; i++)
					if (i & (1 << id)) sta |= 1 << i;
				f[u][sta]++;
				f[u][sta ^ (maxi - 1)]++;
			}
	}
	else
	{
		dfs(Ve[u][0]), dfs(Ve[u][1]);
		if (ch[u] == '|')
		{
			FWT_or(f[Ve[u][0]], maxi);
			FWT_or(f[Ve[u][1]], maxi);
			for (int i = 0; i < maxi; i++)
				(f[u][i] = f[Ve[u][0]][i] * f[Ve[u][1]][i]) %= p;
			FWT_or(f[u], maxi, true);
		}
		else if (ch[u] == '&')
		{
			FWT_and(f[Ve[u][0]], maxi);
			FWT_and(f[Ve[u][1]], maxi);
			for (int i = 0; i < maxi; i++)
				(f[u][i] = f[Ve[u][0]][i] * f[Ve[u][1]][i]) %= p;
			FWT_and(f[u], maxi, true);
		}
		else
		{
			static long long tmp[Maxs];
			FWT_or(f[Ve[u][0]], maxi);
			FWT_or(f[Ve[u][1]], maxi);
			for (int i = 0; i < maxi; i++)
				(tmp[i] = f[Ve[u][0]][i] * f[Ve[u][1]][i]) %= p;
			FWT_or(tmp, maxi, true);
			for (int i = 0; i < maxi; i++)
				(f[u][i] += tmp[i]) %= p;
			FWT_or(f[Ve[u][0]], maxi, true);
			FWT_or(f[Ve[u][1]], maxi, true);
			FWT_and(f[Ve[u][0]], maxi);
			FWT_and(f[Ve[u][1]], maxi);
			for (int i = 0; i < maxi; i++)
				(tmp[i] = f[Ve[u][0]][i] * f[Ve[u][1]][i]) %= p;
			FWT_and(tmp, maxi, true);
			for (int i = 0; i < maxi; i++)
				(f[u][i] += tmp[i]) %= p;
			FWT_and(f[Ve[u][0]], maxi, true);
			FWT_and(f[Ve[u][1]], maxi, true);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> str >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b, c, d, s;
		cin >> a >> b >> c >> d >> s;
		S[s] |= 1 << (a | (b << 1) | (c << 2) | (d << 3));
	}
	int siz = str.size();
	now = ct = 1;
	for (int i = 0; i < siz; i++)
		if (str[i] == '(') ct++, Ve[now].push_back(ct), fa[ct] = now, now = ct;
		else if (str[i] == ')') now = fa[now];
		else ch[now] = str[i];
	dfs(1);
	for (int i = 0; i < maxi; i++)
		if ((i | S[1]) == i && !(i & S[0])) (ans += f[1][i]) %= p;
	cout << ans;
	return 0;
}