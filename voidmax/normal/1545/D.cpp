#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("unroll-loops")    
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <numeric>
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

int n, k;
long long val[1001][1001];
long long sum[1001], sqr[1001];

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n >> k;
    map<long long, int> best;
    long long cool = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> val[i][j];
            sum[i] += val[i][j];
            sqr[i] += val[i][j] * val[i][j];
        }
        // cout << sum[i] << ' ' << sqr[i] << '\n';
        if (i >= 1) {
            best[sum[i] - sum[i - 1]]++;
            if (best[sum[i] - sum[i - 1]] >= 3) {
                cool = sum[i] - sum[i - 1];
            }
            // cout << "\t" << sum[i] - sum[i - 1] << ' ' << sqr[i] * 2 - sqr[i - 2] - sqr[i] << '\n';
        }
    }
    int need = -1;
    long long res = 0;
    for (int i = 1; i + 1 < k; ++i) {
        if (sum[i] - sum[i - 1] != cool && sum[i + 1] - sum[i] != cool) {
            need = i;
            res = sum[i - 1] + cool;
        }
    }
    if (need == -1) {
        if (sum[0] - sum[1] != cool) {
            need = 0;
            res = sum[1] - cool;
        } else {
            need = k - 1;
            res = sum[k - 2] + cool;
        }
    }
    long long delta = res - sum[need];
    int L = max(0, need - 5);
    int R = min(k - 1, need + 5);
    for (int i = 0; i < n; ++i) {
        sqr[need] -= val[need][i] * val[need][i];
        val[need][i] += delta;
        sqr[need] += val[need][i] * val[need][i];
        set<long long> kek;
        for (int M = L; M <= R; ++M) {
            if (M > 0 && M + 1 < k) {
                kek.insert(sqr[M] * 2 - sqr[M - 1] - sqr[M + 1]);
            }
        }
        if (kek.size() == 1) {
            cout << need << ' ' << val[need][i] << endl;
            return 0;
        }
        sqr[need] -= val[need][i] * val[need][i];
        val[need][i] -= delta;
        sqr[need] += val[need][i] * val[need][i];
    }

}