#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, q, Node_ct, ans, lastans, bel[Maxn], cnt[300][Maxn];
struct Node
{
	Node * son[2], * fa;
	int siz, val;
} * root, pool[Maxn];
void create(Node * &t)
{
	t = &pool[++Node_ct];
	t -> siz = 1;
}
bool get_son(Node * t)
{
	return t -> fa -> son[1] == t;
}
void update(Node * t)
{
	t -> siz = 1;
	if (t -> son[0] != NULL) t -> siz += t -> son[0] -> siz;
	if (t -> son[1] != NULL) t -> siz += t -> son[1] -> siz;
}
void rotate(Node * t)
{
	Node * fa = t -> fa, * gf = fa -> fa;
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
void splay(Node * t, Node * goal = NULL)
{
	while (t -> fa != goal)
	{
		Node * fa = t -> fa, * gf = fa -> fa;
		if (gf == goal) rotate(t);
		else
		{
			if (get_son(t) ^ get_son(fa))
				rotate(t), rotate(t);
			else rotate(fa), rotate(t);
		}
	}
}
Node * find_kth(int k)
{
	k++;
	for (Node * t = root; t != NULL; )
	{
		if (t -> son[0] == NULL)
		{
			if (k == 1)
			{
				splay(t);
				return t;
			}
			k--, t = t -> son[1];
		}
		else
		{
			if (k == t -> son[0] -> siz + 1)
			{
				splay(t);
				return t;
			}
			if (k <= t -> son[0] -> siz) t = t -> son[0];
			else k -= t -> son[0] -> siz + 1, t = t -> son[1];
		}
	}
}
void insert(int val)
{
	if (root == NULL)
	{
		create(root);
		root -> val = val;
	}
	else
	{
		Node * tmp = root;
		while (tmp -> son[1] != NULL) tmp = tmp -> son[1];
		splay(tmp);
		create(tmp -> son[1]);
		tmp -> son[1] -> val = val;
		tmp -> son[1] -> fa = tmp;
		splay(tmp -> son[1]);
	}
}
void insert(Node * t, Node * now)
{
	splay(t);
	if (t -> son[0] == NULL)
		t -> son[0] = now, now -> fa = t, update(t);
	else
	{
		Node * tmp = t -> son[0];
		while (tmp -> son[1] != NULL) tmp = tmp -> son[1];
		splay(tmp, t);
		t -> son[0] -> son[1] = now;
		now -> fa = t -> son[0];
	}
	splay(now);
}
Node * erase(Node * t)
{
	splay(t);
	if (t -> son[0] == NULL) root = t -> son[1], root -> fa = NULL;
	else
	{
		Node * tmp = t -> son[0];
		while (tmp -> son[1] != NULL) tmp = tmp -> son[1];
		splay(tmp, root);
		tmp -> fa = NULL;
		tmp -> son[1] = root -> son[1];
		if (tmp -> son[1] != NULL) tmp -> son[1] -> fa = tmp;
		root = root -> son[0];
		update(tmp);
	}
	t -> son[0] = t -> son[1] = NULL;
	update(t);
	return t;
}
void dfs(Node * t, int k)
{
	if (t == NULL) return ;
	if (t -> val == k) ans++;
	if (t -> son[0] != NULL) dfs(t -> son[0], k);
	if (t -> son[1] != NULL) dfs(t -> son[1], k);
}
void work(int lt, int rt, int k)
{
	Node * tmp1 = find_kth(lt - 1),  * tmp2 = find_kth(rt + 1);
	splay(tmp1), splay(tmp2, tmp1);
	dfs(tmp2 -> son[0], k);
}
int main()
{
	scanf("%d", &n);
	int bloc = sqrt(n / log2(n) / 1.8), per = n / bloc;
	for (int i = 1; i <= n; i++)
		bel[i] = (i - 1) / per + 1;
	insert(-0x3f3f3f3f);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		insert(x);
		cnt[bel[i]][x]++;
	}
	insert(0x3f3f3f3f);
	scanf("%d", &q);
	while (q--)
	{
		int opt, l, r;
		scanf("%d", &opt);
		if (opt == 1)
		{
			scanf("%d%d", &l, &r);
			l = (l + lastans - 1) % n + 1;
			r = (r + lastans - 1) % n + 1;
			if (l == r) continue;
			if (l > r) swap(l, r);
			if (bel[l] == bel[r]) goto A;
			cnt[bel[r]][find_kth(r) -> val]--;
			cnt[bel[l]][find_kth(r) -> val]++;
			for (int i = bel[l]; i <= bel[r] - 1; i++)
				cnt[i][find_kth(i * per) -> val]--, cnt[i + 1][find_kth(i * per) -> val]++;
			A:Node * tmp = find_kth(l);
			insert(tmp, erase(find_kth(r)));
		}
		else
		{
			ans = 0;
			int k;
			scanf("%d%d%d", &l, &r, &k);
			l = (l + lastans - 1) % n + 1;
			r = (r + lastans - 1) % n + 1;
			k = (k + lastans - 1) % n + 1;
			if (l > r) swap(l, r);
			if (bel[l] == bel[r])
				work(l, r, k);
			else
			{
				work(l, per * bel[l], k);
				for (int i = bel[l] + 1; i <= bel[r] - 1; i++)
					ans += cnt[i][k];
				work(per * (bel[r] - 1) + 1, r, k);
			}
			printf("%d\n", lastans = ans);
		}
	}
	return 0;
}