#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>

const int N = 1000005;
int n, m, q, sc, c[N];
std::pair<int, int> seg[N << 1];
std::vector<int> cadd[N];
std::vector<long long> sum[N];
std::pair<int, int> qq[N];
char type[10];
long long ans[N], b[N];
bool ask[N], was[N];

long long calc(int c, int l, int r) {
	return sum[c][std::lower_bound(cadd[c].begin(), cadd[c].end(), r) - cadd[c].begin()] - sum[c][std::lower_bound(cadd[c].begin(), cadd[c].end(), l) - cadd[c].begin()];
}

std::set<int> now;

void add(int i, long long x) {
	while (i <= q) {
		b[i] += x;
		i |= i + 1;
	}
}

long long get(int i) {
	long long s = 0;
	while (i >= 0) {
		s += b[i];
		i = (i & i + 1) - 1;
	}
	return s;
}

void ins(std::set<int>::iterator it, int k) {
	if (it != now.end()) add(*it, k * calc(c[*prev(it)], *prev(it), *it));
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < N; ++i) sum[i].resize(1);
	for (int i = 1; i <= q; ++i) {
		scanf("%s", type);
		if (*type == 'C') {
			int l, r;
			scanf("%d%d%d", &l, &r, c + i);
			--c[i];
			seg[sc << 1].first = l - 1;
			seg[sc << 1 | 1].first = r;
			seg[sc << 1].second = seg[sc << 1 | 1].second = i;
			++sc;
		} else if (*type == 'A') {
			int c, x;
			scanf("%d%d", &c, &x);
			--c;
			cadd[c].push_back(i);
			sum[c].push_back(x);
		} else {
			int x;
			scanf("%d", &x);
			qq[m] = std::make_pair(x - 1, i);
			ask[i] = 1;
			++m;
		}
	}
	for (int i = 0; i < N; ++i) for (int j = 1; j < (int)sum[i].size(); ++j) sum[i][j] += sum[i][j - 1];
	now.insert(0);
	std::sort(seg, seg + sc * 2);
	std::sort(qq, qq + m);
	for (int i = 0, j = 0, k = 0; i < n; ++i) {
		while (k < sc * 2 && seg[k].first == i) {
			std::set<int>::iterator it = now.lower_bound(seg[k].second);
			if (was[seg[k].second]) {
				ins(it, -1);
				++it;
				ins(it, -1);
				now.erase(seg[k].second);
				ins(now.lower_bound(seg[k].second), 1);
			} else {
				ins(it, -1);
				it = now.insert(seg[k].second).first;
				ins(it, 1);
				++it;
				ins(it, 1);
			}
			was[seg[k].second] = 1;
			++k;
		}
		while (j < m && qq[j].first == i) {
			std::set<int>::iterator it = prev(now.lower_bound(qq[j].second));
			ans[qq[j].second] = get(qq[j].second) + calc(c[*it], *it, qq[j].second);
			++j;
		}
	}
	for (int i = 1; i <= q; ++i) if (ask[i]) printf("%lld\n", ans[i]);
	return 0;
}