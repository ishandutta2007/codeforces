#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define ll long long
#define fi first
#define se second
using namespace std;

const int N = 222000;
const double pi = acos(-1);

int x[N], y[N], f[N];
ll n, k;
double ang[N][2], all[N];

struct node {
	int l, r, type;
};

void add(int x, int val) {
	for (; x < N; x += x & -x)
		f[x] += val;
}

int query(int x) {
	int res = 0;
	for (; x; x -= x & -x)
		res += f[x];
	return res;
}

ll solve(double r) {
	int top = 0, cnt = 0;
	rep(i, 1, n) {
		double d = sqrt(x[i] * x[i] + y[i] * y[i]);
		if (d < r) continue;
		double angle = acos(r / d);
		double a = atan2(y[i], x[i]) - angle;
		double b = atan2(y[i], x[i]) + angle;
		for (; a < 0; a += 2 * pi);
		for (; b < 0; b += 2 * pi);
		for (; a >= 2 * pi; a -= 2 * pi);
		for (; b >= 2 * pi; b -= 2 * pi); 
		if (a > b) swap(a, b);
		all[++cnt] = a;
		all[++cnt] = b;
		top++;
		ang[top][0] = a;
		ang[top][1] = b;
	}
	sort(all + 1, all + cnt + 1);
	cnt = unique(all + 1, all + cnt + 1) - all - 1;
	vector<node> ev;
	rep(i, 1, top) {
		int x = lower_bound(all + 1, all + cnt + 1, ang[i][0]) - all;
		int y = lower_bound(all + 1, all + cnt + 1, ang[i][1]) - all;
		ev.push_back({x, y, 0});
		ev.push_back({y, x, 1});
	}
	sort(ev.begin(), ev.end(), [&](node a, node b) {
		return a.l < b.l;
	});
	memset(f, 0, sizeof f);
	ll res = 0;
	for (auto &[l, r, type] : ev) {
		if (type == 0) 
			add(l, 1);
		else {
			swap(l, r);
			res += query(r) - query(l - 1) - 1;
			add(l, -1);
		}
	}
	return res;		
}
 
int main() {
	cin >> n >> k;
	rep(i, 1, n) cin >> x[i] >> y[i];
	double l = 0, r = 1e5;
	rep(q, 1, 50) {
		double m = (l + r) * 0.5;
		if (k <= n * (n - 1) / 2 - solve(m))
			r = m;
		else
			l = m;
	}
	cout << setprecision(20) << l << endl;
	return 0;
}