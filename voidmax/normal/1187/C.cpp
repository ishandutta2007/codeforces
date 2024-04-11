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

int n, m;
vector<pair<int, int>> seg[2];
vector<int> ans;

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    cin >> n >> m;
    ans.resize(n);
    for (int i = 0; i < m; ++i) {
    	int t, L, R;
    	cin >> t >> L >> R;
    	seg[t].pb({L - 1, R - 1});
    }
    for (int t = 1; t < 2; ++t) {
    	sort(seg[t].begin(), seg[t].end());
    	vector<pair<int, int>> ns;
  		for (auto i : seg[t]) {
  			if (ns.size() == 0) {
  				ns.pb(i);
  			} else {
  				if (ns.back().y >= i.x) {
  					chkmax(ns.back().y, i.y);
  				} else {
  					ns.pb(i);
  				}
  			}
  		}
  		swap(seg[t], ns);
  		// cout << seg[t] << endl;
    }
    int min_elem = 0;
    int lst = 0;
    for (auto i : seg[1]) {
    	while (lst != i.x) {
    		ans[lst] = min_elem;
    		--min_elem;
    		++lst;
    	}
    	for (int M = i.y; M >= i.x; --M) {
    		ans[M] = min_elem;
    		--min_elem;
    		++lst;
    	}
    }
    while (lst != n) {
		ans[lst] = min_elem;
		--min_elem;
		++lst;
	}
    for (int i = 0; i < n; ++i) {
    	ans[i] += 1 - min_elem;
    }
    // cout << ans << '\n';
    for (auto i : seg[0]) {
    	vector<int> a(ans.begin() + i.x, ans.begin() + i.y + 1);
    	auto b = a;
    	sort(b.begin(), b.end());
    	// cout << "{" << a << "}" << endl;
    	if (a == b) {
    		cout << "NO\n";
    		return 0;
    	}
    }
    cout << "YES\n";
    cout << ans << '\n';
}