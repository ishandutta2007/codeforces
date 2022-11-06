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

const int N = 1e6 + 5;

int n;
vector<pair<int, int>> mem;
vector<int> cnt;
vector<int> t;


bool check(int id) {
    if (id >= n) return true;
//    cout << id << " ?? " << t[id] << endl;
    if (t[id] + 1 >= mem.size()) return true;
//    cout << id << "                 : " << cnt << endl;
    int diff = mem[t[id] + 1].second - mem[t[id]].second;
//    cout << "? " << diff << endl;
    for (int i = -2; i <= 0; ++i) {
        if (id + i < 0) continue;
        if (id + i + 3 > cnt.size()) continue;
        int res = 1;
        for (int j = 0; j < 3; ++j) {
            int q = i + j + id;
            if (t[q] < t[id]) {
                res *= cnt[q] + 1;
            } else if (t[q] > t[id]) {
                res *= cnt[q];
            }
        }
//        cout << " - " << res << ' ' << diff << endl;
        diff -= res;
    }
//    cout << diff << endl;
    return diff == 0;
}

vector<int> real_cnt;

void solve(int i) {
    if (i == -1) {
        for (int i = 0; i < 3; ++i) {
            if (!check(i)) {
//                cout << "? " << cnt << " : " << i << endl;
                return;
            }
        }
        int all = 0;
        for (int i = 0; i + 3 <= n; ++i) {
            all += cnt[i] * cnt[i + 1] * cnt[i + 2];
        }
        if (all == mem[0].second) {
            cout << "! " << cnt << endl;
#ifdef ONPC
            assert(real_cnt == cnt);
#endif
//            exit(0);
        }
        return;
    }
    if (!check(i + 3)) {
//        cout << "? " << cnt << endl;
        return;
    }
    if (cnt[i] == 0) {
        ++cnt[i];
        solve(i - 1);
        --cnt[i];
    }
    solve(i - 1);
}

pair<int, int> count(vector<int> res = {}) {
    if (res.empty()) res = real_cnt;
    pair<int, int> ans = {0, 0};
    for (int i = 0; i < n; ++i) {
        ans.first += res[i] * (res[i] - 1) * (res[i] - 2) / 6;
        if (i + 2 < n) ans.second += res[i] * res[i + 1] * res[i + 2];
    }
//    cout << real_cnt << " : " << ans << endl;
    return ans;
}



void solving() {
    vector<vector<int>> possible, bin;
    for (int a = 0; a < 5 * 5 * 5 * 5; ++a) {
        possible.push_back({});
        int cur = a;
        for (int j = 0; j < 4; ++j) {
            possible.back().push_back(cur % 5);
            cur /= 5;
        }
    }
//    cout << possible.size() << endl;
    for (int i = 0; i < possible.size(); ++i) {
        if (count(possible[i]) == mem[0]) {
            bin.push_back(possible[i]);
//            cout << possible[i] << " : " << real_cnt << endl;
        }
    }
    swap(bin, possible);
    bin.clear();
    vector<int> f;
    for (int i = 0; i < 4; ++i) {
        int mx_val[4] = {0, 0, 0, 0};
        map<pair<int, int>, int> cur[4];
        for (auto v : possible) {
            for (int j = 0; j < 4; ++j) {
                v[j]++;
                cur[j][count(v)]++;
                v[j]--;
            }
        }
        for (int j = 0; j < 4; ++j) {
            for (auto [key, val] : cur[j]) {
                chkmax(mx_val[j], val);
            }
//            cout << mx_val[j] << ' ';
        }
//        cout << " : " << possible.size() << endl;
        int id = min_element(mx_val, mx_val + 4) - mx_val;
        cout << "+ " << id + 1 << endl;
        f.push_back(id);
#ifdef ONPC
        real_cnt[id]++;
        mem[i + 1] = count();
#else
        cin >> mem[i + 1];
#endif
        sort(possible.begin(), possible.end());
        for (auto v : possible) {
            v[id]++;
            if (count(v) == mem[i + 1]) {
                bin.push_back(v);
            }
        }
        swap(bin, possible);
        bin.clear();
    }
    assert(possible.size() == 1);
#ifdef ONPC
    assert(possible[0] == real_cnt);
#endif
    for (auto id : f) --possible[0][id];
    cout << "! " << possible[0] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n;
    int tx = 1;
    while (tx--) {
#ifdef ONPC
        real_cnt.resize(n);
        for (int i = 0; i < n; ++i) {
            real_cnt[i] = rand() % 5;
        }
#endif
        mem.resize(n + 1);
#ifdef ONPC
        mem[0] = count();
#else
        cin >> mem[0];
#endif
        if (n == 4) {
            solving();
            continue;
        }
        cnt.resize(n);
        vector<int> order;
        t.resize(n);
        for (int i = 0; i < n; i += 2) {
            t[i] = order.size();
            order.push_back(i);
        }
        for (int i = 1; i < n; i += 2) {
            t[i] = order.size();
            order.push_back(i);
        }
        for (int i = 1; i <= n; ++i) {
            int id = order[i - 1] + 1;
            cout << "+ " << id << endl;
#ifdef ONPC
            real_cnt[id - 1]++;
            mem[i] = count();
#else
            cin >> mem[i];
#endif
            int v = mem[i].first - mem[i - 1].first;
            v *= 2;
//        cout << v << endl;
            for (int j = 0;; ++j) {
                if (j * (j - 1) == v) {
//                cout << "+ " << j << ' ' << j * (j - 1) << endl;
                    cnt[id - 1] = j;
                    break;
                }
            }
        }
//    int cur = 0;
//    for (int i = 0; i + 1 < n; ++i) {
//        cur += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
//    }
//    cur = mem[0].first - cur;
//    cur *= 6;
//    for (int i = 0;; ++i) {
//        if (i * (i - 1) * (i - 2) == cur) {
//            cnt.push_back(i);
//            break;
//        }
//    }
//    cout << cnt << endl;
//    cout << t << endl;
//    exit(0);
#ifdef ONPC
        for (int i = 0; i < n; ++i) {
            --real_cnt[i];
        }
#endif
        solve(n - 1);
    }
}