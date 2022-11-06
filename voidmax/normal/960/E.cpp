#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#include <iomanip>      
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;

template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }

const string FILENAME = "input";

typedef long double base;
typedef pair<base, base> point;

const int MAXN = 2e5 + 10, p = 1e9 + 7;

int sum(int a, int b) {
	a += b;
	return a >= p ? a - p : a;
}

int mul(long long a, int b) {
	return a * b % p;
}

struct way {
	int cnt, w;
	way() {
		cnt = w = 0;
	}
};

int v[MAXN];
vector<int> edge[MAXN];

int n, ans;

pair<way, way> dfs(int i, int pr = -1) {
	pair<way, way> cur;
	cur.y.cnt = 1;
	cur.y.w = v[i];
	ans = sum(ans, v[i]);
	for (auto j : edge[i]) {
		if (pr == j) continue;
		auto res = dfs(j, i);
		pair<way, way> nans;
		for (int t = 0; t < 2; ++t) {
			ans = sum(ans, sum(mul(cur.x.cnt, res.y.w), mul(res.y.cnt, cur.x.w))); 
			ans = sum(ans, sum(mul(cur.y.cnt, res.y.w), mul(res.y.cnt, p - cur.y.w)));
			ans = sum(ans, sum(mul(cur.x.cnt, res.x.w), mul(res.x.cnt, p - cur.x.w)));
			ans = sum(ans, sum(mul(cur.y.cnt, res.x.w), mul(res.x.cnt, cur.y.w)));
			swap(res, cur);
		}
		swap(res.x, res.y);

		res.x.w = sum(res.x.w, p - mul(v[i], res.x.cnt));
		res.y.w = sum(res.y.w, mul(v[i], res.y.cnt));

		cur.x.w = sum(cur.x.w, res.x.w);
		cur.x.cnt = sum(cur.x.cnt, res.x.cnt);
		cur.y.w = sum(cur.y.w, res.y.w);
		cur.y.cnt = sum(cur.y.cnt, res.y.cnt);
	}
	return cur;
} 

int main() {
	srand(time(0));
	//read(FILENAME);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		v[i] = sum(v[i], p);
	}
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		edge[a].pb(b);
		edge[b].pb(a);
	}
	dfs(0);
	cout << ans << endl;
}