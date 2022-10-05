#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, tree_ct, vis[Maxn], ord[Maxn], a[Maxn], Head[Maxn], P[Maxn], rk[Maxn], nxt_pos[Maxn], Mini[Maxn];
int rev_tree_ct, rev_a[Maxn], rev_Head[Maxn], rev_rk[Maxn], rev_ord[Maxn];
long long k, ans, maxi = -0x7fffffffffffffffLL, sum[Maxn], tmp[Maxn], las_ans[Maxn], suf_maxi[Maxn], pre_maxi[Maxn], rev_sum[Maxn];
set <int> Se;
struct Tree
{
	int lson, rson, cnt, mini, maxi;
	long long sum;
} tree[12 * Maxn], rev_tree[12 * Maxn];
void build_first(Tree tree[], int & tree_ct, int root, int lt, int rt)
{
	tree[root].mini = 0x3f3f3f3f;
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		tree[root] = (Tree){++tree_ct, ++tree_ct, 0, 0x3f3f3f3f};
		build_first(tree, tree_ct, tree[root].lson, lt, mid);
		build_first(tree, tree_ct, tree[root].rson, mid, rt);
	}
}
void build(int now, int las, int lt, int rt, int pos)
{
	if (lt + 1 == rt)
	{
		tree[now].cnt = tree[las].cnt + 1;
		tree[now].sum = tree[las].sum + sum[ord[pos]];
		tree[now].mini = min(tree[las].mini, ord[pos]);
		tree[now].maxi = max(tree[las].maxi, ord[pos]);
	}
	else
	{
		int mid = (lt + rt) >> 1;
		if (pos >= mid)
		{
			tree[now].rson = ++tree_ct;
			tree[now].lson = tree[las].lson;
			build(tree[now].rson, tree[las].rson, mid, rt, pos);
		}
		else
		{
			tree[now].lson = ++tree_ct;
			tree[now].rson = tree[las].rson;
			build(tree[now].lson, tree[las].lson, lt, mid, pos);
		}
		tree[now].cnt = tree[tree[now].lson].cnt + tree[tree[now].rson].cnt;
		tree[now].sum = tree[tree[now].lson].sum + tree[tree[now].rson].sum;
		tree[now].mini = min(tree[tree[now].lson].mini, tree[tree[now].rson].mini);
		tree[now].maxi = max(tree[tree[now].lson].maxi, tree[tree[now].rson].maxi);
	}
}
void rev_build(int now, int las, int lt, int rt, int pos)
{
	if (lt + 1 == rt)
	{
		rev_tree[now].cnt = rev_tree[las].cnt + 1;
		rev_tree[now].sum = rev_tree[las].sum + rev_sum[rev_ord[pos]];
		rev_tree[now].mini = min(rev_tree[las].mini, rev_ord[pos]);
		rev_tree[now].maxi = max(rev_tree[las].maxi, rev_ord[pos]);
	}
	else
	{
		int mid = (lt + rt) >> 1;
		if (pos >= mid)
		{
			rev_tree[now].rson = ++rev_tree_ct;
			rev_tree[now].lson = rev_tree[las].lson;
			rev_build(rev_tree[now].rson, rev_tree[las].rson, mid, rt, pos);
		}
		else
		{
			rev_tree[now].lson = ++rev_tree_ct;
			rev_tree[now].rson = rev_tree[las].rson;
			rev_build(rev_tree[now].lson, rev_tree[las].lson, lt, mid, pos);
		}
		rev_tree[now].cnt = rev_tree[rev_tree[now].lson].cnt + rev_tree[rev_tree[now].rson].cnt;
		rev_tree[now].sum = rev_tree[rev_tree[now].lson].sum + rev_tree[rev_tree[now].rson].sum;
		rev_tree[now].mini = min(rev_tree[rev_tree[now].lson].mini, rev_tree[rev_tree[now].rson].mini);
		rev_tree[now].maxi = max(rev_tree[rev_tree[now].lson].maxi, rev_tree[rev_tree[now].rson].maxi);
	}
}
int ask_cnt(int root, int lt, int rt, int L, int R)
{
	if (L >= R) return 0;
	if (lt == L && rt == R) return tree[root].cnt;
	else
	{
		int mid = (lt + rt) >> 1;
		if (L >= mid) return ask_cnt(tree[root].rson, mid, rt, L, R);
		else if (R <= mid) return ask_cnt(tree[root].lson, lt, mid, L, R);
		else return ask_cnt(tree[root].lson, lt, mid, L, mid) + ask_cnt(tree[root].rson, mid, rt, mid, R);
	}
}
long long ask_sum(int root, int lt, int rt, int L, int R)
{
	if (L >= R) return 0;
	if (lt == L && rt == R) return tree[root].sum;
	else
	{
		int mid = (lt + rt) >> 1;
		if (L >= mid) return ask_sum(tree[root].rson, mid, rt, L, R);
		else if (R <= mid) return ask_sum(tree[root].lson, lt, mid, L, R);
		else return ask_sum(tree[root].lson, lt, mid, L, mid) + ask_sum(tree[root].rson, mid, rt, mid, R);
	}
}
int ask_mini(int root, int lt, int rt, int L, int R)
{
	if (L >= R) return 0x3f3f3f3f;
	if (lt == L && rt == R) return tree[root].mini;
	else
	{
		int mid = (lt + rt) >> 1;
		if (L >= mid) return ask_mini(tree[root].rson, mid, rt, L, R);
		else if (R <= mid) return ask_mini(tree[root].lson, lt, mid, L, R);
		else return min(ask_mini(tree[root].lson, lt, mid, L, mid), ask_mini(tree[root].rson, mid, rt, mid, R));
	}
}
int get_pos(int root, int lt, int rt, int val)
{
	if (lt + 1 == rt) return lt;
	else
	{
		int mid = (lt + rt) >> 1;
		if (tree[tree[root].lson].cnt < val) return get_pos(tree[root].rson, mid, rt, val - tree[tree[root].lson].cnt);
		else return get_pos(tree[root].lson, lt, mid, val);
	}
}
long long cal(int rt, long long val)
{
	int pos = upper_bound(tmp, tmp + n, sum[rt] - val) - tmp;
	return ask_cnt(Head[rt], 0, n, 0, pos);
}
struct cmp
{
	bool operator () (const int x, const int y)
	{
		return sum[x] - sum[ord[nxt_pos[x]]] < sum[y] - sum[ord[nxt_pos[y]]];
	}
};
int get_first(Tree tree[], int root, int lt, int rt, int val)
{
	if (lt + 1 == rt) return lt;
	else
	{
		int mid = (lt + rt) >> 1;
		if (tree[tree[root].lson].maxi >= val) return get_first(tree, tree[root].lson, lt, mid, val);
		return get_first(tree, tree[root].rson, mid, rt, val);
	}
}
long long cost(pair <int, int> x)
{
	return (sum[x.second] - sum[ord[get_first(tree, Head[x.second + 1], 0, n, x.first - 1)]]) + (rev_sum[n - x.first + 1] - rev_sum[rev_ord[get_first(rev_tree, rev_Head[n - x.first + 2], 0, n, n - x.second)]]);
}
long long cost2(pair <int, int> x)
{
	return sum[x.second] - sum[x.first - 1] - cost(x);
}
struct sta
{
	pair <int, int> x;
	long long cost;
	sta(const pair <int, int> _x)
	{
		x = _x, cost = cost2(_x);
	}
	bool operator < (const sta &tmp) const
	{
		return make_pair(cost, x) < make_pair(tmp.cost, tmp.x);
	}
};
priority_queue <int, vector <int>, cmp> Pr;
set <sta> In, Out;
void work(long long t)
{
	long long l = -50000LL * n, r = 50000LL * n;
	while (l + 1 <= r)
	{
		long long mid = (l + r + 1) >> 1, now = 0;
		for (int i = 1; i <= n; i++)
			now += cal(i, mid);
		if (now >= t) l = mid;
		else r = mid - 1;
	}
	for (int i = 1; i <= n; i++)
		if (t && cal(i, l + 1))
		{
			vis[i + 1]--;
			int pos1 = upper_bound(tmp, tmp + n, sum[i] - l - 1) - tmp;
			int pos2 = get_pos(Head[i], 0, n, min((long long) i, t));
			vis[Mini[i] = ask_mini(Head[i], 0, n, 0, min(pos1, pos2 + 1)) + 1]++;
			t -= (P[i] = ask_cnt(Head[i], 0, n, 0, min(pos1, pos2 + 1)));
			ans += (las_ans[i] = P[i] * sum[i] - ask_sum(Head[i], 0, n, 0, min(pos1, pos2 + 1)));
		}
	for (int i = 1; i <= n; i++)
		if (t && cal(i, l))
		{
			int pos1 = upper_bound(tmp, tmp + n, sum[i] - l) - tmp;
			int pos2 = get_pos(Head[i], 0, n, min((long long) i, t + P[i]));
			int c = ask_cnt(Head[i], 0, n, 0, min(pos1, pos2 + 1));
			if (c == P[i]) continue;
			if (Mini[i]) vis[Mini[i]]--;
			else vis[i + 1]--;
			vis[ask_mini(Head[i], 0, n, 0, min(pos1, pos2 + 1)) + 1]++;
			t -= c - P[i], P[i] = c;
			ans -= las_ans[i];
			ans += P[i] * sum[i] - ask_sum(Head[i], 0, n, 0, min(pos1, pos2 + 1));
		}
	for (int i = 2; i <= n; i++)
		vis[i] += vis[i - 1];
	for (int i = 1; i <= n; i++)
		if (!vis[i])
		{
			ans += a[i];
			Se.insert(i);
		}
	for (set <int> :: iterator it = Se.begin(); it != Se.end(); it++)
	{
		set <int> :: iterator it2 = it;
		it2++;
		if (it2 != Se.end())
			Out.insert(make_pair(*it + 1, *it2 - 1)), ans += cost(make_pair(*it + 1, *it2 - 1));
	}
	for (int i = 1; i <= n; i++)
		if (P[i] < i)
		{
			nxt_pos[i] = get_pos(Head[i], 0, n, P[i] + 1);
			Pr.push(i);
		}
}
void erase(pair <int, int> now)
{
	if (In.find(now) != In.end())
		ans -= sum[now.second] - sum[now.first - 1], In.erase(now);
	else Out.erase(now), ans -= cost(now);
}
void assign(int lt, int rt)
{
	if (Se.empty()) return ;
	set <int> :: iterator it_r = Se.upper_bound(rt), it_l = Se.lower_bound(lt);
	for (set <int> :: iterator it = it_l; it != it_r; it++)
	{
		ans -= a[*it];
		set <int> :: iterator it2 = it;
		it2++;
		if (it2 != Se.end())
			erase(make_pair(*it + 1, *it2 - 1));
	}
	if (it_l != Se.begin() && it_l != it_r)
	{
		set <int> :: iterator tmp_it = it_l;
		tmp_it--;
		erase(make_pair(*tmp_it + 1, *it_l - 1));
		if (it_r != Se.end())
		{
			Out.insert(make_pair(*tmp_it + 1, *it_r - 1));
			ans += cost(make_pair(*tmp_it + 1, *it_r - 1));
		}
	}
	Se.erase(it_l, it_r);
}
void add_top(void)
{
	int u = Pr.top();
	Pr.pop();
	ans += sum[u] - sum[ord[nxt_pos[u]]];
	assign(ord[nxt_pos[u]] + 1, u);
	P[u]++;
	if (P[u] < u)
	{
		nxt_pos[u] = get_pos(Head[u], 0, n, P[u] + 1);
		Pr.push(u);
	}
}
int main()
{
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), rev_a[i] = a[i];
	reverse(rev_a + 1, rev_a + 1 + n);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i], rev_sum[i] = rev_sum[i - 1] + rev_a[i], pre_maxi[i] = max(pre_maxi[i - 1] + a[i], 0LL);
	for (int i = n; i >= 1; i--)
		suf_maxi[i] = max(suf_maxi[i + 1] + a[i], 0LL);
	for (int i = 0; i < n; i++)
		tmp[i] = sum[i], ord[i] = rev_ord[i] = i;
	sort(tmp, tmp + n);
	sort(ord, ord + n, [](int x, int y){return sum[x] < sum[y];});
	sort(rev_ord, rev_ord + n, [](int x, int y){return rev_sum[x] < rev_sum[y];});
	for (int i = 0; i < n; i++) rk[ord[i]] = i, rev_rk[rev_ord[i]] = i;
	build_first(tree, tree_ct, Head[0] = ++tree_ct, 0, n);
	for (int i = 0; i < n; i++)
		build(Head[i + 1] = ++tree_ct, Head[i], 0, n, rk[i]);
	build_first(rev_tree, rev_tree_ct, rev_Head[0] = ++rev_tree_ct, 0, n);
	for (int i = 0; i < n; i++)
		rev_build(rev_Head[i + 1] = ++rev_tree_ct, rev_Head[i], 0, n, rev_rk[i]);
	long long t = max(0LL, k - n);
	work(t);
	for (long long i = t; i <= k; i++)
	{
		if ((bool) Se.size() + i <= k && (int) Se.size() + i >= k)
		{
			while ((int) (Se.size() - In.size()) + i < k)
			{
				ans -= In.begin() -> cost;
				Out.insert(*In.begin());
				In.erase(*In.begin());
			}
			while ((int) (Se.size() - In.size()) + i > k)
			{
				ans += Out.rbegin() -> cost;
				In.insert(*Out.rbegin());
				Out.erase(*Out.rbegin());
			}
			while (In.size() && Out.size() && Out.rbegin() -> cost > In.begin() -> cost)
			{
				sta tmp1 = *In.begin(), tmp2 = *Out.rbegin();
				Out.erase(tmp2);
				Out.insert(tmp1);
				In.erase(tmp1);
				In.insert(tmp2);
				ans -= tmp1.cost;
				ans += tmp2.cost;
			}
			maxi = max(maxi, ans + (Se.size() ? (max(0LL, pre_maxi[*Se.begin() - 1]) + max(0LL, suf_maxi[*Se.rbegin() + 1])) : 0));
		}
		add_top();
	}
	printf("%lld", maxi);
	return 0;
}