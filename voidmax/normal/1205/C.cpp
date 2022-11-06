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
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("unroll-loops")    
#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define len(a) int(a.size())
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
        
typedef long long base; 
typedef pair<int, int> point;      
typedef complex<double> comp;

const int N = 1e6 + 5;

int n;
int clr[51][51];
bool used[51][51];

bool dfs(point a, point b, string s) {
	if (a.x > b.x || a.y > b.y) return false;
	s += '0' + clr[a.x][a.y];
	if (a == b) {
		string m = s;
		reverse(s.begin(), s.end());
		// if (m == s) {
		// 	// cout << m << ' ' << s << endl;
		// }
		return m == s;
	}
	if (dfs({a.x + 1, a.y}, b, s)) return true;
	return dfs({a.x, a.y + 1}, b, s);
}

int main() {
    // ios::sync_with_stdio(0);
    srand(time(0));
    cin >> n;
    used[1][1] = true;
    used[n][n] = true;
    clr[1][1] = 1;
    clr[n][n] = 0;
    used[1][2] = true;
    clr[1][2] = 1;
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		if (!used[i][j]) continue;
    		vector<pair<int, int>> cool;
    		cool.pb({i + 2, j});
    		cool.pb({i + 1, j + 1});
    		cool.pb({i, j + 2});
    		for (auto q : cool) {
    			if (q.x > n || q.y > n || used[q.x][q.y]) continue;
    			cout << "? " << i << ' ' << j << ' ' << q << endl;
    			int ans;
    			cin >> ans;
    			ans = !ans;
    			used[q.x][q.y] = true;
    			clr[q.x][q.y] = clr[i][j] ^ ans;
    		}
    	}
    }
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		if (used[i][j]) continue;
    		vector<pair<int, int>> cool;
    		cool.pb({i + 2, j});
    		cool.pb({i + 1, j + 1});
    		cool.pb({i, j + 2});
    		for (auto q : cool) {
    			if (q.x > n || q.y > n || !used[q.x][q.y]) continue;
    			cout << "? " << i << ' ' << j << ' ' << q << endl;
    			int ans;
    			cin >> ans;
    			ans = !ans;
    			used[i][j] = true;
    			clr[i][j] = clr[q.x][q.y] ^ ans;
    			break;
    		}
    	}
    }
    int L = 1, R = 3;
    while (clr[L][L] == clr[R][R]) {
    	L += 2;
    	R += 2;
    }
    vector<pair<point, point>> ask;
    vector<int> ans[2];
    for (int i = 0; i <= 2; ++i) {
    	for (int j = 0; j <= 2; ++j) {
    		for (int q = i; q <= 2; ++q) {
    			for (int k = j; k <= 2; ++k) {
    				if (q + k - i - j < 2) continue;
    				ask.pb({{L + i, L + j}, {L + q, L + k}});
    				for (int t = 2; t--;) {
	    				ans[t].pb(dfs(ask.back().x, ask.back().y, ""));
	    				for (int x = 0; x <= 2; ++x) {
	    					for (int y = 0; y <= 2; ++y) {
	    						if ((x + y) & 1) {
	    							clr[L + x][L + y] = !clr[L + x][L + y];
	    						}
	    					}
	    				}
	    			}
	    			if (ans[0].back() != ans[1].back()) {
	    				cout << "? " << ask.back().x << ' ' << ask.back().y << endl;
	    				int rep;
	    				cin >> rep;
	    				if (rep != ans[1].back()) {
	    					for (int i = 1; i <= n; ++i) {
	    						for (int j = 1; j <= n; ++j) {
	    							if ((i + j) & 1) {
	    								clr[i][j] = !clr[i][j];
	    							}
	    						}
	    					}
	    				}
	    				cout << "!" << endl;
					    for (int i = 1; i <= n; ++i) {
					    	string s = "";
					    	for (int j = 1; j <= n; ++j) {
					    		s += '0' + clr[i][j];
					    	}
					    	cout << s << endl;
					    }
					    return 0;
	    			}
    			}
    		}
    	}
    }
    // cout << ans[0] << endl;
    // cout << ans[1] << endl;
   	assert(false);
}