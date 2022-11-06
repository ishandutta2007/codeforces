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

const int N = 4.6e6 + 5;
const int p = 1e9 + 7;

int sum(int a, int b) {
	a += b;
	return a < p ? a : a - p;
}

int n;
set<string> cool;

int lst = 1;
bool have[5][128];

string s;

int id = 1;
int go[N][2];
int dp[N];

int it = 0;
int node[3001];
int k[3001];

int cur_ans;

void add() {
	int v = 0;
	it = 0;
	for (char c : s) {
		k[it] = c;
		node[it] = v;
		// cout << "!" << go[v][c] << ' ' << c << endl;
		if (go[v][c] == 0) {
			int j = it;
			int val = 0;
			for (int t = 1; t <= 4 && j >= 0; ++t) {
				val = (val << 1) + k[j];
				if (have[t][val]) {
					// cout << t << ' ' << val << endl;
					dp[id] = sum(dp[id], dp[node[j]]);
				}
				--j;
			}
			cur_ans = sum(cur_ans, dp[id]);
			go[v][c] = id++;
		}
		v = go[v][c];
		++it;
	}
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    //read("input")
    dp[0] = 1;
    for (int t = 1; t <= 4; ++t) {
    	for (int i = 0; i < (1 << t); ++i) {
	    	string s = "";
	    	for (int k = 0; k < t; ++k) {
	    		s += '0' + ((i >> k) & 1);
	    	}
	    	cool.insert(s);
	    }
    }
    cool.erase("1100");
    cool.erase("1010");
    cool.erase("0111");
    cool.erase("1111");
    for (auto i : cool) {
    	int v = 0;
    	string k = i;
    	reverse(k.begin(), k.end());
    	for (auto c : k) {
    		v = (v << 1) + c - '0';
    	}
    	have[k.size()][v] = true;
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	char v;
    	cin >> v;
    	s.insert(s.begin(), v - '0');
    	add();
    	cout << cur_ans << '\n';
    }
}