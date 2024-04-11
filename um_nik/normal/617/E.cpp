#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int N = 100100;
const int M = (1 << 20) + 7;
const int B = 350;
const int L = 350;
int a[N];
int n, m, k;
ll ans[N];
ll b[M], c[M];
ll res;

struct Query
{
	int id;
	int l, r;

	Query() : id(), l(), r() {}
	Query(int _id, int _l, int _r) : id(_id), l(_l), r(_r) {}

	bool operator < (const Query Q) const
	{
		return r < Q.r;
	}
};

vector<Query> q[L];

void read()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i + 1] = a[i] ^ x;
	}
	for (int i = 0; i < m; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		r++;
		q[l / B].push_back(Query(i, l, r));
	}
	for (int i = 0; i < L; i++)
		sort(q[i].begin(), q[i].end());
	return;
}

void addBack(int r)
{
	int x = a[r] ^ k;
	res += b[x];
	b[x ^ k]++;
	c[x]++;
}
void addFront(int l)
{
	int x = a[l];
	res += c[x];
	b[x]++;
	c[x ^ k]++;
}
void popFront(int l)
{
	int x = a[l];
	b[x]--;
	c[x ^ k]--;
	res -= c[x];
}

void solve(int id)
{
	if (q[id].empty()) return;
	for (int i = 0; i <= n; i++)
	{
		b[a[i]] = 0;
		c[a[i] ^ k] = 0;
	}
	res = 0;
	int l = q[id][0].l;
	int r = l;
	for (Query Q : q[id])
	{
		while(r < Q.r)
			addBack(r++);
		while (l < Q.l)
			popFront(l++);
		while(l > Q.l)
			addFront(--l);
		ans[Q.id] = res;
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	for (int i = 0; i < L; i++)
		solve(i);
	for (int i = 0; i < m; i++)
		printf("%lld\n", ans[i]);

	return 0;
}