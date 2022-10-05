#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int n, ct, ans;
struct node
{
	node * son[2], * fa;
	int key, val, tag, maxi;
} * root, pool[4 * Maxn];
void create(node * &t)
{
	t = &pool[++ct];
}
bool get_son(node * t)
{
	return t -> fa -> son[1] == t;
}
void pushdown(node * t)
{
	if (t -> son[0] != NULL) t -> son[0] -> key += t -> tag, t -> son[0] -> val += t -> tag, t -> son[0] -> tag += t -> tag, t -> son[0] -> maxi += t -> tag;
	if (t -> son[1] != NULL) t -> son[1] -> key += t -> tag, t -> son[1] -> val += t -> tag, t -> son[1] -> tag += t -> tag, t -> son[1] -> maxi += t -> tag;
	t -> tag = 0;
}
void update(node * t)
{
	t -> maxi = t -> val;
	if (t -> son[0] != NULL) t -> maxi = max(t -> maxi, t -> son[0] -> maxi);
	if (t -> son[1] != NULL) t -> maxi = max(t -> maxi, t -> son[1] -> maxi);
}
void rotate(node * t)
{
	node * fa = t -> fa, * gf = fa -> fa;
	if (gf != NULL)
	{
		bool ss = get_son(fa);
		gf -> son[ss] = t;
	}
	else root = t;
	bool s = get_son(t);
	fa -> son[s] = t -> son[!s];
	if (fa -> son[s] != NULL) fa -> son[s] -> fa = fa;
	t -> son[!s] = fa;
	fa -> fa = t;
	t -> fa = gf;
	update(fa), update(t);
}
stack <node *> St;
void splay(node * t, node * goal = NULL)
{
	node * tmp = t;
	while (tmp -> fa != goal) St.push(tmp), tmp = tmp -> fa;
	while (!St.empty()) pushdown(St.top()), St.pop();
	while (t -> fa != goal)
	{
		node * fa = t -> fa, * gf = fa -> fa;
		if (gf == goal) rotate(t);
		else
		{
			if (get_son(t) ^ get_son(fa))
				rotate(t), rotate(t);
			else rotate(fa), rotate(t);
		}
	}
}
node * insert(int x, int v = 0)
{
	for (node * t = root; t != NULL; t = t -> son[x > t -> key])
	{
		pushdown(t);
		if (t -> key == x)
		{
			splay(t);
			t -> val = max(t -> val, v);
			return t;
		}
		if (t -> son[x > t -> key] == NULL)
		{
			create(t -> son[x > t -> key]);
			t -> son[x > t -> key] -> fa = t;
			t = t -> son[x > t -> key];
			t -> key = x;
			t -> val = v;
			splay(t);
			return t;
		}
	}
}
int erase(int val)
{
	insert(val);
	int res = root -> val;
	if (root -> son[1] == NULL) root = root -> son[0], root -> fa = NULL;
	else
	{
		node * tmp = root -> son[1];
		while (tmp -> son[0] != NULL) pushdown(tmp), tmp = tmp -> son[0];
		splay(tmp, root);
		tmp -> son[0] = root -> son[0];
		root = tmp;
		root -> son[0] -> fa = root;
		root -> fa = NULL;
		update(root);
	}
	return res;
}
node * work(int x)
{
	node * now = insert(x);
	splay(now);
	now -> val = max(now -> val, now -> son[0] -> maxi);
	return now;
}
void dfs(node * t)
{
	ans = max(ans, t -> val);
	pushdown(t);
	if (t -> son[0] != NULL) dfs(t -> son[0]);
	if (t -> son[1] != NULL) dfs(t -> son[1]);
}
int main()
{
	scanf("%d", &n);
	create(root);
	root -> key = -0x3f3f3f3f;
	create(root -> son[1]);
	root -> son[1] -> key = 0x3f3f3f3f, root -> son[1] -> fa = root;
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		node * L = work(l - 1), * R = work(r - 1);
		int val = erase(r);
		splay(L);
		L = L -> son[0];
		while (L -> son[1] != NULL) pushdown(L), L = L -> son[1];
		splay(R);
		R = R -> son[1]; 
		while (R -> son[0] != NULL) pushdown(R), R = R -> son[0];
		splay(L), splay(R, L);
		R -> son[0] -> key++, R -> son[0] -> val++, R -> son[0] -> tag++, R -> son[0] -> maxi++;
		update(R), update(L);
		insert(r, val);
	}
	dfs(root);
	printf("%d", ans);
	return 0;
}