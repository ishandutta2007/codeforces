#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

template <class T>
struct monotonic_hull {

	struct line {
		T m, b;

		T floor_div(T a, T b) {
			return a / b - ((a ^ b) < 0 && a % b);
		}
		T intersect(line oth) {
			return floor_div(b - oth.b, oth.m - m);
		}
		T evaluate(T x) {
			return m * x + b;
		}
	};

	vector<line> hull;

	void update(T m, T b) {
		line ln = {m, b};

		if (!hull.empty() && ln.m == hull.back().m) {
			if (ln.b <= hull.back().b)
				return;
			hull.pop_back();
		}

		while (hull.size() >= 2u) {
			T x1 = ln.intersect(hull[hull.size() - 1u]);
			T x2 = ln.intersect(hull[hull.size() - 2u]);
			if (x1 <= x2)
				break;
			hull.pop_back();
		}
		hull.push_back(ln);
	}

	pair<T, T> query(T x) {
		while (hull.size() >= 2u) {
			T y1 = hull[hull.size() - 1u].evaluate(x);
			T y2 = hull[hull.size() - 2u].evaluate(x);
			if (y1 < y2)
				break;
			hull.pop_back();
		}
		return make_pair(hull.back().m, hull.back().evaluate(x));
	}

};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	monotonic_hull<long long> cht;
	cht.update(0, 0);

	long long sum_s = 0;
	long long sum_b = 0;
	while (m--) {
		int type;
		cin >> type;
		if (type == 1) {
			int k;
			cin >> k;

			cht.hull.clear();
			cht.update(0, 0);
			sum_b = 0;
			sum_s = 0;
			n += k;
		} else if (type == 2) {
			int k;
			cin >> k;

			cht.update(n, -(sum_s * n + sum_b));
			n += k;
		} else {
			int b, s;
			cin >> b >> s;

			sum_b += b;
			sum_s += s;
		}
		auto [j, a] = cht.query(sum_s);
		cout << j + 1 << " " << a + sum_b << "\n";
	}
}