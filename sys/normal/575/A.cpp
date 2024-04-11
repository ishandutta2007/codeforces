
#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 50005;
int p, n, m, cnt, s[Maxn];
long long k;
vector <int> Ve;
struct Matrix
{
	long long val[2][2];
	Matrix ()
	{
		memset(val, 0, sizeof(val));
	}
	Matrix operator * (const Matrix &A) const
	{
		Matrix ans;
		ans.val[0][0] = (val[0][0] * A.val[0][0] + val[0][1] * A.val[1][0]) % p;
		ans.val[0][1] = (val[0][0] * A.val[0][1] + val[0][1] * A.val[1][1]) % p;
		ans.val[1][0] = (val[1][0] * A.val[0][0] + val[1][1] * A.val[1][0]) % p;
		ans.val[1][1] = (val[1][0] * A.val[0][1] + val[1][1] * A.val[1][1]) % p;
		return ans;
	}
	void generate(int x)
	{
		val[1][0] = 1;
		val[0][1] = s[x];
		val[1][1] = s[x % n + 1];
	}
}res, ans;
struct spec
{
	long long pos;
	int val;
	bool operator < (const spec &tmp) const
	{
		return pos < tmp.pos;
	}
}S[Maxn];
Matrix generate(int x, int y)
{
	Matrix tmp;
	return tmp;
}
struct Tree
{
	int lt, rt;
	Matrix val;
}tree[4 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt};
	if (lt + 1 == rt)
		tree[root].val.generate(lt);
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
		tree[root].val = tree[root << 1].val * tree[root << 1 | 1].val;
	}
}
void modify(int root, int lt, int rt, int pos, int ele, int val)
{
	if (tree[root].lt + 1 == tree[root].rt)
	{
		if (ele == -1)
			tree[root].val.generate(lt);
		else tree[root].val.val[ele][1] = val;
	}
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (pos >= mid) modify(root << 1 | 1, mid, rt, pos, ele, val);
		else modify(root << 1, lt, mid, pos, ele, val);
		tree[root].val = tree[root << 1].val * tree[root << 1 | 1].val;
	}
}
Matrix ask(int root, int lt, int rt)
{
	if (lt == tree[root].lt && rt == tree[root].rt) return tree[root].val;
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) return ask(root << 1 | 1, lt, rt);
		else if (rt <= mid) return ask(root << 1, lt, rt);
		else return ask(root << 1, lt, mid) * ask(root << 1 | 1, mid, rt);
	}
}
Matrix fast_pow(Matrix x, long long y)
{
	Matrix ans, now = x;
	ans.val[0][0] = ans.val[1][1] = 1;
	while (y)
	{
		if (y & 1) ans = ans * now;
		now = now * now;
		y >>= 1;
	}
	return ans;
}
struct quest
{
	long long pos;
	int ele, val;
	bool operator < (const quest &tmp) const
	{
		return pos < tmp.pos;
	}
}Q[2 * Maxn];
int main()
{
	ans.val[0][1] = 1;
	scanf("%lld%d%d", &k, &p, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &s[i]);
	build(1, 1, n + 1);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%lld%d", &S[i].pos, &S[i].val);
		Q[2 * i - 1] = (quest){S[i].pos, 0, S[i].val};
		Q[2 * i] = (quest){S[i].pos - 1, 1, S[i].val};
	}
	m *= 2;
	sort(Q + 1, Q + 1 + m);
	while (Q[m].pos > k) m--;
	res = tree[1].val;
	for (int i = 1; i <= m; i++)
	{
		if (Q[i].pos / n != Q[i - 1].pos / n)
		{
			ans = ans * tree[1].val * fast_pow(res, Q[i].pos / n - Q[i - 1].pos / n - 1);
			for(vector <int> :: iterator it = Ve.begin(); it != Ve.end(); it++)
				modify(1, 1, n, *it, -1, 0);
			Ve.clear();
		}
		modify(1, 1, n, Q[i].pos % n + 1, Q[i].ele, Q[i].val);
		Ve.push_back(Q[i].pos % n + 1), Ve.push_back((Q[i].pos - 1) % n + 1);
	}
	if (k / n != Q[m].pos / n)
	{
		ans = ans * tree[1].val * fast_pow(res, k / n - Q[m].pos / n - 1);
		for(vector <int> :: iterator it = Ve.begin(); it != Ve.end(); it++)
			modify(1, 1, n, *it, -1, 0);
		Ve.clear();
	}
	if (k % n)
		ans = ans * ask(1, 1, k % n + 1);
	printf("%lld", ans.val[0][0]);
	return 0;
}