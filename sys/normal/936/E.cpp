#include <bits/stdc++.h>
using namespace std;
 
const int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0}, Maxn = 300005;
int n, m, q, rt, ct, tot, cnt, time_now, fa[Maxn], head[Maxn], pos[Maxn], siz[Maxn], Time[Maxn], shift[Maxn], Down[Maxn], Up[Maxn], maxi[Maxn], mini1[2 * Maxn], mini2[2 * Maxn], to[Maxn][4];
bool vis[Maxn];
queue <pair <int, int> > Qu;
long long Hash(pair <int, int> x)
{
	return x.first * 300001LL + x.second;
}
long long Hash(pair <int, pair <int, int> > x)
{
	return x.first + x.second.first * 300001LL * 300001 + x.second.second * 300001LL;
}
struct Hashtable1
{
	int cnt, head[4000055], value[300055], pre[300055];
	long long key[300055];
	Hashtable1()
	{
		memset(pre, -1, sizeof(pre));
		memset(head, -1, sizeof(head));
	}
	int & operator [] (pair <int, int> x)
	{
		long long now = Hash(x);
		int pos = now % 4000037;
		for (int i = head[pos]; ~i; i = pre[i])
			if (key[i] == now)
				return value[i];
		pre[++cnt] = head[pos];
		key[cnt] = now;
		head[pos] = cnt;
		return value[cnt];
	}
	bool find(pair <int, int> x)
	{
		long long now = Hash(x);
		int pos = now % 4000037;
		for (int i = head[pos]; ~i; i = pre[i])
			if (key[i] == now)
				return true;
		return false;
	}
} id, bel;
struct Hashtable2
{
	int cnt, head[7000019], pre[6000055];
	long long key[6000055];
	pair <int, int> value[6000055];
	Hashtable2()
	{
		memset(pre, -1, sizeof(pre));
		memset(head, -1, sizeof(head));
	}
	pair <int, int> & operator [] (pair <int, pair <int, int> > x)
	{
		long long now = Hash(x);
		int pos = now % 7000003;
		for (int i = head[pos]; ~i; i = pre[i])
			if (key[i] == now)
				return value[i];
		pre[++cnt] = head[pos];
		key[cnt] = now;
		head[pos] = cnt;
		return value[cnt];
	}
} dis;
set <pair <int, int> > link;
vector <int> Ve[Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	if (x != y && link.find(make_pair(x, y)) == link.end())
	{
		edge[++cnt] = (edg){head[x], y};
		head[x] = cnt;
		link.insert(make_pair(x, y));
	}
}
void get_root(int u, int fa)
{
	siz[u] = Up[u] - Down[u] + 1, maxi[u] = 0;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa && !vis[to])
		{
			get_root(to, u);
			siz[u] += siz[to];
			maxi[u] = max(maxi[u], siz[to]);
		}
	}
	maxi[u] = max(maxi[u], tot - siz[u]);
	if (maxi[u] < maxi[rt]) rt = u;
}
void get_dis(int u)
{
	for (int i = Down[u]; i <= Up[u]; i++)
		dis[make_pair(u, make_pair(pos[u], i))] = make_pair(0, i), Time[id[make_pair(pos[u], i)]] = time_now, Qu.push(make_pair(pos[u], i));
	while (!Qu.empty())
	{
		int x = Qu.front().first, y = Qu.front().second;
		Qu.pop();
		pair <int, int> d = dis[make_pair(u, make_pair(x, y))]; 
		int now = id[make_pair(x, y)];
		for (int i = 0; i <= 3; i++)
		{
			if (!to[now][i]) continue;
			if (Time[to[now][i]] == time_now) continue;
			if (dx[i] && vis[bel[make_pair(x + dx[i], y + dy[i])]]) continue;
			Time[to[now][i]] = time_now;
			dis[make_pair(u, make_pair(x + dx[i], y + dy[i]))] = make_pair(d.first + 1, d.second);
			Qu.push(make_pair(x + dx[i], y + dy[i]));
		}
	}
}
void divide(int u)
{
	vis[u] = true;
	shift[u] = ct, ct += Up[u] - Down[u] + 2;
	++time_now;
	get_dis(u);
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (!vis[to])
		{
			get_root(to, 0), tot = siz[to], rt = 0, get_root(to, 0);
			fa[rt] = u;
			divide(rt);
		}
	}
}
int lowbit(int x)
{
	return x & -x;
}
void add1(int u, int x, int y)
{
	int limit = Up[u] - Down[u] + 1;
	for (int i = limit - x + 1; i <= limit; i += lowbit(i))
		mini1[i + shift[u]] = min(mini1[i + shift[u]], y);
}
void add2(int u, int x, int y)
{
	int limit = Up[u] - Down[u] + 1;
	for (int i = x; i <= limit; i += lowbit(i))
		mini2[i + shift[u]] = min(mini2[i + shift[u]], y);
}
int ask1(int u, int x)
{
	int limit = Up[u] - Down[u] + 1, result = 0x3f3f3f3f;
	for (int i = limit - x + 1; i; i -= lowbit(i))
		result = min(result, mini1[i + shift[u]]);
	return result;
}
int ask2(int u, int x)
{
	int result = 0x3f3f3f3f;
	for (int i = x; i; i -= lowbit(i))
		result = min(result, mini2[i + shift[u]]);
	return result;
}
void modify(int x, int y)
{
	int u = bel[make_pair(x, y)];
	while (u)
	{
		pair <int, int> d = dis[make_pair(u, make_pair(x, y))];
		add1(u, d.second - Down[u] + 1, d.first + (d.second - Down[u] + 1));
		add2(u, d.second - Down[u] + 1, d.first - (d.second - Down[u] + 1));
		u = fa[u];
	}
}
int query(int x, int y)
{
	int u = bel[make_pair(x, y)], result = 0x3f3f3f3f;
	while (u)
	{
		pair <int, int> d = dis[make_pair(u, make_pair(x, y))];
		result = min(result, d.first - (d.second - Down[u] + 1) + ask1(u, d.second - Down[u] + 1));
		result = min(result, d.first + (d.second - Down[u] + 1) + ask2(u, d.second - Down[u] + 1));
		u = fa[u];
	}
	return result;
}
void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
}
void print(int x)
{
	if (x < 10)
		putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}
int main()
{
	memset(mini1, 0x3f, sizeof(mini1));
	memset(mini2, 0x3f, sizeof(mini2));
	read(n);
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		read(x), read(y);
		Ve[x].push_back(y);
		id[make_pair(x, y)] = i;
	}
	for (int i = 1; i <= 300000; i++)
	{
		sort(Ve[i].begin(), Ve[i].end());
		int las = -1;
		for (vector <int> :: iterator it = Ve[i].begin(); it != Ve[i].end(); it++)
		{
			if (*it - las != 1)
			{
				++m;
				pos[m] = i;
				Up[m] = Down[m] = *it;
			}
			else Up[m]++;
			las = *it;
			bel[make_pair(i, *it)] = m;
		}
	}
	for (int i = 1; i <= 300000; i++)
		for (vector <int> :: iterator it = Ve[i].begin(); it != Ve[i].end(); it++)
			for (int j = 0; j <= 3; j++)
				if (id.find(make_pair(i + dx[j], *it + dy[j])))
				{
					to[id[make_pair(i, *it)]][j] = id[make_pair(i + dx[j], *it + dy[j])];
					add(bel[make_pair(i, *it)], bel[make_pair(i + dx[j], *it + dy[j])]);
				}
	maxi[0] = 0x3f3f3f3f, tot = m, get_root(1, 0), divide(rt);
	read(q);
	bool flag = false;
	while (q--)
	{
		int opt, x, y;
		read(opt), read(x), read(y);
		if (opt == 1)
			modify(x, y), flag = true;
		else if (!flag) puts("-1");
		else print(query(x, y)), putchar('\n');
	}
	return 0;
}