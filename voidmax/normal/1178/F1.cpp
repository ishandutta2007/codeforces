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
const int p = 998244353;

int n, m;
int L[501], R[501];
vector<int> all[501];
int a[N];
int nxt[N];
long long dp1[501][501];
long long dp2[501][501];
long long ndp[501];
vector<pair<int, int>> ord;
vector<int> st;

int get1(int Ln, int Rn) {
	if (Ln > Rn) return 1;
	if (L[a[Ln]] == Ln && R[a[Rn]] == Rn) 
		return dp1[a[Ln]][a[Rn]];
	return 0;
}

int get2(int Ln, int Rn) {
	if (Ln > Rn) return 1;
	if (L[a[Ln]] == Ln && R[a[Rn]] == Rn) 
		return dp2[a[Ln]][a[Rn]];
	return 0;
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    	if (a[i] == a[i - 1]) {
    		--n;
    		--i;
    		continue;
    	}
    	if (L[a[i]] == 0) L[a[i]] = i;
    	R[a[i]] = i;
    	all[a[i]].pb(i);
    	ndp[a[i]] = -1;
    	while (st.size() && a[st.back()] > a[i]) {
    		nxt[st.back()] = i;
    		st.pop_back();
    	}
    	nxt[i] = n + 1;
    	st.pb(i);
    }
    for (int i = 1; i <= m; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		ord.pb({i, j});
    	}
    }
    sort(ord.begin(), ord.end(), [](point a, point b) {
    	return R[a.y] - L[a.x] < R[b.y] - L[b.x];
    });
    // cerr << "start" << endl;
    for (auto e : ord) {
    	int Ln = L[e.x];
    	int Rn = R[e.y];
    	// cerr << Ln << ' ' << Rn << endl;
    	if (Rn < Ln) continue;
    	int M = Ln;
    	while (nxt[M] <= Rn) M = nxt[M];
    	// cout << M << endl;
    	int i = a[M];
    	if (!(Ln <= L[i] && R[i] <= Rn)) continue;
    	// cout << "!" << endl;
    	if (ndp[i] == -1) {
    		ndp[i] = 1;
    		for (int j = 0; j + 1 < all[i].size(); ++j) {
    			ndp[i] = ndp[i] * get2(all[i][j] + 1, all[i][j + 1] - 1) % p;
    		}
    		// cout << i << ' ' << ndp[i] << '\n';
       	}
    	dp1[e.x][e.y] = 1LL * get2(Ln, all[i][0] - 1) * get2(all[i].back() + 1, Rn) % p;
    	dp2[e.x][e.y] = dp1[e.x][e.y] = dp1[e.x][e.y] * ndp[i] % p;
    	for (int j = 1; j <= m; ++j) {
    		if (Ln <= L[j] && R[j] < Rn) {
    			dp2[e.x][e.y] += 1LL * get1(Ln, R[j]) * get2(R[j] + 1, Rn);
    			dp2[e.x][e.y] %= p;
    		}
    	}
    	// cout << Ln << ' ' << Rn << ' ' << a[M] << ' ' << get1(Ln, Rn) << ' ' << get2(Ln, Rn)  << endl;
    }
    cout << get2(1, n) << '\n';
}