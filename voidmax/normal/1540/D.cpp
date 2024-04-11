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
const int RN = N + 228;
const int BLOCK_SIZE = 700;

int n, m;
int c[RN], need[RN];

struct block {
    int L, R;
    vector<int> order;

    void init() { 
        for (int M = L; M < R; ++M) { 
            need[M] = c[M];
            int i = 0;
            while (i < order.size()) {
                if (need[order[i]] <= need[M]) {
                    ++need[M];
                    ++i;
                } else {
                    break;
                }
            }
            order.insert(order.begin() + i, M);
        }
    }

    void chg(int id) {
        for (int i = 0; i < order.size(); ++i) { 
            if (order[i] != id) continue;
            order.erase(order.begin() + i);
            for (int q = i; q < order.size(); ++q) {
                if (order[q] > id) {
                    int pos = q;
                    need[order[pos]]--;
                    while (pos > 0 && need[order[pos - 1]] == need[order[pos]]) {
                        --need[order[pos]];
                        swap(order[pos], order[pos - 1]);
                        --pos;
                    }
                } 
            }
            need[id] = c[id];
            int j = 0;
            while (j < order.size()) {
                if (order[j] > id) {
                    ++j;
                } else if (need[order[j]] <= need[id]) {
                    ++need[id];
                    ++j;
                } else {
                    break;
                }
            }
            j = 0;
            while (j < order.size() && need[order[j]] < need[id]) {
                ++j;
            }
            order.insert(order.begin() + j, id);
            for (int q = order.size() - 1; q >= j + 1; --q) {
                if (order[q] > id) {
                    int pos = q;
                    need[order[pos]]++;
                    while (pos + 1 < order.size() && need[order[pos + 1]] == need[order[pos]]) {
                        ++need[order[pos]];
                        swap(order[pos], order[pos + 1]);
                        ++pos;
                    }
                }
            }
            break;
        }
    }

    int getk(int k) {
        int Ln = -1, Rn = order.size();
        // cout << "order: ";
        // for (int i = 0; i < order.size(); ++i) {
        //     cout << need[order[i]] << ' ';
        // }
        // cout << '\n';
        while (Rn - Ln > 1) {
            int M = (Rn + Ln) >> 1;
            if (need[order[M]] - M <= k) {
                Ln = M;
            } else {
                Rn = M;
            }
        }
        // cout << "needed: " << k << ' ' << Rn << '\n';
        return k + Rn;
    }
} box[N];

int get(int i) {
    int block = i / BLOCK_SIZE;
    int cur = need[i];
    while (block > 0) {
        --block;
        cur = box[block].getk(cur);
    }
    return cur;
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif 
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int id = n - i - 1;
        cin >> c[id];
        // c[id] = rand() % (i + 1);
        c[id] = i - c[id];
    } 
    for (int L = 0; L < n; L += BLOCK_SIZE) {
        box[L / BLOCK_SIZE].L = L;
        box[L / BLOCK_SIZE].R = min(n, L + BLOCK_SIZE);
        box[L / BLOCK_SIZE].init();
    }
    // return 0;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int t, id;
        cin >> t >> id;
        id = n - id;
        // t = 2;
        // id = rand() % n;
        if (t == 2) {
            cout << get(id) + 1 << '\n';
        } else {
            int x;
            cin >> x;
            // x = rand() % (n - id);
            c[id] = (n - id - 1) - x;
            box[id / BLOCK_SIZE].chg(id);
        }
    }
}