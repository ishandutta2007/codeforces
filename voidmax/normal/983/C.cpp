
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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")    
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
	


const string FILENAME = "input";
  
typedef pair<int, int> point;
 
int n;
int place[2001];

int bad[1000000];
int id[9][5][9][9][9][9];

vector<vector<int>> mask;

vector<int> cur;

void res(int bad) {
	::bad[mask.size()] = bad;
	if (cur.size() == 0) {
		id[bad][0][0][0][0][0] = mask.size();
	} else if (cur.size() == 1) {
		id[bad][1][cur[0]][0][0][0] = mask.size();
	} else if (cur.size() == 2) {
		id[bad][2][cur[0]][cur[1]][0][0] = mask.size();
	} else if (cur.size() == 3) {
		id[bad][3][cur[0]][cur[1]][cur[2]][0] = mask.size();
	}  else {
		id[bad][4][cur[0]][cur[1]][cur[2]][cur[3]] = mask.size();
	}
	mask.pb(cur);
	if (cur.size() == 4) {
		return;
	}
	for (int j = cur.size() ? cur.back() : 0; j < 9; ++j) {
		if (j == bad) continue;
		cur.pb(j);
		res(bad);
		cur.pop_back();
	}
}

vector<int> que;

bool cmp(int i, int j) {
	return mask[i].size() > mask[j].size();
} 

int get_id(vector<int> &cur, int bad) {
	if (cur.size() == 0) {
		return id[bad][0][0][0][0][0];
	} else if (cur.size() == 1) {
		return id[bad][1][cur[0]][0][0][0];
	} else if (cur.size() == 2) {
		return id[bad][2][cur[0]][cur[1]][0][0];
	} else if (cur.size() == 3) {
		return id[bad][3][cur[0]][cur[1]][cur[2]][0];
	}  else {
		return id[bad][4][cur[0]][cur[1]][cur[2]][cur[3]];
	}
}

int dp[100000];
int ndp[100000];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	//read(FILENAME);
	for (int i = 0; i < 9; ++i) {
		res(i);
	}
	for (int i = 0; i < mask.size(); ++i) {
		que.pb(i);
	}
	sort(que.begin(), que.end(), cmp);
	cin >> n;
	for (int j = 1; j < mask.size(); ++j) {
		dp[j] = 1e9;
	}
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		for (int j : que) {
			if (dp[j] == 1e9) continue;
			if (mask[j].size() == 4) {
				dp[j] = 1e9;
				continue;
			}
			int t = abs(bad[j] - a) + 1;
			vector<int> cur = mask[j];
			bool cool = true;
			for (int w : cur) {
				if (w == a) {
					cool = false;
					break;
				}
			}
			if (!cool) {
				dp[j] = 1e9;
				continue;
			}
			cur.insert(lower_bound(cur.begin(), cur.end(), b), b);
			// cout << bad[j] << " [" << mask[j] << "] " << dp[j] << endl;
			// cout << cur << ":" << b << endl;
			chkmin(dp[get_id(cur, a)], dp[j] + t);
			//cout << bad[get_id(cur, a)] << " {" << mask[get_id(cur, a)] << "} " << dp[get_id(cur, a)] << endl;
			dp[j] = 1e9;
		}
		// cout << endl;
		for (int j : que) {
			if (dp[j] == 1e9) continue;
			// cout << bad[j] << " (" << mask[j] << ") " << dp[j] << endl;
			vector<int> cur = mask[j];
			for (int e : cur) {
				vector<int> cp = cur;
				for (int i = 0; i < cp.size(); ++i) {
					if (cp[i] == e) {
						cp.erase(cp.begin() + i);
						--i;
					}
				}
				int t = abs(e - bad[j]) + (int)cur.size() - (int)cp.size();
				chkmin(dp[get_id(cp, e)], dp[j] + t);
			}
		} 
	}
	int ans = 1e9;
	for (int i = 0; i < mask.size(); ++i) {
		if (mask[i].size() == 0) {
			chkmin(ans, dp[i]);
		}
	}
	cout << ans << endl;
}