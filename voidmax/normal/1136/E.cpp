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

const int N = 1 << 17;

struct seg_tree {
	long long t[N * 2];
	long long mod[N * 2];

	long long chg(int i, int L, int R, int Ln, int Rn, int val) {
		if (Ln <= L && R <= Rn) {
			mod[i] += val;
			// cout << L << ' ' << R << endl;
			return t[i] + mod[i] * (R - L);
		}
		if (Rn <= L || R <= Ln) {
			return t[i] + mod[i] * (R - L);
		}
		int M = (L + R) >> 1;
		t[i] = chg(i * 2, L, M, Ln, Rn, val) + 
				chg(i * 2 + 1, M, R, Ln, Rn, val);
		return t[i] + mod[i] * (R - L);
	}

	long long get(int i, int L, int R, int Ln, int Rn, long long val = 0) {
		val += mod[i];
		if (Ln <= L && R <= Rn) {
			return t[i] + val * (R - L);
		}
		if (Rn <= L || R <= Ln) {
			return 0;
		}
		int M = (L + R) >> 1;
		return get(i * 2, L, M, Ln, Rn, val) + 
				get(i * 2 + 1, M, R, Ln, Rn, val);
	}
} box;

vector<int> a;
vector<int> k;
long long delta[N + 1];
set<int> que;

int n, m;



int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    //read("input")
    cin >> n;
    a.resize(n);
    k.resize(n - 1);
    cin >> a >> k;
    for (int i = 0; i + 1 < n; ++i) {
    	delta[i] = a[i + 1] - a[i] - k[i];
    	que.insert(i);
    	box.chg(1, 0, N, i, i + 1, a[i]);
    }
    box.chg(1, 0, N, n - 1, n, a[n - 1]);
    cin >> m;
    for (int i = 0; i < m; ++i) {
    	char c;
    	cin >> c;
    	if (c == 's') {
    		int L, R;
    		cin >> L >> R;
    		--L;
    		cout << box.get(1, 0, N, L, R) << '\n';
    	} else {
    		int id, d;
    		cin >> id >> d;
    		--id;
    		bool OK = true;
    		while (true) {
    			// cout << id << ' ' << d << ' ' << delta[id] << endl;
    			delta[id] -= d;
    			box.chg(1, 0, N, id, id + 1, d);
    			if (id && OK) {
    				delta[id - 1] += d;
    				que.insert(id - 1);
    			}
    			OK = false;
    			// cout << "?" << delta[id] << endl;
    			if (delta[id] >= 0) break;
    			d = -delta[id];
    			delta[id] = 0;
    			que.erase(id);
    			auto it = que.lower_bound(id);
    			if (it == que.end()) {
    				box.chg(1, 0, N, id + 1, N, d);
    				break;
    			} else {
    				box.chg(1, 0, N, id + 1, *it, d);
    				// cout << "???" << *it << endl;
    				id = *it;
    			}
    		}
    	}
    	// for (int i = 0; i < n; ++i) {
    	// 	cout << box.get(1, 0, N, i, i + 1) << ' ';
    	// } cout << '\n';
    }
}