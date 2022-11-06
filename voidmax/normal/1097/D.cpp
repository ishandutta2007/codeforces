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

const int N = 1e6 + 5;
const int p = 1e9 + 7;

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

long long n, m, t;

int sum1 = 0, sum2 = 0;

int kp[51];
int dp[51][51];
vector<long long> dev, prime;

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    //read("input")
    cin >> n >> t;
	m = n;
	for (int i = 2; 1LL * i * i <= n; ++i) {
		if (n % i == 0) {
			if (m % i == 0) {
				prime.pb(i);
				while (m % i == 0) {
					m /= i;
				}
			}
			if (1LL * i * i != n) dev.pb(n / i);
			dev.pb(i);
		}
	}
	if (n != 1) dev.pb(1);
	dev.pb(n);
	if (m != 1) prime.pb(m);
	for (int t = 0; t <= 50; ++t) {
		kp[t] = powx(t + 1, p - 2);
		dp[t][t] = 1;
	}
	for (int i = 0; i < t; ++i) {
		for (int j = 0; j <= 50; ++j) {
			for (int q = 0; q <= 50; ++q) {
				int v = mul(dp[j][q], kp[q]);
				dp[j][q] = 0;
				for (int k = 0; k <= q; ++k) {
					dp[j][k] = sum(dp[j][k], v);
				}
			}
		}
	}
	vector<int> start;
	for (auto j : prime) {
		long long k = n;
		int cnt = 0;
		while (k % j == 0) {
			++cnt;
			k /= j;
		}
		start.pb(cnt);
	}
	for (auto i : dev) {
		int cur = 1;
		int id = 0;
		for (auto j : prime) {
			long long k = i;
			int cnt = 0;
			while (k % j == 0) {
				++cnt;
				k /= j;
			}
			//cout << start[id] << ' ' << cnt << ' ' << dp[start[id]][cnt] << endl;
			cur = mul(cur, dp[start[id]][cnt]);
			++id;
		}
		// cout << cur << endl;
		sum1 = sum(sum1, mul(i % p, cur));
	}
	cout << sum1 << endl;
}