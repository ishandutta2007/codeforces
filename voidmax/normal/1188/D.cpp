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

const int N = 1e5 + 5;

int n;
int dp[2][N];
vector<long long> a;

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    cin >> n;
    a.resize(n);
    cin >> a;
    sort(a.begin(), a.end());
    for (auto &i : a) {
    	i = a.back() - i;
    }	
    // cout << a << endl;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
    	dp[0][i] = 1e9;
    } 
    for (int t = 0; t < 60; ++t) {
    	long long v = (1LL << t) - 1;
    	sort(a.rbegin(), a.rend(), [v](long long i, long long j){return (i & v) < (j & v);});
    	long long cnt0 = 0, cnt1 = 0, cnt2 = 0;
    	for (auto i : a) {
    		if ((i >> t) & 1) {
    			++cnt1;
    		} else {
    			++cnt0;
    		}
    	}
    	for (int i = 0; i <= n; ++i) dp[1][i] = 1e9;
    	chkmin(dp[1][0], dp[0][0] + cnt1);
    	chkmin(dp[1][cnt1], dp[0][0] + cnt0);
    	int L = 0;
    	while (L < n) {
    		int R = L;
    		while (R < n && (a[L] & v) == (a[R] & v)) ++R;
    		for (int M = L; M < R; ++M) {
    			auto i = a[M];
    			if ((i >> t) & 1) {
    				--cnt1;
    				++cnt2;
    			} else {
    				--cnt0;
    				++cnt1;
    			}
    		}
    		// cout << R << " : " << cnt0 << ' ' << cnt1 << ' ' << cnt2 << endl;
    		chkmin(dp[1][cnt2], dp[0][R] + cnt1);
    		chkmin(dp[1][cnt2 + cnt1], dp[0][R] + cnt0 + cnt2);
    		L = R;
    	} 
    	swap(dp[0], dp[1]);
    	// cout << t << " : ";
    	// for (int i = 0; i <= n; ++i) {
    	// 	cout << dp[0][i] << ' ';
    	// }
    	// cout << endl;
    }
    cout << dp[0][0] << '\n';
}