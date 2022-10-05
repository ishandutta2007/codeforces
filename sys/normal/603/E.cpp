#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 500005;
int n, m, q, ct, cnt, head[Maxn], pos[Maxn];
long long f[Maxn], g[Maxn];
bool del[Maxn];
struct node
{
	node * fa, * son[2], * pos;
	bool tag;
	int siz, siz2, val, pos_id;
} point[Maxn];
void update(node * t)
{
	t -> siz = t -> siz2 + (!t -> val);
	if (t -> son[0] != NULL) t -> siz += t -> son[0] -> siz;
	if (t -> son[1] != NULL) t -> siz += t -> son[1] -> siz;
	t -> pos = t;
	t -> pos_id = t - point;
	if (t -> son[0] != NULL)
	{
		t -> pos_id = t -> son[0] -> pos -> val > t -> pos -> val ? t -> son[0] -> pos_id : t -> pos_id;
		t -> pos = t -> son[0] -> pos -> val > t -> pos -> val ? t -> son[0] -> pos : t -> pos;
	}
	if (t -> son[1] != NULL)
	{
		t -> pos_id = t -> son[1] -> pos -> val > t -> pos -> val ? t -> son[1] -> pos_id : t -> pos_id;
		t -> pos = t -> son[1] -> pos -> val > t -> pos -> val ? t -> son[1] -> pos : t -> pos;
	}
}
bool get_son(node * t)
{
	return t -> fa -> son[1] == t;
}
bool heavy(node * t)
{
	if (t -> fa == NULL) return false;
	return t -> fa -> son[0] == t || t -> fa -> son[1] == t;
}
void pushdown(node * t)
{
	if (t -> tag)
	{
		t -> tag = 0;
		swap(t -> son[0], t -> son[1]);
		if (t -> son[0] != NULL) t -> son[0] -> tag ^= 1;
		if (t -> son[1] != NULL) t -> son[1] -> tag ^= 1;
	}
}
void rotate(node * t)
{
	node * fa = t -> fa, * gf = fa -> fa;
	if (heavy(fa))
	{
		bool ss = get_son(fa);
		gf -> son[ss] = t;
	}
	bool s = get_son(t);
	fa -> son[s] = t -> son[!s];
	if (t -> son[!s] != NULL) t -> son[!s] -> fa = fa;
	t -> son[!s] = fa;
	fa -> fa = t;
	t -> fa = gf;
	update(fa), update(t);
}
stack <node*> St;
void splay(node * t)
{
	node * tmp = t;
	St.push(tmp);
	while (heavy(tmp))
		tmp = tmp -> fa, St.push(tmp);
	while (!St.empty()) pushdown(St.top()), St.pop();
	while (heavy(t))
	{
		node * fa = t -> fa;
		if (!heavy(fa))
			rotate(t);
		else
		{
			if (get_son(fa) ^ get_son(t))
				rotate(fa), rotate(t);
			else rotate(t), rotate(t);
		}
	}
}
void access(node * t)
{
	node * tmp = NULL;
	for (; t != NULL; tmp = t, t = t -> fa)
	{
		splay(t);
		if (t -> son[1] != NULL) t -> siz2 += t -> son[1] -> siz;
		if (tmp != NULL) t -> siz2 -= tmp -> siz;
		t -> son[1] = tmp;
		update(t);
	}
}
void makeroot(node * t)
{
	access(t);
	splay(t);
	t -> tag ^= 1;
}
void spilt(node * x, node * y)
{
	makeroot(x);
	access(y);
	splay(y);
}
node * findroot(node * x)
{
	access(x), splay(x);
	pushdown(x);
	while (x -> son[0] != NULL) x = x -> son[0], pushdown(x);
	splay(x);
	return x;
}
void link(node * x, node * y)
{
	makeroot(x);
	makeroot(y);
	if (findroot(y) == x) return ;
	x -> fa = y;
	y -> siz2 += x -> siz;
	update(y);
}
void cut(node * x, node * y)
{
	makeroot(x);
	if (findroot(y) != x || y -> fa != x || y -> son[0] != NULL) return ;
	y -> fa = x -> son[1] = NULL;
	update(x);
}
struct edg
{
	int x, y, w, id;
	bool operator < (const edg &tmp) const
	{
		if (w != tmp.w) return w < tmp.w;
		return id < tmp.id;
	}
} edge[Maxn];
set <edg> Se;
int main()
{
	scanf("%d%d", &n, &m);
	if (n & 1)
	{
		for (int i = 1; i <= m; i++) puts("-1");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		point[i].siz = 1;
	ct = n;
	for (int i = 1; i <= n; i += 2)
	{
		ct++;
		edge[ct] = (edg){i, i + 1, 0x3f3f3f3f, ct};
		Se.insert(edge[ct]);
		point[ct].val = 0x3f3f3f3f;
		link(&point[i], &point[ct]), link(&point[ct], &point[i + 1]);
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		ct++;
		edge[ct] = (edg){x, y, w, ct};
		point[ct].val = w;
		if (findroot(&point[x]) != findroot(&point[y]))
			link(&point[x], &point[ct]), link(&point[ct], &point[y]), Se.insert(edge[ct]);
		else
		{
			spilt(&point[x], &point[y]);
			if (point[y].pos -> val > w)
			{
				int tmp_x = edge[point[y].pos_id].x, tmp_y = edge[point[y].pos_id].y;
				node * tmp = point[y].pos;
				Se.erase(edge[point[y].pos_id]);
				cut(&point[tmp_x], tmp), cut(tmp, &point[tmp_y]);
				link(&point[x], &point[ct]), link(&point[ct], &point[y]);
				Se.insert(edge[ct]);
			}
		}
		while (true)
		{
			int id = Se.rbegin() -> id, x = Se.rbegin() -> x, y = Se.rbegin() -> y;
			cut(&point[x], &point[id]), cut(&point[id], &point[y]);
			Se.erase(*Se.rbegin());
			access(&point[x]), splay(&point[x]), access(&point[y]), splay(&point[y]);
			if ((point[x].siz & 1) || (point[y].siz & 1))
			{
				link(&point[x], &point[id]), link(&point[id], &point[y]);
				Se.insert(edge[id]);
				break;
			}
		}
		printf("%d\n", Se.rbegin() -> w == 0x3f3f3f3f ? -1 : Se.rbegin() -> w);
	}
	return 0;
}