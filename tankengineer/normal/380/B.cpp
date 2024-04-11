#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define left LEFT
#define right RIGHT

const int N = 7005;

int n, m, cnt[N];

struct Operation {
	int t, l, r, x;

	void in() {
		scanf("%d%d%d%d", &t, &l, &r, &x);
		--t, --l, --r;
	}

	bool check(int ll, int rr) {
		return min(rr, r) >= max(ll, l);
	}
};

bool ispower(int x) {
	int c = x;
	while (~c & 1) {
		c >>= 1;
	}
	return c == 1;
}

int cntnext(int n) {
	int ret = n, x = 1;
	while (x <= n) {
		++ret;
		x <<= 1;
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	cnt[0] = 1;				
	for (int i = 0; i + 1 < n; ++i) {
		cnt[i + 1] = 0;
		for (int j = 0; j < cnt[i]; ++j) {
			if (ispower(j + 1)) {
				cnt[i + 1] += 2;
			} else {
				cnt[i + 1] += 1;
			}
		}
	}
	vector<Operation> op;
	for (int i = 0; i < m; ++i) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			Operation tmp;
			tmp.in();
			op.push_back(tmp);
		} else {
			int t, v;
			scanf("%d%d", &t, &v);
			--t, --v;
			vector<pair<int, int> > range;
			range.push_back(make_pair(v, v));
			int l = v, r = v;
			for (int j = t; j + 1 < n; ++j) {
				l = cntnext(l);
				if (ispower(r + 1)) {
					r = cntnext(r) + 1;
				} else {
					r = cntnext(r);
				}
				range.push_back(make_pair(l, r));
			}
			vector<int> ans;
			for (int j = 0; j < (int)op.size(); ++j) {
				if (op[j].t >= t && op[j].check(range[op[j].t - t].first, range[op[j].t - t].second)) {
					ans.push_back(op[j].x);
				}
			}
			sort(ans.begin(), ans.end());
			ans.erase(unique(ans.begin(), ans.end()), ans.end());
			printf("%d\n", (int)ans.size());
		}
	}
	return 0;
}