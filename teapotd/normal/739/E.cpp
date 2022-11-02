#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int,int>;
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for (int i = (b); i < (e); i++)
#define each(a,x) for (auto& a : (x))
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())

int n, a, b;
vector<double> p, q;

pair<double, Pii> check(double ka, double kb) {
	pair<double, Pii> ret = {0, {0,0}};
	rep(i, 0, n) {
		pair<double, Pii> alt1 = {ret.x+p[i]-ka, {ret.y.x+1, ret.y.y}};
		pair<double, Pii> alt2 = {ret.x+q[i]-kb, {ret.y.x, ret.y.y+1}};
		pair<double, Pii> alt3 = {ret.x+p[i]+q[i]-p[i]*q[i]-ka-kb, {ret.y.x+1, ret.y.y+1}};
		ret = max(max(max(ret, alt1), alt2), alt3);
	}
	return ret;
}

template<class T, class F>
T parametricSearch(double begin, double end, int wanted, F func) {
	rep(i, 0, 40) {
		double mid = (begin+end) / 2;
		pair<T, int> ret = func(mid);
		if (ret.y < wanted) {
			end = mid;
		} else if (ret.y > wanted) {
			begin = mid;
		} else {
			return ret.x;
		}
	}
	return func(begin).x;
}

int main() {
	cin.sync_with_stdio(0);
	cout << fixed << setprecision(4);

	cin >> n >> a >> b;
	p.resize(n);
	q.resize(n);
	each(k, p) cin >> k;
	each(k, q) cin >> k;

	double ans = parametricSearch<double>(0, 1, a, [](double ka) {
		return parametricSearch<pair<double, int>>(0, 1, b, [ka](double kb) {
			auto tmp = check(ka, kb);
			tmp.x += ka*a + kb*b;
			return make_pair(make_pair(tmp.x, tmp.y.x), tmp.y.y);
		});
	});

	cout << ans << endl;
	return 0;
}