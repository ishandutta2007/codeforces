#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, v, t[maxn], f[maxn], dp[maxn], tmp[maxn];
long long p1[maxn], p2[maxn], a[maxn]; // p1 : a + vt, p2 : a - vt;
inline int Pos(long long x, const vector<long long> &v) {
	return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}
inline int Pt(long long x, const vector<long long> &v) {
	return upper_bound(v.begin(), v.end(), x) - v.begin() + 1;
}
namespace BIT {
	vector<int> val;
	int n;
	inline void Init(int _n) {
		val.clear();
		n = _n;
		val.resize(n + 1);
		for(int j = 1; j <= n; ++ j)
			val[j] = -1e9;
	}
	inline void Update(int x, int d) {
		for(; x <= n; x += x & -x)
			val[x] = max(val[x], d);
	}
	inline int Ask(int x) {
		int res = -1e9;
		for(; x; x -= x & -x)
			res = max(res, val[x]);
		return res;
	}
}
inline void Solve(int l, int r) {
	if(l == r)
		return;
	int mid = (l + r) >> 1;
	vector<long long> va, v1, v2;
	va.clear(), v1.clear(), v2.clear();
	vector<vector<int> > add, ask;
	add.clear(), ask.clear();
	Solve(l, mid);
// cerr << "Solve(" << l << " " << mid << " " << r << ")" << endl;
	for(int i = l; i <= mid; ++ i) {
		va.push_back(a[i]);
		v1.push_back(p1[i]);
		v2.push_back(p2[i]);
// cerr << a[i] << " " << p1[i] << " " << p2[i] << " " << f[i] << endl;
	}
	for(int i = mid + 1; i <= r; ++ i)
		va.push_back(a[i]);
// for(int i = mid + 1; i <= r; ++ i)
// 	cerr << i << " " << a[i] << " " << p1[i] << " " << p2[i] << " " << f[i] << " " << f[i] << endl;
	v1.push_back(-1e18), v1.push_back(1e18);
	v2.push_back(-1e18), v2.push_back(1e18);
	sort(va.begin(), va.end());
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	va.erase(unique(va.begin(), va.end()), va.end());
	v1.erase(unique(v1.begin(), v1.end()), v1.end());
	v2.erase(unique(v2.begin(), v2.end()), v2.end());
	int sa = va.size(), s1 = v1.size(), s2 = v2.size();
	add.resize(sa + 1), ask.resize(sa + 1);
// cerr << "????" << endl;
// cerr << "????" << endl;
	for(int i = l; i <= mid; ++ i)
		add[Pos(a[i], va)].push_back(i);
// cerr << "????" << endl;
	for(int i = mid + 1; i <= r; ++ i)
		ask[Pos(a[i], va)].push_back(i);
// cerr << "????" << endl;
	BIT :: Init(s2);
	for(int i = 1; i <= sa; ++ i) {
		for(auto id : add[i])
			BIT :: Update(s2 - Pos(p2[id], v2) + 1, f[id]);
		for(auto id : ask[i])
			f[id] = max(f[id], BIT :: Ask(s2 - Pos(p2[id], v2) + 1) + 1);
	}
// for(int i = mid + 1; i <= r; ++ i)
// 	cerr << i << " " << i << " " << f[i] << endl;
	BIT :: Init(s1);
	for(int i = sa; i; -- i) {
		for(auto id : add[i])
			BIT :: Update(Pos(p1[id], v1), f[id]);
		for(auto id : ask[i])
			f[id] = max(f[id], BIT :: Ask(Pt(p1[id], v1) - 1) + 1);
	}
// for(int i = mid + 1; i <= r; ++ i)
// 	cerr << i << " " << i << " " << f[i] << endl;
	Solve(mid + 1, r);
	// int pos = l, pl = l, pr = mid + 1;
	// while(pl <= mid || pr <= r) {
	// 	if(pl > mid)
	// 		tmp[pos ++] = id[pr ++];
	// 	else if(pr > r)
	// 		tmp[pos ++] = id[pl ++];
	// 	else {
	// 		if(a[id[pl]] < a[id[pr]])
	// 			tmp[pos ++] = id[pl ++];
	// 		else
	// 			tmp[pos ++] = id[pr ++];
	// 	}
	// }
	// for(int i = l; i <= r; ++ i)
	// 	i = tmp[i];
}
inline void Brute(int out) {
	vector<int> f(n + 1, -1e9);
	f[0] = 0;
	for(int i = 1; i <= n; ++ i)
		for(int j = 0; j < i; ++ j)
			if(abs(a[i] - a[j]) <= 1ll * v * (t[i] - t[j]))
				f[i] = max(f[i], f[j] + 1);
	printf("%d\n", *max_element(f.begin(), f.end()));
	assert(out == *max_element(f.begin(), f.end()));
}
int main() {
// srand(unsigned(time(NULL)));
// n = 2e5, v = 1e6;
// n = rand() % 10 + 1, v = rand() % 10 + 1;
// printf("%d %d\n", n, v);
	scanf("%d%d", &n, &v);
	for(int i = 1; i <= n; ++ i)
		scanf("%d", &t[i]);
// t[i] = rand() % (1000000000 / n) + t[i - 1] + 1;
// t[i] = rand() % 40 + t[i - 1] + 1;
	for(int i = 1; i <= n; ++ i) {
		scanf("%lld", &a[i]);
// a[i] = rand() % 101 - 50;
// a[i] = rand() % 2000000000 - 1000000000;
		f[i] = abs(a[i]) <= 1ll * v * t[i] ? 1 : -1e9;
		p1[i] = a[i] + 1ll * v * t[i];
		p2[i] = a[i] - 1ll * v * t[i];
// cerr << a[i] << " " << t[i] << " " << p1[i] << " " << p2[i] << " " << f[i] << endl;
	}
	Solve(1, n);
// for(int i = 1; i <= n; ++ i)
// 	cerr << f[i] << " ";
// cerr << endl;
	int ans = 0;
	for(int i = 1; i <= n; ++ i)
		ans = max(ans, f[i]);
	printf("%d\n", ans);
// Brute(ans);
}