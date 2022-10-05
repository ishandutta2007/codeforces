#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
int T, n, m;
__int128 a[2][Maxn], g[2][4 * Maxn][4 * Maxn];
queue <pair <int, int> > Qu;
vector <int> A, B;
void build(int type, int pos, int root, int lt, int rt)
{
	if (lt + 1 == rt) g[type][pos][root] = a[type][pos] / __gcd(a[type][pos], a[type ^ 1][lt]);
	else
	{
		int mid = (lt + rt) >> 1;
		build(type, pos, root << 1, lt, mid), build(type, pos, root << 1 | 1, mid, rt);
		g[type][pos][root] = __gcd(g[type][pos][root << 1], g[type][pos][root << 1 | 1]);
	}
}
void del(int type, int pos, int root, int lt, int rt, int p)
{
	if (lt + 1 == rt) g[type][pos][root] = 0;
	else
	{
		int mid = (lt + rt) >> 1;
		if (p >= mid) del(type, pos, root << 1 | 1, mid, rt, p);
		else del(type, pos, root << 1, lt, mid, p);
		g[type][pos][root] = __gcd(g[type][pos][root << 1], g[type][pos][root << 1 | 1]);
	}
}	
void print(__int128 x)
{
	if (!x) return ;
	if (x < 10) putchar('0' + x);
	else print(x / 10), putchar('0' + (x % 10));
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		A.clear(), B.clear();
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			string str;
			cin >> str;
			a[0][i] = 0;
			for (auto u : str)
				a[0][i] = a[0][i] * 10 + u - '0';
		}
		for (int i = 1; i <= m; i++)
		{
			string str;
			cin >> str;
			a[1][i] = 0;
			for (auto u : str)
				a[1][i] = a[1][i] * 10 + u - '0';
		}
		for (int i = 1; i <= n; i++)
		{
			build(0, i, 1, 1, m + 1);
			if (g[0][i][1] != 1) Qu.push(make_pair(0, i));
		}
		for (int i = 1; i <= m; i++)
		{
			build(1, i, 1, 1, n + 1);
			if (g[1][i][1] != 1) Qu.push(make_pair(1, i));
		}
		while (!Qu.empty())
		{
			pair <int, int> u = Qu.front();
			Qu.pop();
			for (int i = 1; i <= (u.first ? n : m); i++)
				if (a[u.first ^ 1][i] != 1 && g[u.first ^ 1][i][1] == 1)
				{
					del(u.first ^ 1, i, 1, 1, (u.first ? m : n) + 1, u.second);
					if (g[u.first ^ 1][i][1] != 1)
						Qu.push(make_pair(u.first ^ 1, i));
				}
		}
		for (int i = 1; i <= n; i++)
			if (g[0][i][1] == 1) A.push_back(i);
		for (int i = 1; i <= m; i++)
			if (g[1][i][1] == 1) B.push_back(i);
		if (A.size() && B.size())
		{
			printf("YES\n%d %d\n", A.size(), B.size());
			for (auto u : A)
				print(a[0][u]), putchar(' ');
			puts("");
			for (auto u : B)
				print(a[1][u]), putchar(' ');
			puts("");
		}
		else puts("NO");
	}
	return 0;
}