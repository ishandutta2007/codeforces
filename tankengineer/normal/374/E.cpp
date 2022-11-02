#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2000;
int n, m;
int x[N << 1], y[N << 1];

void process(vector<pair<int, pair<int, int> > > &v) {
	sort(v.begin(), v.end());
	vector<pair<int, pair<int, int> > > w;
	for (int i = 0; i < (int)v.size(); ++i) {
		int r = v[i].second.second;
		int j = i + 1;
		while (j < v.size() && v[j].first == v[i].first && v[j].second.first <= r) {
			r = max(r, v[j].second.second);
			++j;
		}
		w.push_back(make_pair(v[i].first, make_pair(v[i].second.first, r)));
		i = j - 1;
	}
	v = w;
}

int a[2005], size;

inline int lowbit(int i) {
	return i & -i;
}

void add(int pos, int val) {
	while (pos <= size) {
		a[pos] += val;
		pos += lowbit(pos);
	}
}

int ask(int pos) {
	if (pos < 0) {
		return 0;
	}
	int ret = 0;
	while (pos) {
		ret += a[pos];
		pos -= lowbit(pos);
	}
	return ret;
}

int getsum(int pos1, int pos2) {
	return ask(pos2) - ask(pos1 - 1);
}

bool check(int t) {
	vector<pair<int, pair<int, int> > > shu, heng;
	vector<int> xs;
	for (int i = 0; i < n; ++i) {
		shu.push_back(make_pair(x[i], make_pair(y[i] - 2 * t, y[i] + 2 * t)));
		xs.push_back(x[i]);
	}
	process(shu);
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	size = xs.size();
	for (int i = n; i < n + m; ++i) {
		heng.push_back(make_pair(y[i], make_pair(x[i] - 2 * t, x[i] + 2 * t)));
	}
	process(heng);
	memset(a, 0, sizeof(a));
	for (int i = 0; i < (int)heng.size(); ++i) {
		vector<pair<int, pair<int, int> > > evt;
		for (int j = 0; j < (int)shu.size(); ++j) {
			if (shu[j].first >= heng[i].second.first && shu[j].first <= heng[i].second.second) {
				if (shu[j].second.first <= heng[i].first && shu[j].second.second >= heng[i].first) {
					int t = lower_bound(xs.begin(), xs.end(), shu[j].first) - xs.begin() + 1;
					add(t, 1);
					evt.push_back(make_pair(shu[j].second.second, make_pair(1, t)));
				}
			}
		}
		for (int j = i + 1; j < (int)heng.size(); ++j) {
			if (heng[j].first > heng[i].first) {
				evt.push_back(make_pair(heng[j].first, make_pair(-1, j)));
			}
		}
		sort(evt.begin(), evt.end());
		for (int j = 0; j < (int)evt.size(); ++j) {
			if (evt[j].second.first == -1) {
				int k = evt[j].second.second;
				int l = heng[k].second.first, r = heng[k].second.second;
				l = lower_bound(xs.begin(), xs.end(), l) - xs.begin() + 1;
				r = upper_bound(xs.begin(), xs.end(), r) - xs.begin() - 1 + 1;
				if (l >= r) {
					continue;
				}
				if (getsum(l, r) >= 2) {
					return true;
				}
			} else {
				int t = evt[j].second.second;
				add(t, -1);
			}
		}
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int xx, yy;
		scanf("%d%d", &xx, &yy);
		x[i] = (xx + yy);
		y[i] = (xx - yy);
	}
	for (int i = n; i < n + m; ++i) {
		int xx, yy;
		scanf("%d%d", &xx, &yy);
		x[i] = (xx + yy);
		y[i] = (xx - yy);
	}
	int l = 0, r = 20000000, m;
	if (!check(r)) {
		puts("Poor Sereja!\n");
	} else {
		while (l != r) {
			m = l + r >> 1;
			if (check(m)) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		printf("%d\n", r);
	}
	return 0;
}