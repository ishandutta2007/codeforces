#include <bits/stdc++.h>
#define double long double

using namespace std;

const double EPS = 1E-12, INF = 1e15 + 7;
 
struct pt {
	double x, y;
    pt() {}
    pt(double x, double y): x(x), y(y) {}
    pt operator + (pt a) {
        return pt(x + a.x, y + a.y);
    }
    pt operator - (pt a) {
        return pt(x - a.x, y - a.y);
    }
    pt mul(double k) {
        return pt(x * k, y * k);
    }
    double len() {
        return sqrt(x * x + y * y);
    }
    pt set_len(double k) {
        return mul(k / len());
    }
};
 
struct seg {
	pt p, q;
    int id;
    seg() {}
    seg(pt p, pt q, int id): p(p), q(q), id(id) {}
	double get_y (double x) const {
		if (abs (p.x - q.x) < EPS)  return p.y;
		return p.y + (q.y - p.y) * (x - p.x) / (q.x - p.x);
	}
};
 
 
inline bool intersect1d (double l1, double r1, double l2, double r2) {
	if (l1 > r1)  swap (l1, r1);
	if (l2 > r2)  swap (l2, r2);
	return max (l1, l2) <= min (r1, r2) + EPS;
}
 
inline int vec (const pt & a, const pt & b, const pt & c) {
	double s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	return abs(s)<EPS ? 0 : s>0 ? +1 : -1;
}
 
bool intersect (const seg & a, const seg & b) {
	return intersect1d (a.p.x, a.q.x, b.p.x, b.q.x)
		&& intersect1d (a.p.y, a.q.y, b.p.y, b.q.y)
		&& vec (a.p, a.q, b.p) * vec (a.p, a.q, b.q) <= 0
		&& vec (b.p, b.q, a.p) * vec (b.p, b.q, a.q) <= 0;
}
 
 
bool operator< (const seg & a, const seg & b) {
	double x = max (min (a.p.x, a.q.x), min (b.p.x, b.q.x));
	return a.get_y(x) < b.get_y(x) - EPS;
}
 
 
struct event {
	double x;
	int tp, id;
 
	event() { }
	event (double x, int tp, int id)
		: x(x), tp(tp), id(id)
	{ }
 
	bool operator< (const event & e) const {
		if (abs (x - e.x) > EPS)  return x < e.x;
		return tp > e.tp;
	}
};
 
set<seg> s;
vector < set<seg>::iterator > where;
vector<event> e;
 
inline set<seg>::iterator prev (set<seg>::iterator it) {
	return it == s.begin() ? s.end() : --it;
}
 
inline set<seg>::iterator next (set<seg>::iterator it) {
	return ++it;
}

int dbg = 0;
 
bool solve (const vector<seg> & a) {
    s.clear();
    e.clear();
	int n = (int) a.size();
	for (int i=0; i<n; ++i) {
		e.push_back (event (min (a[i].p.x, a[i].q.x), +1, i));
		e.push_back (event (max (a[i].p.x, a[i].q.x), -1, i));
	}
	sort (e.begin(), e.end());
    //cout << "Here!" << endl;
	for (size_t i=0; i<e.size(); ++i) {
        //cout << i << endl;
		int id = e[i].id;
		if (e[i].tp == +1) {
            //cout << "kek" << endl;
			set<seg>::iterator
				nxt = s.lower_bound (a[id]),
				prv = prev (nxt);
			if (nxt != s.end() && intersect (*nxt, a[id]))
				return 1;
			if (prv != s.end() && intersect (*prv, a[id]))
				return 1;
			where[id] = s.insert (nxt, a[id]);
		}
		else {
            //cout << "lol" << endl;
			set<seg>::iterator
				nxt = next (where[id]),
				prv = prev (where[id]);
			if (nxt != s.end() && prv != s.end() && intersect (*nxt, *prv))
				return 1;
            //int kek = where[id];
            //cout << 128 << endl;
			 s.erase (where[id]);
            //cout << 130 << endl;
		}
	}
	return 0;
}


signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
    //freopen("Desktop/input.txt", "r", stdin);
    int n;
    cin >> n;
    pt p[n], d[n];
    double s[n];
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y >> d[i].x >> d[i].y >> s[i];
    double l = 0, r = INF, mid;
    bool flag = 0;
    where.resize(n);
    for (int step = 0; step < 80; step++) {
        //cout << step << endl;
        dbg = step;
        mid = (l + r) / 2;
        vector <seg> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = seg(p[i], p[i] + d[i].set_len(s[i] * mid), i);
        }
        if (solve(v)) {
            flag = 1;
            r = mid;
        } else {
            l = mid;
        }
    }
    if (!flag) cout << "No show :(" << endl;
    else cout << fixed << r << endl;
}