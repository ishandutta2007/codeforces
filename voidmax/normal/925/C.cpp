 /*
 












 
 */
#pragma GCC optimize "-oFast"
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
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int MAXN = 100228;

int n;
long long b[MAXN];
bool del[MAXN];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   // read(FILENAME);
    cin >> n;
    long long x = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        del[i] = false;
    }
    vector<long long> order;
    for (int i = 59; i >= 0; i--) {
        vector<long long> st;
        for (int j = 0; j < n; j++) {
            if (!del[j]) {
                if (b[j] & (1LL << i)) {
                    st.pb(b[j]);
                    del[j] = true;
                }
            }
        }
        sort(all(st));
        reverse(all(st));
        vector<long long> order1;
        int cnt = 0;
        if (sz(st)) {
            order1.pb(st.back());
            st.pop_back();
            cnt ^= 1;
        }
        for (int is = 0; is < sz(order); is++) {
            order1.push_back(order[is]);
            if (order[is] & (1LL << i)) {
                cnt ^= 1;
            }
            if (sz(st)) {
                if (cnt == 0) {
                    order1.pb(st.back());
                    st.pop_back(); 
                    cnt ^= 1;
                }
            }
        }
        if (!st.empty()) {
            cout << "No\n";
            return 0;
        }
        order = order1;
    }
    assert(sz(order) == n);
    long long cur = order[0];
    for (int i = 1; i < sz(order); i++) {
        long long ncur = order[i] ^ cur;
       // cout << cur << ' ' << ncur << endl;
        if (ncur <= cur) {
            cout << "No\n";
            return 0;
        }
        cur = ncur;
    }
    cout << "Yes\n";
    for (auto x: order) {
        cout << x << '\n';
    } 
    return 0;
}