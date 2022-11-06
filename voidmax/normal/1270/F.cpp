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

const int N = 1 << 18;
const int B = 600;

int n;
string s;
long long ans = 0;

int cnt[N + 228];
int lst[N + 228];

vector<pair<int, int>> res;
vector<int> ones;

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> s;
    // s.resize(1e5, '1');
    // s.resize(2e5, '1');
    n = s.size();
    ones.pb(-1);
    for (int i = 0; i < n; ++i) {
    	if (s[i] == '1') {
    		ones.pb(i);
    	} 
    }
    ones.pb(n);
    for (auto& c : s) c -= '0';
    for (int i = 1; i <= B; ++i) {
    	memset(cnt, 0, sizeof(cnt));
    	int val = 0;
    	lst[0] = 0;
    	cnt[0] = 1;
    	for (char c : s) {
    		// cout << int(c) << endl;
    		if (c == 0) {
    			--val;
    		} else {
    			val += i - 1;
    		}
    		int nv = (N + val) & (N - 1);
    		if (lst[nv] != val) {
    			lst[nv] = val;
    			cnt[nv] = 0;
    		}
    		// cout << nv << endl;
    		ans += cnt[nv]++;
    	}
    }
    int lst = 0;
    int s = n / (B + 1);
    for (int L = 0; L < n; ++L) {
    	while (ones[lst] < L) ++lst;
    	for (int t = 1; t <= s; ++t) {
    		int cR = ones[lst + t - 1];
    		if (cR == n) break;
    		int can = ones[lst + t] - cR - 1;
    		int len = cR - L + 1;
    		int need = t * (B + 1);
    		// cout << len << ' ' << t << ' ' << can << ' ' << need << '\n';
    		if (len > need) need += ((len - need - 1) / t + 1) * t;
    		// cout << "???" << need << endl;
    		need -= len;
    		if (can < need) continue;
    		can -= need;
    		ans += can / t + 1;
    		// cout << can / t + 1 << endl;
    	}
    }
    cout << ans << '\n';
}