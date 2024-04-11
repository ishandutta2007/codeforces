#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <ctime>
#include <map>
#define ld double
#define ll long long
#define mp make_pair

using namespace std;

struct vt {
	ld x, y;

	vt(): x(0), y(0) {
	}

	vt(ld x, ld y): x(x), y(y) {

	}
};

vt operator -(vt a, vt b) {
	a.x -= b.x;
	a.y -= b.y;

	return a;
}

ld operator *(vt a, vt b) {
	return a.x * b.y - a.y * b.x;
}

ld dist(vt a) {
	return a.x * a.x + a.y * a.y;
}

vt operator *(vt a, ld x) {
	a.x *= x;
	a.y *= x;

	return a;
}

const int maxn = (int)1e5 + 10;

vt v[maxn];

bool cmp(vt a, vt b) {
	if (a * b != 0) {
		return a * b > 0;
	}

	return dist(a) < dist(b);
}

void write(vt a) {
	cout << a.x << ' ' << a.y << endl;
}

int main() {
	int n;

	cin >> n;
	ld p, q;

	cin >> p >> q;

	ld aa = 0, bb = 0;

	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &v[i].x, &v[i].y);
		aa = max(aa, v[i].x);
		bb = max(bb, v[i].y);
	}

	v[n] = vt(aa, 0);
	v[n + 1] = vt(0, bb);
	n += 2;

	sort(v, v + n, cmp);

	vector <vt> st;

	st.push_back(vt(0, 0));

	for (int i = 0; i < n; i++) {
		int len = (int)st.size();

		while (len > 1 && (v[i] - st[len - 2]) * (st[len - 1] - st[len - 2]) >= 0) {
			st.pop_back();
			len--;
		}

		st.push_back(v[i]);
	}

	vt f = vt(p, q);

	int pos = 1;

	n = (int)st.size();
	ld ans = 1e9;

	for (int i = 0; i < n - 1; i++) {
		if (st[i] * f >= 0) {
			pos = i;
		}
	}

	ld l = 0;
	ld r = 1e6;
	for (int i = 0; i < 100000; i++) {
		ld m = (l + r) / 2;

		vt g = f * m;

		if ((st[pos + 1] - st[pos]) * (g - st[pos]) > 0) {
			l = m;
		} else {
			r = m;
		}
	}

	ans = min(ans, 1.0 / l);

	printf("%.10lf", ans);

	return 0;
}