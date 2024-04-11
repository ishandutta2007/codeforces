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

int n;

string mask[30];
unordered_map<string, int> id[2];

string operator - (string a, string b) {
    for (int i = 0; i < a.size(); ++i) {
        a[i] -= b[i];
    }
    return a;
}

string operator ^ (string a, string b) {
    for (int i = 0; i < a.size(); ++i) {
        a[i] += b[i];
    }
    return a;
}

string operator ^= (string &a, string b) {
    return a = a ^ b;
}

string operator * (string a, int t) {
    for (int i = 0; i < a.size(); ++i) {
        a[i] *= t;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n;
    string m(n, char(1));
    for (int i = 0; i < 30; ++i) {
        mask[i] = string(n, char(0));
    }
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        for (int j = 0; j < 30; ++j) {
            if ((a >> j) & 1) {
                mask[j][i] += 1;
            }
        }
    }
    for (int i = 1 << 15; i--;) {
        string sum1(n, 0), sum2(n, 0);
        for (int j = 0; j < 15; ++j) {
            if ((i >> j) & 1) {
                sum1 ^= m - mask[j];
                sum2 ^= m - mask[j + 15];
            } else {
                sum1 ^= mask[j];
                sum2 ^= mask[j + 15];
            }
        }
        id[0][sum1] = i;
        id[1][sum2] = (i << 15);
    }
    for (int t = 0; t < 30; ++t) {
        for (auto [sum, mask] : id[0]) {
            if (id[1].count(m * t - sum)) {
//                cout << "?" << t << '\n';
                cout << mask + id[1][m * t - sum] << '\n';
                return 0;
            }
        }
    }
    cout << -1 << '\n';
}