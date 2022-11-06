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

const int N = 3e5 + 5;

int n, r;
vector<point> a;

vector<int> coor;
vector<pair<int, point>> event;

struct seg_tree {
	int mod[N * 4];
	int t[N * 4];
	
	void chg(int i, int L, int R, int Ln, int Rn, int d) {
		// vector<int> a = {i,  L, R, Ln, Rn, d}; cout << a << endl;
		// assert(L != R);
		int Lx = coor[L];
		int Rx = coor[R - 1] + 1;
		// cout << Lx << ' ' << Rx << ' ' << Ln << ' ' << Rn << endl;
		if (Rn <= Lx || Rx <= Ln) return;
		if (Ln <= Lx && Rx <= Rn) {
			mod[i] += d;
			return; 
		}
		int M = (L + R) >> 1;
		chg(i * 2, L, M, Ln, Rn, d);
		chg(i * 2 + 1, M, R, Ln, Rn, d);
		t[i] = max(t[i * 2] + mod[i * 2], t[i * 2 + 1] + mod[i * 2 + 1]);
	}
} box;

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    cin >> n >> r;
    a.resize(n);
    cin >> a;
    for (auto &i : a) {
    	i = {i.x + i.y, i.x - i.y};
    	coor.pb(i.y);
    	event.pb({i.x, i});
    	event.pb({i.x + r * 2 + 1, i});
    }
    sort(coor.begin(), coor.end());
    coor.pb(1e9);
    sort(event.begin(), event.end());
    int L = 0;
    int ans = 0;
    while (L < event.size()) {
    	int R = L;
    	while (R < event.size() && event[L].x == event[R].x) {
    		// cout << R << endl;
    		if (event[R].x == event[R].y.x) {
    			box.chg(1, 0, coor.size(), event[R].y.y, event[R].y.y + r * 2 + 1, 1);
    		} else {
    			box.chg(1, 0, coor.size(), event[R].y.y, event[R].y.y + r * 2 + 1, -1);
    		}
    		++R;
    	}
    	chkmax(ans, box.t[1] + box.mod[1]);
    	L = R;
    }
    cout << ans << '\n';
}