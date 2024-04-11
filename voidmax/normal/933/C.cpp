// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
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
  
typedef long double base;
typedef pair<base, base> point;

const string FILENAME = "input";

const base eps = 1e-7;
const int MAXN = 1e5;

base r[3];
point a[3];

base vec(point a, point b) {
	return a.x * b.y - a.y * b.x;
}

bool half(point a) {
	if (a.x != 0) return a.x < 0;
	return a.y < 0;
}

point operator + (point a, point b) {
	return {a.x + b.x, a.y + b.y};
}

point operator - (point a, point b) {
	return {a.x - b.x, a.y - b.y};
}

base dist(point a, point b) {
	return hypot(a.x - b.x, a.y - b.y);
}

point c;

bool cmp(point a, point b) {
	if (half(a - c) != half(b - c)) {
		return half(a - c) < half(b - c);
	}
	return vec(a - c, b - c) < 0;
}

int n;
vector<int> edge[MAXN];
vector<point> all;
vector<point> que[3];
vector<int> nq[3];

bool used[MAXN];

void dfs(int i) {
	if (used[i]) return;
	used[i] = true;
	for (auto j : edge[i]) {
		dfs(j);
	}
}

int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].x >> a[i].y >> r[i];
		for (int j = 0; j < 200; ++j) {
			int alp = j;
			point v = {sin(alp), cos(alp)};
			v.x *= r[i];
			v.y *= r[i];
			que[i].pb(a[i] + v);
		}
		for (int j = 0; j < i; ++j) {
			point v = a[i] - a[j];
			base d = dist(a[i], a[j]);
			if (d < eps) continue;
			//cout << d << endl;
			// L * L + r1 * r1 = R * R + r2 * r2
			// d * (L - R) = r2 * r2 - r1 * r1;
			double L = (d + (r[i] * r[i] - r[j] * r[j]) / d) / 2;
			//cout << fixed << dh << ' ' << i << ' ' << j << endl;
			double dh = sqrt(abs(r[i] * r[i] - L * L));
			//cout << fixed << L << ' ' << i << ' ' << j << endl;
			v.x /= d;
			v.y /= d;
			//cout << dh << endl;
			point M = a[i] - make_pair(v.x * L, v.y * L);
			swap(v.x, v.y);
			v.x = -v.x;
			//cout << v.x << ' ' << v.y << endl;
			//cout << M.x << ' ' << M.y << endl;
			point F1 = M + make_pair(v.x * dh, v.y * dh);
			point F2 = M - make_pair(v.x * dh, v.y * dh);
			if (abs(dist(F1, a[i]) - r[i]) < eps && abs(dist(F1, a[j]) - r[j]) < eps) {
				que[j].pb(F2);
				que[i].pb(F2);
				que[i].pb(F1);
				que[j].pb(F1);
			}
			//cout << i << ' ' << j << ' ' << fixed << F1.x << ' ' << F1.y << endl;

		}
	}
	int V = 0;
	int E = 0;
	int F = 0;
	int C = 0;
	for (int i = 0; i < n; ++i) {
		//cout << i << ' ' << que[i].size() << endl;
		c = a[i];
		sort(que[i].begin(), que[i].end(), cmp);

		for (auto j : que[i]) {
			all.pb(j);
			++V;
		}
				//cout << i << endl;
		set<int> used;
		for (auto j : que[i]) {
			for (int q = 0;; ++q) {
				assert(q < all.size());
				if (dist(all[q], j) < eps) {
					if (used.count(q)) break;
					//cout << q << '/' << j.x << ' ' << j.y << endl;

					used.insert(q);
					nq[i].pb(q);
					break;
				} 
			}
		}
		//cout << endl;
				//cout << i << endl;
		//cout << nq[i].size() << ' ' << que[i].size() << endl;
		nq[i].pb(nq[i][0]);
		for (int j = 0; j + 1 < nq[i].size(); ++j) {
			E += 1;
			edge[nq[i][j]].pb(nq[i][j + 1]);
			edge[nq[i][j + 1]].pb(nq[i][j]);
		}
				//cout << i << endl;

	}
	//return 0;
	for (int i = 0; i < V; ++i) {
		if (!used[i]) {
			++C;
			dfs(i);
		}
	}
	//V - E + F = 1 + C
	//F = 1 + C + E - V
	//cout << E << ' ' << V << ' ' << C << endl;
	cout << 1 + C + E - V << endl;
}