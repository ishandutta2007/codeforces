#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

const int N = 100050, M = N << 1;
int n, m;

int getID(const int l, const int r) {
	return l + r | l != r;
}

struct segTree {
	
	int maxs[M << 1];

	segTree() {
		memset(maxs, 0, sizeof(maxs));
	}

	void insert(const int l, const int r, const int pos, const int val) {
		if (pos < l || pos > r) {
			return ;
		}
		if (l == r) {
			maxs[getID(l, r)] = val;
		} else {
			int k = (l + r) >> 1;
			insert(l, k, pos, val);
			insert(k + 1, r, pos, val);
			maxs[getID(l, r)] = max(maxs[getID(l, k)], maxs[getID(k + 1, r)]);
		}
	}

	int query(const int l, const int r, const int a, const int b) {
		if (b < l || r < a) {
			return 0;
		}
		if (a <= l && r <= b) {
			return maxs[getID(l, r)];
		}
		int k = (l + r) >> 1;
		return max(query(l, k, a, b), query(k + 1, r, a, b)); 
	}

} x, y;

int main() {
	set<pair<int, int> > hei, pos;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int tp, th;
			scanf("%d%d", &tp, &th);
			--tp;
			th = th - i + m;
			hei.insert(make_pair(th, tp));
			pos.insert(make_pair(tp, th));
			vector<pair<int, int> > tmp;
			for (set<pair<int, int> >::iterator it = hei.begin(); it != hei.end() && (*it).first <= th; ++it) {
				tmp.push_back(*it);
				x.insert(0, 10 + m, (*it).first, 0);
				y.insert(0, n - 1, (*it).second, 0);
			}
			reverse(tmp.begin(), tmp.end());
			for (int i = 0; i < (int)tmp.size(); ++i) {
				int tp = tmp[i].second, th = tmp[i].first, tans;
				tans = y.query(0, n - 1, tp, n - 1) + 1;
				x.insert(0, 10 + m, th, tans);
				y.insert(0, n - 1, tp, tans);
			}
		} else {
			int to;
			scanf("%d", &to);
			vector<pair<int, int> > tmp;
			set<pair<int, int> >::iterator it = pos.begin();
			for (int i = 0; i < to; ++i, ++it) {
				tmp.push_back(*it);
				x.insert(0, 10 + m, tmp.back().second, 0);
				y.insert(0, n - 1, tmp.back().first, 0);
			}
			pos.erase(tmp.back());
			hei.erase(make_pair(tmp.back().second, tmp.back().first));
			tmp.pop_back();
			reverse(tmp.begin(), tmp.end());
			for (int i = 0; i < (int)tmp.size(); ++i) {
				int tp = tmp[i].first, th = tmp[i].second, tans;
				tans = x.query(0, 10 + m, th, 10 + m) + 1;
				x.insert(0, 10 + m, th, tans);
				y.insert(0, n - 1, tp, tans);
			}
		}
		printf("%d\n", y.query(0, n - 1, 0, n - 1));
	}
	return 0;
}