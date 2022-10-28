#include <bits/stdc++.h>
using namespace std;

using point = complex<long long>;
#define x real()
#define y imag()

long long cross(point u, point v) {
	return (u * conj(v)).y;
}

long long orient(point a, point b, point c) {
	return cross(b - a, c - a);
}

struct cmp_x {
	bool operator()(point a, point b) const {
		return make_tuple(a.x, a.y) < make_tuple(b.x, b.y);
	}
};

vector<point> convex_hull(vector<point> pts) {
	vector<point> res;
	for (int k = 0; k < 2; ++k) {
		int start = res.size();
		for (auto i : pts) {
			while (int(res.size()) - start >= 2 &&
					orient(res[res.size() - 2u], res[res.size() - 1u], i) <= 0) {
				res.pop_back();
			}
			res.push_back(i);
		}
		res.pop_back();
		reverse(pts.begin(), pts.end());
	}

	if (res.size() == 2u && res[0] == res[1]) {
		res.pop_back();
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<point> pts;
	map<point, int, cmp_x> mp;
	for (int i = 1; i <= n; ++i) {
		int xi, yi;
		cin >> xi >> yi;
		pts.emplace_back(xi, yi);
		mp[pts.back()] = i;
	}
	sort(pts.begin(), pts.end(), cmp_x());

	string s;
	cin >> s;

	vector<point> hull = convex_hull(pts);
	vector<int> ans;
	point cur;

	auto add = [&](point p) {
		cur = p;
		ans.push_back(mp[p]);
		pts.erase(find(pts.begin(), pts.end(), p));
	};

	add(hull[0]);

	for (int i = 0; i < n - 2; ++i) {
		int ndx = find(hull.begin(), hull.end(), cur) - hull.begin();
		if (s[i] == 'R') {
			ndx = (ndx + 1) % int(hull.size());
		} else {
			ndx = (ndx - 1 + int(hull.size())) % int(hull.size());
		}
		point tmp = hull[ndx];
		hull = convex_hull(pts);
		add(tmp);
	}

	add(hull[0] == cur ? hull[1] : hull[0]);

	for (auto& i : ans) {
		cout << i << " ";
	}
	cout << "\n";
}