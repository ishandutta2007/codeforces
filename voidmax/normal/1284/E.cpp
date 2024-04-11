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


point C;

point operator + (point a, point b) {
	return {a.x + b.x, a.y + b.y};
}

point operator - (point a, point b) {
	return {a.x - b.x, a.y - b.y};
}

long long operator * (point a, point b) {
	return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

bool half(const point& a) {
	if (a.x == 0) return a.y < 0;
	return a.x < 0;
}

bool cmp(const point& a, const point& b) {
	point va = a - C;
	point vb = b - C;
	bool ha = half(va);
	bool hb = half(vb);
	if (ha != hb) return ha < hb;
	return va * vb > 0;
}

int n;
vector<point> a;
vector<point> order;

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n;
    a.resize(n);
    cin >> a;
    int cnt = 0;
    long long ans = 0;
    for (auto i : a) {
    	order = a;
    	order.erase(order.begin() + cnt);
    	C = i;
    	sort(order.begin(), order.end(), cmp);
    	for (int i = 0; i < n - 1; ++i) order.pb(order[i]);
    	++cnt;
    	int R = 0;
    	long long good = 1LL * (n - 1) * (n - 2) * (n - 3) * (n - 4) / (1 * 2 * 3 * 4);
    	for (int L = 0; L < n - 1; ++L) {
    		if (R <= L) R = L + 1;
    		while (R - L < (n - 1)) {
    			point va = order[L] - i;
    			point vb = order[R] - i;
    			if (va * vb < 0) {
    				break;
    			}
    			++R;
    		}
    		--R;
    		int cnt = max(0, R - L);
    		good -= 1LL * cnt * (cnt - 1) * (cnt - 2) / (1 * 2 * 3);  		
    		if (good < 0) good = -1e9;
    	}
    	if (good < 0) good = 0;
    	ans += good;
    }
    cout << ans << '\n';
}