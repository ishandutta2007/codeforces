#include <bits/stdc++.h> 
using namespace std;

using ld = long double;
using pt = complex<ld>;
#define x real()
#define y imag()

const int MX = 25000;
const ld EPS = 1e-12;

ld dot(pt p, pt q) {
	return (conj(p) * q).x;
}

ld cross(pt p, pt q) {
	return (conj(p) * q).y;
}

ld sqr(pt p) {
	return dot(p, p);
}

struct line {
	pt v, init, delta;
	ld s, c;

	line() {}

	line(pt v, pt init, ld s) : 
			v(v), init(init), delta(polar(s, atan2l(v.y, v.x))), s(s), c(cross(v, init)) {}
} lns[MX];

set<pair<line, int>>::iterator where[MX];
ld cur_x;
int n;

bool intersect(const line& p, const line& q, ld t) {
	ld d = cross(p.v, q.v);

	if (abs(d) < EPS) {
		if (abs(cross(p.v, q.init) - p.c) < EPS) {
			bool coll_p = dot(p.v, p.init) <= dot(p.v, q.init) + EPS;
			bool coll_q = dot(q.v, q.init) <= dot(q.v, p.init) + EPS;

			if (coll_p && coll_q) {
				return sqr(q.init - p.init) / ((p.s + q.s) * (p.s + q.s)) <= t * t + EPS;
			} else if (coll_p) {
				return sqr(q.init - p.init) / (p.s * p.s) <= t * t + EPS;
			} else if (coll_q) {
				return sqr(q.init - p.init) / (q.s * q.s) <= t * t + EPS;
			}
		}
		return false;
	}

	pt res = (q.v * p.c - p.v * q.c) / d;
	return dot(p.v, p.init) <= dot(p.v, res) + EPS && 
			dot(q.v, q.init) <= dot(q.v, res) + EPS &&
			sqr(res - p.init) / (p.s * p.s) <= t * t + EPS &&
			sqr(res - q.init) / (q.s * q.s) <= t * t + EPS;
}

bool operator<(const line& p, const line& q) {
	return (p.c + p.v.y * cur_x) / p.v.x < (q.c + q.v.y * cur_x) / q.v.x;
}

bool chk(ld t) {
	vector<pair<ld, int>> events;
	for (int i = 0; i < n; ++i) {
		events.emplace_back(lns[i].init.x, i);
		events.emplace_back(lns[i].init.x + t * lns[i].delta.x, i);
	}
	sort(events.begin(), events.end());

	set<pair<line, int>> bst;
	fill(where, where + n, bst.end());
	for (auto e : events) {
		cur_x = e.first;
		int i = e.second;

		if (where[i] != bst.end()) {
			if (where[i] != bst.begin() && where[i] != --bst.end()) {
				auto pre = prev(where[i]);
				auto nxt = next(where[i]);
				if (intersect(pre->first, nxt->first, t))
					return true;
			}
			bst.erase(where[i]);
		} else {
			where[i] = bst.emplace(lns[i], i).first;
			if (where[i] != bst.begin()) {
				auto pre = prev(where[i]);
				if (intersect(pre->first, lns[i], t))
					return true;
			}
			if (where[i] != --bst.end()) {
				auto nxt = next(where[i]);
				if (intersect(lns[i], nxt->first, t))
					return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(12);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x0, y0, dx, dy, s;
		cin >> x0 >> y0 >> dx >> dy >> s;
		lns[i] = line(pt(dx, dy), pt(x0, y0), s);
	}

	bool ok = false;
	ld lb = 0, rb = 1e12;
	for (int k = 0; k < 100; ++k) {
		ld mb = (lb + rb) / 2;
		if (chk(mb)) {
			ok = true;
			rb = mb;
		} else {
			lb = mb;
		}
	}

	if (!ok) {
		cout << "No show :(" << '\n';
	} else {
		cout << lb << '\n';
	}
}