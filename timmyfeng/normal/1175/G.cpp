#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using pt = pair<ll, ll>;
#define x first
#define y second
const int MXN = 2e4;
const int MXM = 1e2;
const int INF = 1e9;

pt operator-(pt a, pt b) {
	return {a.x - b.x, a.y - b.y};
}
pt operator*(pt a, pt b) {
	return {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};
}
ll dot(pt a, pt b) {
	return a.x * b.x + a.y * b.y;
}
ll cross(pt a, pt b) {
	return a.x * b.y - a.y * b.x;
}

struct cht {
	deque<pt> hull, vecs;

	void addfront(pt ln) {
		while (!vecs.empty() && dot(vecs.front(), ln - hull.front()) < 0) {
			hull.pop_front();
			vecs.pop_front();
		}
		if (!hull.empty()) {
			vecs.push_front((hull.front() - ln) * pt{0, 1});
		}
		hull.push_front(ln);
	}

	void addback(pt ln) {
		while (!vecs.empty() && dot(vecs.back(), ln - hull.back()) < 0) {
			hull.pop_back();
			vecs.pop_back();
		}
		if (!hull.empty()) {
			vecs.push_back((ln - hull.back()) * pt{0, 1});
		}
		hull.push_back(ln);
	}

	ll qry(int x) {
		auto it = lower_bound(vecs.begin(), vecs.end(), pt{x, 1}, [](pt a, pt b){
			return cross(a, b) > 0;
		});
		return dot(hull[it - vecs.begin()], {x, 1});
	}
};

int chd[MXN * 100][2], a[MXN + 1], sz, n;
ll dp[2][MXN + 1]; 
pt lct[MXN * 100];

int newnode(int chd0, int chd1, pt ln) {
	int u = ++sz;
	chd[u][0] = chd0;
	chd[u][1] = chd1;
	lct[u] = ln;
	return u;
}

int upd(pt ln, int u, int l = 1, int r = n) {
	if (!u)
		return newnode(0, 0, ln);
	int m = (l + r) / 2;
	bool mnl = dot(ln, {l, 1}) < dot(lct[u], {l, 1});
	bool mnm = dot(ln, {m, 1}) < dot(lct[u], {m, 1});
	pt res = lct[u];
	if (mnm) {
		swap(res, ln);
	}
	if (l == r)
		return newnode(0, 0, res);
	if (mnl == mnm)
		return newnode(chd[u][0], upd(ln, chd[u][1], m + 1, r), res);
	return newnode(upd(ln, chd[u][0], l, m), chd[u][1], res);
}

ll qry(int x, int u, int l = 1, int r = n) {
	if (!u)
		return INF;
	int m = (l + r) / 2;
	ll res = dot(lct[u], {x, 1});
	if (l == r) 
		return res;
	if (x <= m) 
		return min(res, qry(x, chd[u][0], l, m));
	return min(res, qry(x, chd[u][1], m + 1, r));
}

void merge(cht& a, cht& b) {
	if (b.hull.size() > a.hull.size()) {
		for (auto it = a.hull.rbegin(); it != a.hull.rend(); ++it) {
			b.addfront(*it);
		}
		swap(a, b);
	} else {
		for (auto i : b.hull) {
			a.addback(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	fill(dp[0] + 1, dp[0] + 1 + n, INF);
	for (int i = 1; i <= k; ++i) {
		sz = 0;
		int r = i % 2;
		vector<cht> hulls;
		vector<int> mx, rt = {0};
		for (int j = 0; j <= n; ++j) {
			dp[r][j] = qry(j, rt.back());
			if (j == n)
				continue;
			cht cur;
			cur.addback({-j, dp[!r][j]});
			while (!mx.empty() && a[j] > mx.back()) {
				mx.pop_back();
				rt.pop_back();
				merge(cur, hulls.back());
				hulls.pop_back();
			}
			mx.push_back(a[j]);
			rt.push_back(upd({a[j], cur.qry(a[j])}, rt.back()));
			hulls.push_back(move(cur));
		}
	}
	cout << dp[k % 2][n] << '\n';
}