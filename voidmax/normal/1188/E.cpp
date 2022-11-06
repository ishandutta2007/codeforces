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
const int M = 2e6 + 5;
const int p = 998244353;

int sum(int a, int b) {
	a += b;
	return a < p ? a : a - p;
}

int mul(long long a, int b) {
	return a * b % p;
}

int powx(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = mul(ans, a);
		a = mul(a, a);
		b >>= 1;
	}
	return ans;
}

int n;
vector<int> a;
int f[2][M];

int cnk(int n, int k) {
	return mul(f[0][n], mul(f[1][n - k], f[1][k]));
} 

int func(int n, int k) {
	return cnk(n + k - 1, k - 1);
}

int cnt[M];

long long sumw = 0, sumw2 = 0;

int r[M];

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    cin >> n;
    a.resize(n);
    cin >> a;
    sort(a.begin(), a.end());
    f[0][0] = 1;
    for (int i = 1; i < M; ++i) {
    	f[0][i] = mul(f[0][i - 1], i); 
    }
    f[1][M - 1] = powx(f[0][M - 1], p - 2);
    for (int i = M - 1; i--;) {
    	f[1][i] = mul(f[1][i + 1], i + 1);
    }
    for (auto i : a) {
    	cnt[i]++;
    	sumw += i;
    	r[i % n]++;
    	sumw2 += i % n;
    }
    for (int i = 1; i + 1 <= n; ++i) {
    	if (a[i] < i) {
    		int ans = 1;
    		int mod = 0;
    		for (int j = 1; j < i; ++j) {
    			mod += cnt[j - 1];
    			assert(mod <= j);
    			ans = sum(ans, func(j - mod, n));
    		}
    		cout << ans << '\n';
    		return 0;
    	}
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
    	if (sumw >= sumw2 && (sumw - sumw2) % n == 0) {
    		ans = sum(ans, func((sumw - sumw2) / n, n));
		}
    	sumw2 -= n - r[i];
    	sumw2 += 1LL * (n - 1) * r[i];
    }
    cout << ans << '\n';
}