#include <cstdio>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
#include <cstring>

struct query {
	int v, l, k, id;
	bool operator<(query arg) {
		return v < arg.v;
	}
};

const int N = 1000005;
int tt, n, q, a[N], amt[N], t[N << 1], ans[N], start[N];
query qq[N];
std::vector<int> g[N];
std::set<std::pair<int, int> > end;

void add(int i, int x, int v = 0, int tl = 0, int tr = n + 1)
{
	while (tr - tl != 1) {
		t[v] += x;
		int m = tl + tr >> 1;
		if (i < m) {
			++v;
			tr = m;
		} else {
			v += tr - tl & ~1;
			tl = m;
		}
	}
	t[v] += x;
}

int sq(int l, int r, int v = 0, int tl = 0, int tr = n + 1)
{
    if (tl >= r || tr <= l) return 0;
    if (tl >= l && tr <= r) return t[v];
    int m = tl + tr >> 1;
    return sq(l, r, v + 1, tl, m) + sq(l, r, v + (tr - tl & ~1), m, tr);
}

int qry(int sum, int v = 0, int tl = 0, int tr = n + 1)
{
    if (t[v] < sum) return -1;
	while (tr - tl != 1) {
		int m = tl + tr >> 1;
		if (t[v + 1] >= sum) {
			++v;
			tr = m;
		} else {
			sum -= t[v + 1];
			v += tr - tl & ~1;
			tl = m;
		}
	}
	return tl;
}

void dfs(int v)
{
    if (amt[a[v]]) {
		add(amt[a[v]], -1);
		end.erase(std::make_pair(amt[a[v]], a[v]));
	}
    ++amt[a[v]];
	end.insert(std::make_pair(amt[a[v]], a[v]));
    add(amt[a[v]], 1);
    for (int i = start[v]; i < q && qq[i].v == v; ++i) {
        int id = qry(sq(0, qq[i].l) + qq[i].k);
        if (id == -1) ans[qq[i].id] = -2;
        else ans[qq[i].id] = end.lower_bound(std::make_pair(id, 0))->second;
    }
    for (int i = 0; i < (int)g[v].size(); ++i) dfs(g[v][i]);
    add(amt[a[v]], -1);
	end.erase(std::make_pair(amt[a[v]], a[v]));
    --amt[a[v]];
    if (amt[a[v]]) {
		add(amt[a[v]], 1);
		end.insert(std::make_pair(amt[a[v]], a[v]));
	}
}

int main()
{
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d%d", &n, &q);
        memset(t, 0, n + 5 << 3);
        for (int i = 0; i < n; ++i) {
            amt[i] = 0;
            g[i].clear();
            scanf("%d", a + i);
            --a[i];
        }
        for (int i = 1; i < n; ++i) {
            int p;
            scanf("%d", &p);
            g[p - 1].push_back(i);
        }
        for (int i = 0; i < q; ++i) {
            scanf("%d%d%d", &qq[i].v, &qq[i].l, &qq[i].k);
			--qq[i].v;
			qq[i].id = i;
        }
		std::sort(qq, qq + q);
		for (int i = 0; i < q;) {
			start[qq[i].v] = i;
			do {
				++i;
			} while (i < q && qq[i].v == qq[i - 1].v);
		}
        dfs(0);
        for (int i = 0; i < q; ++i) printf("%d ", ans[i] + 1);
        printf("\n");
    }
    return 0;
}