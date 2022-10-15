#include <bits/stdc++.h>
#define N 200005
#define int long long
using namespace std;

template <typename T>

void read(T &a)
{
	T x = 0,f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	a = x * f;
}

template <typename T>

void write(T x)
{
	if (x < 0) putchar('-'),x = -x;
	if (x < 10) return (void) putchar(x + '0');
	write(x / 10);
	putchar(x % 10 + '0');
}

template <typename T>

void writeln(T x)
{
	write(x);
	putchar('\n');
}

template <typename T>

void writes(T x)
{
	write(x);
	putchar(' ');
}

template <typename T,typename... Args> 

void read(T &t,Args &... args)
{
	read(t);
	read(args...);
}

template <typename T,typename... Args>

void writes(T t,Args ... args)
{
	writes(t);
	writes(args...);
}

template <typename T,typename... Args>

void writeln(T t,Args ... args)
{
	writes(t);
	writes(args...);
	putchar('\n');
}

int n,m,head[N],pnt[N << 1],nxt[N << 1],E = 0;
int id[N],cnt;

void add_edge(int u,int v)
{
	pnt[E] = v;
	nxt[E] = head[u];
	head[u] = E++;
}

struct BIT
{
	int tr[N << 1];
	int lowbit(int x)
	{
		return x & (-x);
	}
	void update(int x,int k)
	{
		while (x <= n + m)
		{
			tr[x] += k;
			x += lowbit(x);
		}
	}
	int query(int x)
	{
		int res = 0;
		while (x)
		{
			res += tr[x];
			x -= lowbit(x);
		}
		return res;
	}
}T;

namespace LCT
{
	int siz[N],ch[N][2],fa[N],rev[N];
	int check(int x)
	{
		return x == ch[fa[x]][1];
	}
	int isroot(int x)
	{
		return x != ch[fa[x]][0] && x != ch[fa[x]][1];
	}
	void pushup(int x)
	{
		siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1;
	}
	void pushr(int x)
	{
		swap(ch[x][0],ch[x][1]);
		rev[x] ^= 1;
	}
	void pushdown(int x)
	{
		id[ch[x][0]] = id[x];
		id[ch[x][1]] = id[x];
		if (!rev[x]) return ;
		pushr(ch[x][0]);
		pushr(ch[x][1]);
		rev[x] = 0;
	}
	void rotate(int x)
	{
		int y = fa[x],z = fa[y],k = check(x),w = ch[x][!k];
		if (!isroot(y)) ch[z][check(y)] = x;
		ch[x][!k] = y;
		ch[y][k] = w;
		if (w) fa[w] = y;
		fa[y] = x;
		fa[x] = z;
		pushup(y);
	}
	void splay(int x)
	{
		int y = x;
		std::vector<int> sk;
		sk.push_back(y);
		while (!isroot(y)) sk.push_back(fa[y]),y = fa[y];
		while (!sk.empty()) pushdown(sk.back()),sk.pop_back();
		while (!isroot(x))
		{
			y = fa[x];
			if (!isroot(y)) rotate((check(x) ^ check(y)) ? x : y);
			rotate(x);
		}
		pushup(x);
	}
	void access(int x)
	{
		int y = 0;
		while (x)
		{
			splay(x);
			T.update(id[x],-siz[ch[x][0]] - 1);
			T.update(cnt,siz[ch[x][0]] + 1);
			ch[x][1] = y;
			pushup(x);
			y = x;
			x = fa[x];
		}
	}
}

void dfs(int u,int f)
{
	LCT::fa[u] = f;
	LCT::siz[u] = 1;
	id[u] = u;
	for (int i = head[u]; i != -1; i = nxt[i])
	{
		int v = pnt[i];
		if (v == f) continue;
		dfs(v,u);
		if (id[u] < id[v])
		{
			id[u] = id[v];
			LCT::ch[u][1] = v;
			LCT::siz[u] = LCT::siz[v] + 1;
		}
	}
	T.update(id[u],1);
}

signed main()
{
	memset(head,-1,sizeof(head));
	read(n,m);
	for (int i = 1; i < n; i++)
	{
		int u,v;
		read(u,v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(n,0);
	cnt = n;
	for (int i = 1; i <= m; i++)
	{
		char opt[7];
		scanf("%s",opt);
		if (opt[0] == 'u')
		{
			int u;
			read(u);
			cnt++;
			LCT::access(u);
			LCT::splay(u);
			LCT::pushr(u);
			id[u] = cnt;
		}
		if (opt[0] == 'w')
		{
			int u;
			read(u);
			LCT::splay(u);
			writeln(T.query(id[u]) - LCT::siz[LCT::ch[u][0]]);
		}
		if (opt[0] == 'c')
		{
			int u,v;
			read(u,v);
			LCT::splay(u);
			int au = T.query(id[u]) - LCT::siz[LCT::ch[u][0]];
			LCT::splay(v);
			int av = T.query(id[v]) - LCT::siz[LCT::ch[v][0]];
			writeln(au < av ? u : v);
		}
	}
	return 0;
}