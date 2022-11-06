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

const int N = 1.5e5+ 5;

int n, m;
long long cur = 0, mod = 0;
int it = 0;
vector<long long> dead;
long long s[N];
long long ask[N];
long long ans[N];
vector<int> order;

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    //read("input");
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> s[i];
    }
    sort(s, s + n);
    vector<pair<long long, bool>> cur_coor;
    vector<long long> cur_ans;
    for (int i = 0; i + 1 < n; ++i) {
    	cur_coor.pb({s[i + 1] - s[i], 0});

    } 
    mod = n;
    long long lst = -1;
    cin >> m;
    for (int i = 0; i < m; ++i) {
    	long long L, R;
    	cin >> L >> R;
   		ask[i] = R - L;
   		cur_coor.pb({ask[i], 1});
    }
    sort(cur_coor.begin(), cur_coor.end());
    for (auto i : cur_coor) {
    	cur += mod * (i.x - lst);
    	lst = i.x;
    	if (i.y == 0) {
    		--cur;
    		--mod;
    	} 
    	// cout << cur << ' ' << mod << ":" << i << endl;
    	cur_ans.pb(cur);
    }
    for (int  i = 0; i < m; ++i) {
    	int id = lower_bound(cur_coor.begin(), cur_coor.end(),
    		make_pair(ask[i], (bool)1)) - cur_coor.begin();
    	cout << cur_ans[id] << ' ';
    }
    cout << '\n';
}