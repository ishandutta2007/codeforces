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

const int N = 1e3 + 1;

int n;
long long h[N];

vector<int> id;
vector<int> order;

vector<pair<int, int>> points = {{-2, 1}, {3, -1}, {-2, -1}, {1, -2}, {0, 3}, {2, 2}};

pair<int, int> ask(int a, int b, int c) {
	--a, --b, --c;
	point A = points[a];
	point B = points[b];
	point C = points[c];
	B.x -= A.x;
	B.y -= A.y;
	C.x -= A.x;
	C.y -= A.y;
	int s = B.x * C.y - C.x * B.y;
	if (s == 0) return {0, 0};
	if (s < 0) return {-s, 1};
	return {s, -1};
}

long long get_tp(int t, int a, int b, int c) {
	cout << t << ' ' << a << ' ' << c << ' ' << b << endl;
	// auto [ans1, ans2] = ask(a, b, c);
	// cout << ans1 << ' ' << ans2 << endl;
	// if (t == 1) return ans1;
	// else        return ans2;
	long long ans;
	cin >> ans;
	return ans;
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n;
   	// n = points.size();
    for (int i = 1; i <= n; ++i) id.pb(i);
    int L = 1, R = 2;
    h[L] = h[R] = 0;
    for (int i = 3; i <= n; ++i) {
    	h[i] = get_tp(1, L, R, i);
    	int t = get_tp(2, L, R, i);
    	h[i] *= t;
    }
    sort(id.begin(), id.end(), [](int i, int j) {
    	return h[i] < h[j];
    });
    for (int t = 0; t < 2; ++t) {
    	if (h[id.back()] > 0) {
    		if (get_tp(2, L, R, id.back()) == -1) swap(L, R);
    	}
  		swap(L, R);
    	for (int i = 1; i <= n; ++i) {
    		h[i] *= -1;
    	}
    	reverse(id.begin(), id.end());
    }
    for (int t = 0; t < 2; ++t) {
    	order.pb(L);
    	if (h[id.back()] > 0) {
    		int M = id.back();
    		vector<int> ans[2];
    		for (int i : id) {
    			if (i == M) {
    				ans[1].pb(i);
    				break;
    			}
    			if (h[i] > 0) {
    				if (get_tp(2, L, M, i) > 0) {
    					ans[0].pb(i);
    				} else {
    					ans[1].pb(i);
    				}
    			}
    		}
    		for (auto i : ans[0]) order.pb(i);
    		reverse(ans[1].begin(), ans[1].end());
    	    for (auto i : ans[1]) order.pb(i);
    	}
    	swap(L, R);
    	for (int i = 1; i <= n; ++i) {
    		h[i] *= -1;
    	}
    	reverse(id.begin(), id.end());
    }
    cout << 0 << ' ';
    bool OK = false;
    for (int i = 0; i < n; ++i) {
    	if (order[i] == 1) {
    		OK = true;
    	}
    	if (OK) cout << order[i] << ' ';
    }
    for (int i = 0; i < n; ++i) {
    	if (order[i] == 1) {
    		OK = false;
    	}
    	if (OK) cout << order[i] << ' ';
    }
    cout << endl;
}