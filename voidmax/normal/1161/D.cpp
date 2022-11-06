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

const int p = 998244353;

int n, m;
int ans = 0;
int clr[1001];
string s;

int val[2][1001];

void set_val(int t, int i, int v) {
    if (val[t][i] != -1) return;
    val[t][i] = v;
    if (s[i] != '?') {
        set_val(!t, i, (s[i] - '0') ^ v);
    }
    if (t == 0) {
        set_val(t, n - 1 - i, v);
    } else {
        set_val(t, m - 1 - (i - (n - m)) + (n - m), v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    //read("input")
    cin >> s;
    n = s.size();
    for (int i = 1; i < s.size(); ++i) {
        m = s.size() - i;
        int cur = 1;
        memset(val, -1, sizeof(val));
        for (int j = 0; j < i; ++j) {
            set_val(1, j, 0);
        }
        set_val(1, i, 1);
        // cout << "\nSTART" << endl;
        // for (int i = 0; i < n; ++i) {
        //     if (val[0][i] == -1) {
        //         cout << '#';
        //         continue;
        //     }  
        //     cout << val[0][i];
        // } cout << endl;
        // for (int i = 0; i < n; ++i) {
        //     if (val[1][i] == -1) {
        //         cout << '#';
        //         continue;
        //     }  
        //     cout << val[1][i];
        // } cout << endl;
        for (int j = i; j < s.size(); ++j) {
            if (val[1][j] == -1) {
                set_val(1, j, 0);
                cur = (cur * 2) % p;
                // cout << "1?" << j << endl;
            }
        }
        for (int j = 0; j < s.size(); ++j) {
            if (val[0][j] == -1) {
                set_val(0, j, 0);
                cur = (cur * 2) % p;
                // cout << "0?" << j << endl;
            }
        }
        bool OK = val[1][i] == 1;
        for (int j = 0; j < i; ++j) {
            if (val[1][j]) {
                OK = false;
                break;
            }
        }
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] != '?') {
                if ((s[j] - '0') != (val[0][j] ^ val[1][j])) {
                    OK = false;
                    break;
                }
            }
        }
        // if (OK) {
        //     for (int i = 0; i < n; ++i) {
        //         cout << val[0][i];
        //     } cout << endl;
        //     for (int i = 0; i < n; ++i) {
        //         cout << val[1][i];
        //     } cout << endl;
        // }
        // cout << "END" << endl;
        if (OK) ans = (cur + ans) % p;
    }
    cout << ans << '\n';
}  

//1....
//01...