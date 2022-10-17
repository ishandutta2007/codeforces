#include <cstdio>
#include <utility>

const int N = 200000;
const int T = (1 << 33 - __builtin_clz(N - 1)) - 1;
int tc, n, q;
char s[N + 1], f[N + 1];
std::pair<int, int> t[T], a[N];

void push(int v, int tl, int tr) 
{
	if (tr - tl != 1 && t[v].second) {
		if (t[v].second == 1) t[(v << 1) + 1].first = t[(v << 1) + 2].first = 0;
		else {
			int m = (tl + tr) >> 1;
			t[(v << 1) + 1].first = m - tl;
			t[(v << 1) + 2].first = tr - m;
		}
		t[(v << 1) + 1].second = t[(v << 1) + 2].second = t[v].second;
		t[v].second = 0;
	}
}

void build(int v, int tl, int tr) 
{
	if (tr - tl == 1) {
		t[v].first = f[tl] - '0';
		t[v].second = 0;
	}
	else {
		int m = (tl + tr) >> 1;
		build((v << 1) + 1, tl, m);
		build((v << 1) + 2, m, tr);
		t[v].first = t[(v << 1) + 1].first + t[(v << 1) + 2].first;
		t[v].second = 0;
	}
}

void update(int v, int tl, int tr, int l, int r, int x) 
{
	if (!(tl >= r || tr <= l)) {
		if (tl >= l && tr <= r) {
			if (x == 1) t[v].first = 0;
			else t[v].first = tr - tl;
			t[v].second = x;
		}
		else {
			push(v, tl, tr);
			int m = (tl + tr) >> 1;
			update((v << 1) + 1, tl, m, l, r, x);
			update((v << 1) + 2, m, tr, l, r, x);
			t[v].first = t[(v << 1) + 1].first + t[(v << 1) + 2].first;
		}
	}
}

int query(int v, int tl, int tr, int l, int r) 
{
	if (tl >= r || tr <= l) return 0;
	if (tl >= l && tr <= r) return t[v].first;
	push(v, tl, tr);
	int m = (tl + tr) >> 1;
	return query((v << 1) + 1, tl, m, l, r) + query((v << 1) + 2, m, tr, l, r);
}

int main() 
{
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d%s%s", &n, &q, s, f);
		build(0, 0, n);
		for (int i = 0; i < q; ++i) {
			scanf("%d%d", &a[i].first, &a[i].second);
			--a[i].first;
		}
		bool ok = true;
		for (int i = q - 1; i >= 0 && ok; --i) {
			int s = query(0, 0, n, a[i].first, a[i].second);
			if (s * 2 == a[i].second - a[i].first) ok = false;
			else {
				if (s * 2 < a[i].second - a[i].first) update(0, 0, n, a[i].first, a[i].second, 1);
				else update(0, 0, n, a[i].first, a[i].second, 2);
			}
		}
		for (int i = 0; i < n && ok; ++i) if ('0' + query(0, 0, n, i, i + 1) != s[i]) ok = false;
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}