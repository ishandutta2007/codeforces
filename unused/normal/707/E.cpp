#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

// persistent segment tree impl: sum tree
namespace pstree {
	typedef long long val_t;
	const int DEPTH = 11;
	const int TSIZE = 1 << DEPTH;

	const int MAX_QUERY = 2005;
	struct node {
		val_t v;
		node *l, *r;
	} npoll[TSIZE * 2 + MAX_QUERY * (DEPTH + 1)];
	int pptr, last_q;
	node *head[MAX_QUERY + 1];
	int q[MAX_QUERY + 1];
	int lastidx = 0;
	void init() {
		// zero-initialize, can be changed freely
		memset(&npoll[TSIZE - 1], 0, sizeof(node) * TSIZE);
		memset(q, 0, sizeof(q));
		for (int i = TSIZE - 2; i >= 0; i--) {
			npoll[i].v = 0;
			npoll[i].l = &npoll[i * 2 + 1];
			npoll[i].r = &npoll[i * 2 + 2];
		}
		head[0] = &npoll[0];
		last_q = 0;
		pptr = 2 * TSIZE - 1;
		q[0] = 0;
		lastidx = 0;
	}

	void update(int pos, val_t val, int t) {
		head[++last_q] = &npoll[pptr++];
		node *old = head[last_q - 1], *now = head[last_q];
		while (lastidx < t) q[lastidx++] = last_q - 1;
		q[t] = last_q;
		int flag = 1 << DEPTH;
		for (;;) {
			now->v = old->v + val;
			flag >>= 1;
			if (flag == 0) {
				now->l = now->r = nullptr; break;
			}
			if (flag & pos) {
				now->l = old->l;
				now->r = &npoll[pptr++];
				now = now->r, old = old->r;
			}
			else {
				now->r = old->r;
				now->l = &npoll[pptr++];
				now = now->l, old = old->l;
			}
		}
	}

	val_t query(int s, int e, int l, int r, node *n) {
		if (s == l && e == r) return n->v;
		int m = (l + r) / 2;
		if (m >= e) return query(s, e, l, m, n->l);
		else if (m < s) return query(s, e, m + 1, r, n->r);
		else return query(s, m, l, m, n->l) + query(m + 1, e, m + 1, r, n->r);
	}

	// query summation of [s, e] at time t
	val_t query(int s, int e, int t) {
		s = max(0, s); e = min(TSIZE - 1, e);
		if (s > e) return 0;
		return query(s, e, 0, TSIZE - 1, head[q[t]]);
	}
}

struct pts
{
	int x, y, w;
	bool operator<(const pts &rhs) const
	{
		return y < rhs.y;
	}
};

vector<pts> points[2005];

struct query
{
	char type;
	int param;
};

struct rectangle_
{
	int x1, y1, x2, y2;
};

query qry[1000005];
vector<rectangle_> rect;
vector<pair<int, long long>> graph[2005];
bool turned[2005];

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++)
	{
		int len;
		scanf("%d", &len);
		points[i].resize(len);
		for (int j = 0; j < len; j++)
		{
			scanf("%d%d%d", &points[i][j].x, &points[i][j].y, &points[i][j].w);
		}
	}

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf(" %c%*s", &qry[i].type);
		if (qry[i].type == 'A')
		{
			rectangle_ r;
			scanf("%d%d%d%d", &r.x1, &r.y1, &r.x2, &r.y2);
			rect.emplace_back(r);
			qry[i].param = rect.size() - 1;
		}
		else
		{
			scanf("%d", &qry[i].param);
			qry[i].param--;
		}
	}

	for (int i = 0; i < k; i++)
	{
		turned[i] = true;
		pstree::init();
		sort(points[i].begin(), points[i].end());
		for (auto &&p : points[i])
		{
			pstree::update(p.x, p.w, p.y);
		}
		int maxy = points[i].back().y;
		for (int j = 0; j < rect.size(); j++)
		{
			long long res = pstree::query(rect[j].x1, rect[j].x2, min(maxy, rect[j].y2)) - pstree::query(rect[j].x1, rect[j].x2, min(maxy, rect[j].y1 - 1));
			graph[j].emplace_back(i, res);
		}
	}

	for (int i = 0; i < q; i++)
	{
		if (qry[i].type == 'A')
		{
			int idx = qry[i].param;
			long long ans = 0;
			for (auto &&e : graph[idx])
			{
				if (turned[e.first]) ans += e.second;
			}
			printf("%lld\n", ans);
		}
		else
		{
			turned[qry[i].param] ^= true;
		}
	}
}