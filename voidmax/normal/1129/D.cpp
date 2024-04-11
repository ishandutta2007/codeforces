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
const int LOG = 9;
const int S = 1 << LOG;
const int p = 998244353;

void sum(int &a, int b) {
	a = (a + b) % p;
}

int n, k;

int dp[N];

int cur_ans;
int sz[S][N];
int cnt[S];
int val[N];

void chg(int i, int v) {
	val[i] -= cnt[i >> LOG];
	sum(sz[i >> LOG][val[i]], v);
	if (val[i] + cnt[i >> LOG] <= k) {
		sum(cur_ans, v);
	}
}

void print() {
	cout << "?" << cur_ans << endl;
	for (int i = 0; i <= 4; ++i) {
		cout << val[i] + cnt[i >> LOG] << ' ' << dp[i] << endl;
	}
}

void add(int L, int R, int d) {
	// cout << L << ' ' << R << ' ' << d << '\n';
	// cout << "___" << endl;
	// print();
	// cout << "___" << endl;
	for (int i = 0; i <= (n >> LOG); ++i) {
		int Ln = i << LOG;
		int Rn = (i + 1) << LOG;
		if (L <= Ln && Rn <= R) {
			// cout << "HI"  << ' ' << L << ' ' << R << ' ' << cnt[i] << ' ' << val[0] << ' ' << endl;
			if (d == -1) {
				int id = k - cnt[i] + 1;
				if (id >= 0) sum(cur_ans, sz[i][id]);
			} else {
				int id = k - cnt[i];
				if (id >= 0) sum(cur_ans, p - sz[i][id]);
			}
			cnt[i] += d;
		} else {
			int Lm = max(L, Ln), Rm = min(R, Rn);
			for (int j = Lm; j < Rm; ++j) {
				sum(sz[i][val[j]], p - dp[j]);
				if (val[j] + cnt[i] <= k) sum(cur_ans, p - dp[j]);
				val[j] += d;
				sum(sz[i][val[j]], dp[j]);
				if (val[j] + cnt[i] <= k) sum(cur_ans, dp[j]);

			}
		}
	}
	// print(); 
}

int a[N];
int lst[N][2];

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    //read("input")
    cin >> n >> k;
    dp[0] = 1;
    chg(0, 1);
    // print();
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	if (lst[a[i]][1] != 0) {
    		add(lst[a[i]][0], lst[a[i]][1], -1);
    	}
    	add(lst[a[i]][1], i, 1);
    	lst[a[i]][0] = lst[a[i]][1];
    	lst[a[i]][1] = i;
    	dp[i] = cur_ans;
    	// cout << cur_ans << endl;
    	chg(i, cur_ans);
    	// print();
    }
    cout << dp[n] << '\n';
}