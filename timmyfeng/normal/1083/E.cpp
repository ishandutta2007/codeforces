#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

struct rect {
	int x, y;
	long long a;
	operator<(rect oth) {
		return x < oth.x;
	}
} rects[N];

template <class T>
struct monotonic_hull {

	struct line {
		T m, b;
		T floor_div(T a, T b) {
			return a / b - ((a ^ b) < 0 && a % b != 0);
		}
		T intersect(line oth) {
			return floor_div(b - oth.b, oth.m - m);
		}
		T evaluate(T x) {
			return m * x + b;
		}
	} hull[N];

	int back = 0;
	int front = 0;

	void update(T m, T b) {
		line ln = {m, b};
		while (back - front >= 2) {
			T x1 = ln.intersect(hull[back - 1]);
			T x2 = hull[back - 1].intersect(hull[back - 2]);
			if (x1 < x2)
				break;
			--back;
		}
		hull[back] = ln;
		++back;
	}

	T query(T x) {
		while (back - front >= 2) {
			T y1 = hull[front].evaluate(x);
			T y2 = hull[front + 1].evaluate(x);
			if (y1 > y2)
				break;
			++front;
		}
		return hull[front].evaluate(x);
	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> rects[i].x >> rects[i].y >> rects[i].a;
	}
	sort(rects, rects + n);

	monotonic_hull<long long> cht;
	cht.update(0, 0);

	for (int i = 0; i < n; ++i) {
	cht.update(-rects[i].x, 1LL * rects[i].x * rects[i].y - rects[i].a + cht.query(rects[i].y));
	}

	cout << cht.query(0) << "\n";
}