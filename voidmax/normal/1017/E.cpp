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
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
// #pragma GCC optimize("unroll-loops")    
#include <iostream>
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
#include <deque>
#include <cassert>
#include <iomanip> 
#include <chrono>
#define pb push_back
#define x first
#define y second
#define mp make_pair
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
typedef pair<base, base> point;
 
int n, m;
vector<point> a, b;



point operator - (point a, point b) {
    return {a.x - b.x, a.y - b.y};
}

long long vec(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

long long scal(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

long long dist(point a, point b = {0, 0}) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

point c;
vector<point> res;

bool cmp(point a, point b) {
    a = a - c;
    b = b - c;
    if (vec(a, b) == 0) {
        return dist(a) < dist(b);
    }
    return vec(a, b) < 0;
}

vector<point> get(vector<point> arr) {
    if (arr.size() == 0) return {};
    c = *min_element(arr.begin(), arr.end());
    arr.erase(min_element(arr.begin(), arr.end()));
    sort(arr.begin(), arr.end(), cmp);
    vector<point> ans = {c};
    for (auto C : arr) {
        //cout << "?" << arr.size() << endl;
        bool bad = false;
        while (ans.size() > 1) {
            point B = ans.back();
            point A = ans[(int)ans.size() - 2];
            if (vec(A - B, A - C) == 0) {
                ans.pop_back();
            } else if (vec(A - B, A - C) > 0) {
                ans.pop_back();
            } else {
                break;
            }
        }
        if (!bad) {
            ans.push_back(C);
        }  
    }
    while (ans.size() > 2) {
        point B = ans.back();
        point A = ans[(int)ans.size() - 2];
        if (vec(A - B, A - c) == 0) {
            if (dist(A) > dist(B)) {
                ans.pop_back();
            } else {
                swap(ans.back(), ans[(int)ans.size() - 1]);
                ans.pop_back();
            }
        } else if (vec(A - B, A - c) > 0) {
            ans.pop_back();
        } else {
            break;
        }
    }
    return ans;
}



vector<point> rotate(point A, point B) {
    double alp = atan2(vec(A, B), scal(A, B));
    long double L = sin(alp), R = cos(alp);
    pair<long double, long double> O; 
    vector<point> ans;
    for (auto i : ::a) {
        pair<long double, long double> cur = {i.x * R - i.y * L, i.x * L + i.y * R};
        if (ans.size() == 0) {
            O = {i.x - cur.x, i.y - cur.y};
            cur = i;
        } else {
            cur = {cur.x + O.x, cur.y + O.y};
        }
        ans.pb({round(cur.x), round(cur.y)});
        if (ans.size() >= 2) {
            int id = (int)ans.size() - 2;
            if (dist(a[id], a[id + 1]) != dist(ans[id], ans[id + 1])) {
                return {};
            }
        }
    }
    // cout << ans.size() << endl;
    // for (int i = 0; i < ans.size(); ++i) {
    //     cout << ans[i] << endl;
    // }
    return ans;
}

void check(vector<point> a) {
    if (a.size() != b.size()) return;
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); ++i) {
        if ((a[i] - b[i]) != (a[0] - b[0])) 
            return;
    }
    cout << "YES\n";
    exit(0);
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    //read("input");
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    cin >> a >> b;
    a = get(a);
    b = get(b);
    sort(b.begin(), b.end());
    //cout << a.size() << ' ' << b.size() << endl;
    long long d = dist(a[0], a[1]);
    long long L = 0, R = 1.1e8;
    while (L * L <= d) {
        while (L * L + R * R > d) {
            --R;
        }
        if (L * L + R * R == d) {
            check(rotate(a[1] - a[0], {L, R}));
            check(rotate(a[1] - a[0], {L, -R}));
            check(rotate(a[1] - a[0], {-L, R}));
            check(rotate(a[1] - a[0], {-L, -R}));
        }
        ++L;
    }
    cout << "NO" << endl;
}