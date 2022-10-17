#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <utility>

struct pt {
	long long a, b;
	bool operator<(pt arg) {
		return (__int128)a * arg.b < (__int128)b * arg.a;
	}
	bool operator==(pt arg) {
		return !(*this < arg) && !(arg < *this);
	}
};

struct edge {
	int to, ind;
	edge(int to_ = 0, int ind_ = 0) {
		to = to_;
		ind = ind_;
	}
};

const int N = 200000;
int n;
pt l[N], r[N], p[2 * N];
std::vector<edge> g[2 * N];
bool u[2 * N], ue[N];
std::vector<std::pair<int, int> > ans;

int dfs(int v, int pr = -1) 
{
	u[v] = true;
	int e = -1;
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i].to != pr && !ue[g[v][i].ind]) {
		int next = -1;
		if (u[g[v][i].to]) {
			next = g[v][i].ind;
			ue[g[v][i].ind] = true;
		}
		else {
			int s = dfs(g[v][i].to, v);
			if (s == -1) next = g[v][i].ind;
			else ans.push_back(std::make_pair(g[v][i].ind, s));
		}
		if (next != -1) {
			if (e == -1) e = next;
			else {
				ans.push_back(std::make_pair(e, next));
				e = -1;
			}
		}
	}
	return e;
}

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		l[i].a = (long long)c * b;
		l[i].b = (long long)(a + b) * d;
		r[i].a = (long long)(c + d) * b;
		r[i].b = (long long)a * d;
		p[i * 2] = l[i];
		p[i * 2 + 1] = r[i];
	}
	std::sort(p, p + 2 * n);
	int size = 0;
	for (int i = 0, j = 0; i < 2 * n; ++j) {
		p[j] = p[i];
		do {
			++i;
		} while (i < 2 * n && p[i] == p[j]);
		size = j + 1;
	}
	for (int i = 0; i < n; ++i) {
		int ll = std::lower_bound(p, p + size, l[i]) - p, rr = std::lower_bound(p, p + size, r[i]) - p;
		g[ll].push_back(edge(rr, i));
		g[rr].push_back(edge(ll, i));
	}
	for (int i = 0; i < size; ++i) if (!u[i]) dfs(i);
	printf("%d\n", ans.size());
	for (int i = 0; i < (int)ans.size(); ++i) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
	return 0;
}