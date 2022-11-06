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

const int N = 2e5 + 5;

int n, m;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int d[N], nxt[N ];
int a[N];
int cnt;
int used[N];
vector<pair<int, int>> cur[N];
vector<int> cool[N];
vector<int> edge[N];

int ans = 0;

int dfs(int i) {
	if (used[i] == cnt) return 0;
	used[i] = cnt;
	int max1 = 0, max2 = 0;
	for (int j : edge[i]) {
		int max3 = dfs(j);
		if (max2 < max3) {
			max2 = max3;
			if (max2 > max1) {
				swap(max2, max1);
			}
		}
	}
	chkmax(ans, max1 + max2 + 1);
	return 1 + max1;
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    //read("input")
    for (int i = 2; i < N; ++i) {
    	if (d[i]) continue;
    	d[i] = i;
    	if (1LL * i * i > N) continue;
    	for (int j = i * i; j < N; j += i) {
    		d[j] = i;
    	}
    }
    for (int i = 2; i < N; ++i) {
    	int j = i;
    	while (j % d[i] == 0) {
    		j /= d[i];
    	}
    	nxt[i] = j;
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    	int j = a[i];
    	while (j > 1) {
    		cool[d[j]].pb(i);
    		j = nxt[j];
    	}
    }
    for (int i = 1; i < n; ++i) {
    	int v1, v2;
    	cin >> v1 >> v2;
    	--v1, --v2;
    	int j = __gcd(a[v1], a[v2]);
    	while (j > 1) {
    		cur[d[j]].pb({v1, v2});
    		j = nxt[j];
    	}
    }
    for (int i = 0; i < N; ++i) {
    	if (!cool[i].size()) continue;
    	++cnt;
    	//cout << i << endl;
    	for (auto j : cur[i]) {
    		edge[j.x].pb(j.y);
    		edge[j.y].pb(j.x);
    		//cout << j << endl;
    	}
    	for (int j : cool[i]) {
    		//cout << "?" << j << endl;
    		dfs(j);
    		edge[j].clear();
    	}
    }
    cout << ans << '\n';
}