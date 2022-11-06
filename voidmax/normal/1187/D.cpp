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

const int N = 1 << 19;

int m, n;
vector<int> p[N + 100];
vector<int> a, b;
vector<int> d;

struct seg_tree {
	int t[N * 2 + 100];

	seg_tree() {
		for (int i = 0; i < N * 2; ++i) t[i] = 1e9;
	}

	void chg(int i, int val) {
		i += N;
		t[i] = val;
		while (i > 1) {
			i >>= 1;
			t[i] = min(t[i * 2], t[i * 2 + 1]);
		}
	}

	int get(int i, int L, int R, int Ln, int Rn) {
		if (Rn <= L || R <= Ln) return 1e9;
		if (Ln <= L && R <= Rn) {
			return t[i];
		} 
		int M = (L + R) >> 1;
		return min(get(i * 2, L, M, Ln, Rn), get(i * 2 + 1, M, R, Ln, Rn));
	}
} box;

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    cin >> m;
    while (m--) {
    	cin >> n;
    	a.resize(n);
    	b.resize(n);
    	d.resize(n);
    	cin >> a >> b;
    	for (auto i = 0; i <= n; ++i) {
    		p[i].clear();
    	}
    	for (int i = 0; i < n; ++i) {
    		p[a[i]].push_back(i);
    	}
    	for (int i = 0; i < n; ++i) {
    		reverse(p[i + 1].begin(), p[i + 1].end());
    	}
    	bool OK = true;
    	for (int i = 0; i < n; ++i) {
    		if (p[b[i]].size() == 0) {
    			OK = false;
    			break;
    		}
    		d[i] = p[b[i]].back();
    		p[b[i]].pop_back();
    	} 
    	if (!OK) {
    		cout << "NO\n";
    		continue;
    	}
    	for (int i = 0; i < n; ++i) {
    		box.chg(i, a[i]);
    	}
    	for (int i = 0; i < n; ++i) {
    		if (box.get(1, 0, N, 0, d[i] + 1) != b[i]) {
    			OK = false;
    		}
    		box.chg(d[i], 1e9);
    	}
    	if (!OK) {
    		cout << "NO\n";
    		continue;
    	}
    	cout << "YES\n";
    }
}