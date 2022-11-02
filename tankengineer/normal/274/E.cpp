#include<set>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005, M = 100005;
set<pair<int, int> > isBlock;
vector<int> bl1[N + M], bl2[N + M]; 
vector<pair<int, int> > v1[N + M], v2[N + M], evt[N + M];
int n, m;

struct state {
	pair<int, int> p, d;
};
bool operator < (const state &a, const state &b) {
	return a.p < b.p || a.p == b.p && a.d < b.d;
}

vector<state> route;
set<state> rem;

pair<int, int> operator + (const pair<int, int> &a, const pair<int, int> &b) {
	pair<int, int> ret = a;
	ret.first += b.first;
	ret.second += b.second;
	return ret;	
}

pair<int, int> operator - (const pair<int, int> &a, const pair<int, int> &b) {
	pair<int, int> ret = a;
	ret.first -= b.first;
	ret.second -= b.second;
	return ret;	
}

void addBlock(int x, int y) {
	isBlock.insert(make_pair(x, y));
	int dig1 = x + y, dig2 = x - y + m + 1;
	bl1[dig1].push_back(dig2);
	bl2[dig2].push_back(dig1);
}

pair<int, int> makePos(int s1, int s2) {
	s2 -= m + 1;
	return make_pair(s1 + s2 >> 1, s1 - s2 >> 1);
}

pair<int, int> makeDig(pair<int, int> p) {
	return make_pair(p.first + p.second, p.first - p.second + m + 1);
}

pair<int, int> findBlock(int x, int y, int dx, int dy) {
	int dig1 = x + y, dig2 = x - y + m + 1;
	if (dx == dy) {
		int tmp = upper_bound(bl2[dig2].begin(), bl2[dig2].end(), dig1) - bl2[dig2].begin();
		if (dx == 1) {
			return makePos(bl2[dig2][tmp], dig2);
		} else {
			return makePos(bl2[dig2][tmp - 1], dig2);
		}
	} else {
		int tmp = upper_bound(bl1[dig1].begin(), bl1[dig1].end(), dig2) - bl1[dig1].begin();
		if (dx == 1) {
			return makePos(dig1, bl1[dig1][tmp]);
		} else {
			return makePos(dig1, bl1[dig1][tmp - 1]);
		}
	}
}

pair<int, int> findBlock(state st) {
	return findBlock(st.p.first, st.p.second, st.d.first, st.d.second);
}

const int T = N + M + 5 << 1;
int sum[2][T];

int getID(int l, int r) {
	return l + r | l != r;
}

void segInsert(int t, int l, int r, int pos, int val) {
	if (pos < l || pos > r) {
		return;
	}
	sum[t][getID(l, r)] += val;
	if (l == r) {
		return;
	}
	int k = l + r >> 1;
	segInsert(t, l, k, pos, val);
	segInsert(t, k + 1, r, pos, val);
}

int segAsk(int t, int l, int r, int a, int b) {
	if (b < l || r < a) {
		return 0;
	}
	if (a <= l && r <= b) {
		return sum[t][getID(l, r)];
	}
	int k = l + r >> 1;
	return segAsk(t, l, k, a, b) + segAsk(t, k + 1, r, a, b);
}

int main() {
	int k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= n + 1; ++i) {
		addBlock(i, 0);
		addBlock(i, m + 1);
	}
	for (int i = 1; i <= m; ++i) {
		addBlock(0, i);
		addBlock(n + 1, i);
	}
	for (int i = 0; i < k; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		addBlock(x, y);
	}
	for (int i = 0; i <= n + m + 2; ++i) {
		sort(bl1[i].begin(), bl1[i].end());
		sort(bl2[i].begin(), bl2[i].end());
	}
	int sx, sy, dx, dy;
	char dir[4];
	scanf("%d%d%s", &sx, &sy, dir);
	dx = dir[0] == 'N' ? -1 : 1;
	dy = dir[1] == 'E' ? 1 : -1;
	state st;
	st.d = make_pair(dx, dy);
	st.p = findBlock(sx, sy, -dx, -dy) + st.d;
	while (!rem.count(st)) {
		rem.insert(st);
		route.push_back(st);
		pair<int, int> b = findBlock(st);
		state tmp;
		tmp.d = st.d;
		tmp.p = b - st.d;
		route.push_back(tmp);
		bool flagx = (isBlock.count(make_pair(b.first - st.d.first, b.second)));
		bool flagy = (isBlock.count(make_pair(b.first, b.second - st.d.second)));
		if (flagx == flagy) {
			st.d.first = -st.d.first;
			st.d.second = -st.d.second;
			st.p = b + st.d;
		} else {
			st.p = b;
			if (flagx) {
				st.d.second = -st.d.second;
				st.p.second += st.d.second;
			} else {
				st.d.first = -st.d.first;
				st.p.first += st.d.first;
			}
		}
	}
	int t = route.size();
	for (int i = 0; i < t; i += 2) {
		pair<int, int> d1 = makeDig(route[i].p), d2 = makeDig(route[i + 1].p);
		if (d1 > d2) {
			swap(d1, d2);
		}
		if (d1.first == d2.first) {
			v1[d1.first].push_back(make_pair(d1.second, d2.second));
		} else {
			v2[d1.second].push_back(make_pair(d1.first, d2.first));
		}
	}
	for (int i = 0; i <= n + m + 2; ++i) {
		if (v1[i].size()) {
			sort(v1[i].begin(), v1[i].end());
			v1[i].erase(unique(v1[i].begin(), v1[i].end()), v1[i].end());
		}
		if (v2[i].size()) {
			sort(v2[i].begin(), v2[i].end());
			v2[i].erase(unique(v2[i].begin(), v2[i].end()), v2[i].end());
		}
	}
	long long ans = 0;
	int INSERT = -1, DELETE = n + m + 5;
	for (int i = 0; i <= n + m + 2; ++i) {
		for (int j = 0; j < (int)v1[i].size(); ++j) {
			ans += v1[i][j].second - v1[i][j].first + 2 >> 1;
			evt[i].push_back(v1[i][j]);
		}
		for (int j = 0; j < (int)v2[i].size(); ++j) {
			ans += v2[i][j].second - v2[i][j].first + 2 >> 1;
			evt[v2[i][j].first].push_back(make_pair(INSERT, i));
			evt[v2[i][j].second].push_back(make_pair(DELETE, i));
		}
	}
	for (int i = 0; i <= n + m + 2; ++i) {
		if (evt[i].size()) {
			sort(evt[i].begin(), evt[i].end());
			for (int j = 0; j < (int)evt[i].size(); ++j) {
				pair<int, int> t = evt[i][j];
				if (t.first == INSERT) {
					segInsert(i & 1, 0, n + m + 2, t.second, 1);
				} else if (t.first == DELETE) {
					segInsert(i & 1, 0, n + m + 2, t.second, -1);
				} else {
					ans -= segAsk(i & 1, 0, n + m  + 2, t.first, t.second);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}