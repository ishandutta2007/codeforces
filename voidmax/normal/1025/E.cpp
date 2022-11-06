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
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
// #pragma GCC optimize("unroll-loops")    
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
#include <chrono>
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((string(FILENAME) + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((string(FILENAME) + ".out").c_str(), "w", stdout)
using namespace std;
        
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; } 
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
 
typedef int base;       
typedef pair<base, base> point;


int n, m;
point s[51], f[51];
vector<pair<point, point>> ans;
vector<int> que;
int id[51];
int who[51][51];

bool cmp(int i, int j) {
	return mp(-f[i].x, f[i].y) < mp(-f[j].x, f[j].y);
}

bool cmp2(int i, int j) {
	return s[i] < s[j];
}

int cnt = 1;
point p[51][51];

bool cool(point a) {
	return (a.x >= 0 && a.x < n) && (a.y >= 0 && a.y < n);
}

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

bool bfs(point a, point b) {
	int w = who[a.x][a.y];
	who[a.x][a.y] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			p[i][j].x = 1e9;
		}
	}
	p[a.x][a.y].x = -1e9;
	queue<point> que;
	que.push(a);
	while (que.size()) {
		auto u = que.front();
		que.pop();
		if (u == b) break;
		for (int t = 0; t < 4; ++t) {
			point v = {u.x + dx[t], u.y + dy[t]};
			//cout << "!" << v << endl;
			if (cool(v) && who[v.x][v.y] == 0 && p[v.x][v.y].x > n) {
				//cout << "=" << v << ' ' << b << endl;
				p[v.x][v.y] = u;
				que.push(v);
			}
		}
	}
	//cout << p[b.x][b.y] << endl;
	if (p[b.x][b.y].x > n) return false;
	vector<point> ord;
	ord.pb(b);
	s[w] = b;
	who[b.x][b.y] = w;
	while (b != a) {
		b = p[b.x][b.y];
		ord.pb(b);
	}
	reverse(ord.begin(), ord.end());
	for (int i = 0; i + 1 < ord.size(); ++i) {
		ans.pb({ord[i], ord[i + 1]});
	}
	return true;
}

bool moved[51];

vector<int> res;

void move(int i) {
	while (i < n && res[i] == 0) ++i;
	if (i == n) return;
	if (moved[res[i]]) return;
	if (f[res[i]].x <= i) {
		moved[res[i]] = true;
		bfs(s[res[i]], f[res[i]]);
	} else {
		for (int j = i; j <= f[res[i]].x; ++j) move(i);
		moved[res[i]] = true;
		bfs(s[res[i]], f[res[i]]);
	}
}


int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
   	//read("input");
	cin >> n >> m;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= m; ++i) {
		cin >> s[i];
		--s[i].x, --s[i].y;
		who[s[i].x][s[i].y] = i;
		que.pb(i);
	}	
	for (int i = 1; i <= m; ++i) {
		cin >> f[i];
		--f[i].x, --f[i].y;
	}
	sort(que.begin(), que.end(), cmp);
	int cnt = 0;
	for (auto i : que) {
		id[i] = cnt++;
	}
	sort(que.rbegin(), que.rend(), cmp2);
	for (int t = 0; t < 3; ++t) {
		for (int i : que) {
			auto u = s[i];
			if (u.x == n - 1 || who[u.x + 1][u.y]) continue;
			assert(bfs(u, {u.x + 1, u.y}));
		}
	}
	reverse(que.begin(), que.end());
	for (int i : que) {
		assert(bfs(s[i], {0, id[i]}));
	}
	vector<int> st[n];
	sort(que.begin(), que.end(), cmp);
	for (int i : que) {
		assert(bfs(s[i], {f[i].x, s[i].y}));
		st[f[i].x].pb(i);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < st[i].size(); ++j) {
			for (int q = 0; q < st[i].size(); ++q) {
				int L = -1e9, R = 1e9;
				if (q) L = s[st[i][q - 1]].y;
				if (q + 1 != st[i].size()) R = s[st[i][q + 1]].y;
				if (L < f[st[i][q]].y && f[st[i][q]].y < R) {
					assert(bfs(s[st[i][q]], f[st[i][q]]));
				}
			}
		}	
	}
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i.x.x + 1 << ' ' << i.x.y + 1 << ' ' << i.y.x + 1 << ' ' << i.y.y + 1 << '\n';
	}
}