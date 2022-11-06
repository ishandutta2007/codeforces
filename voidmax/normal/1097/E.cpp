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
#include <bits/stdc++.h>
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
        
typedef long long base; 
typedef pair<int, int> point;      
typedef complex<double> comp;

const int N = 1e5 + 5;

int n, cnt;
vector<int> s[N];
int pr[N];
int a[N];
bool dead[N];
vector<int> ans[N];


void test() {
	cin >> n;
	cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int t = 0; t < 2; ++t) {
		while (n > 0) {
			for (int i = 0; i <= n; ++i) {
				s[i].clear();
				dead[i] = false;
			}
			int len = 1;
			s[0] = {0};
			for (int i = 1; i <= n; ++i) {
				int L = 0, R = len;
				while (R - L > 1) {
					int M = (L + R) >> 1;
					if ((a[s[M].back()] < a[i])) {
						L = M;
					} else {
						R = M;
					}
				}
				pr[i] = s[L].back();
				s[R].pb(i);
				if (len == R) len++;
			}
			if (!t) {
				int k = 0;
				while (k * (k + 1) / 2 <= n) ++k;
				if (!t && len - 1 < k) {
					break;
				}
				int it = s[len - 1].back();
				while (it != 0) {
					ans[cnt].pb(a[it]);
					dead[it] = true;
					it = pr[it];
				}
				reverse(ans[cnt].begin(), ans[cnt].end());
				++cnt;
			} else {
				for (int i = 1; i < len; ++i) {
					for (int j : s[i]) {
						ans[cnt].pb(a[j]);
						dead[j] = true;
					}
					++cnt;
				}
				break;
			}
			int it = 1;
			for (int i = 1; i <= n; ++i) {
				if (!dead[i]) {
					a[it++] = a[i];
				}
			}
			n -= ans[cnt - 1].size();
		}
	}
	cout << cnt << '\n';
	for (int i = 0; i < cnt; ++i) {
		cout << ans[i].size() << ' ' << ans[i] << '\n';
		ans[i].clear();
	}
}


int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    //read("input")
    int t;
    cin >> t;
    while (t--) {
    	test();
    }
}