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

int n;
map<int, int> cntLL, cntLR;
set<pair<int, int>> gL, gR;

int find_less(set<pair<int, int>>& s, int value) {
    auto it = s.lower_bound(make_pair(value, -1));
    if (it != s.begin()) {
        return (--it)->y;
    }
    return -1;
}

bool add(set<pair<int, int>>& s, pair<int, int> value) {
    auto it = s.lower_bound(value);
    while (it != s.end()) {
        if (it->x >= value.x && it->y >= value.y) {
            s.erase(it);
            it = s.lower_bound(value);
        } else {
            break;
        }
    }
    if (it != s.begin()) {
        --it;
        if (it->x <= value.x && it->y <= value.y) {
            return false;
        }
    }
    s.insert(value);
    return true;
}

int get_ans(map<int, int>& m) {
    while (m.size() && m.begin()->y == 0) {
        m.erase(m.begin());
    }
    if (m.size()) {
        return m.begin()->x;
    }
    return 1e9;
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n;
    long long ans = 0;
    int last_value = 0;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        if (i != 0) {
            if (last_value < value) {
                int ansR = find_less(gL, -value);
                int ansL = find_less(gR, value);
                if (ansL != -1) {
                    cntLL[ansL]++;
                    add(gL, {-last_value, ansL});
                }
                gR.clear();
                cntLR.clear();
                if (ansR != -1) {
                    cntLR[ansR] += add(gR, {last_value, ansR});
                    add(gR, {last_value, ansR});
                }
            } else {
                int ansR = find_less(gL, -value);
                int ansL = find_less(gR, value);
                if (ansR != -1) {
                    cntLR[ansR] += add(gR, {last_value, ansR});
                    add(gR, {last_value, ansR});
                }
                gL.clear();
                cntLL.clear();
                if (ansL != -1) {
                    cntLL[ansL] += add(gL, {-last_value, ansL});
                }
            }
        }
        cntLL[i]++;
        add(gL, {-1e9, i});
        cntLR[i]++;
        add(gR, {-1e9, i});
        last_value = value;
        // cout << min(get_ans(cntLL), get_ans(cntLR)) << ' ' << i + 1 << '\n';
        // cout << "gL: ";
        // for (auto v : gL) cout << v << ", ";
        // cout << '\n';
        // cout << "gR: ";
        // for (auto v : gR) cout << v << ", ";
        // cout << '\n';
        ans += i + 1 - min(get_ans(cntLL), get_ans(cntLR));
    }
    cout << ans << '\n';
}