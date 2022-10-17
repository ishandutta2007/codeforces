#include <cstdio>
#include <algorithm>
#include <utility>

const int N = 200000;
int n, m, q, a[N], b[N], in[N << 1];
std::pair<int, int> val[N << 1], d[N << 1];
std::pair<int, long long> res[N << 1];

struct dsu {
	dsu *p;
	int left, right, inside;
	dsu() {
		p = 0;
	}
	dsu *find() {
		if (!p) return this;
		return p = p->find();
	}
} du[N << 1];

int main() 
{
	scanf("%d%d%d", &n, &m, &q);
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		sum += a[i];
		val[i] = std::make_pair(a[i], 1);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", b + i);
		val[n + i] = std::make_pair(b[i], 0);
	}
	n += m;
	std::sort(val, val + n);
	for (int i = 0; i < n; ++i) {
		du[i].left = i;
		du[i].right = i + 1;
		du[i].inside = val[i].second;
	}
	for (int i = 0; i < n - 1; ++i) d[i] = std::make_pair(val[i + 1].first - val[i].first, i);
	std::sort(d, d + n - 1);
	int amt = 0;
	res[0] = std::make_pair(0, sum);
	for (int i = 0, j = 1; i < n - 1;) {
		do {
			dsu *l = du[d[i].second].find(), *r = du[d[i].second + 1].find();
			while (l->inside && r->inside < r->right - r->left) {
				++r->inside;
				sum += val[r->right - r->inside].first - val[l->right - l->inside].first;
				--l->inside;
			}
			l->p = r;
			r->left = l->left;
			r->inside += l->inside;
			++i;
		} while (i < n - 1 && d[i].first == d[i - 1].first);
		res[j] = std::make_pair(d[i - 1].first, sum);
		++j;
		amt = j;
	}
	while (q--) {
		int k;
		scanf("%d", &k);
		printf("%lld\n", (std::lower_bound(res, res + amt, std::make_pair(k, ~((long long)1 << 63))) - 1)->second);
	}
	return 0;
}