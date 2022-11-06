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
#define int long long
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

const int N = 3e5 + 5;

int n;
long long s;
int cnt[N];
int elem[N];

bool check(int M) {
    int h = 1, cnt = 0, cur = 1;
    while (cnt != n) {
        elem[h] = min(cur, n - cnt);
        ++h;
        cnt += min(cur, n - cnt);
        cur *= M;
    }
    long long sum = 0;
    for (int i = 1; i < h; ++i) {
        sum += 1LL * i * elem[i];
    }
    return sum <= s;
}



void build(int M) { 
    for (int i = 0; i < N; ++i) elem[i] = 0;
    int h = 1, cnt = 0, cur = 1;
    while (cnt != n) {
        elem[h] = min(cur, n - cnt);
        ++h;
        cnt += min(cur, n - cnt);
        cur *= M;
    }
    long long sum = 0;
    for (int i = 1; i < h; ++i) {
        sum += 1LL * i * elem[i];
        //cout << elem[i] << "!";
    }
    //cout << "?" << sum << endl;
    for (int a = 18; a >= 0; --a) {
        bool chg = true;
        while (chg) {
            chg = false;
            for (int i = h - 1; i >= 1; --i) {
                //cout << sum - s << endl;
                int j = min(h, i + (1 << a));
                long long me1 = (s - sum) / (j - i);
                long long me2 = 0;
                if (j - i == 1) {
                    me2 = (1LL * M * elem[i] - elem[j]) / (M + 1);
                } else {
                    me2 = min(elem[i] - (elem[i + 1] + M - 1) / M, elem[j - 1] * M - elem[j]);
                }
                long long cur = min(me1, me2);
                if (me1 < 0 || me2 < 0) exit(0);
                if (cur != 0) chg = true;
                sum += cur * (j - i);
                elem[i] -= cur;
                elem[j] += cur;
                if (elem[h]) ++h;
            }
        }
    }
    vector<pair<int, int>> cntx[h + 1];
    cntx[1].pb({1, 0});
    int id = 2;
    cout << "Yes\n";
    for (int i = 2; i <= h; ++i) {
        int it = 0;
        for (int j = 0; j < elem[i]; ++j) {
            if (cntx[i - 1][it].y == M) ++it;
            cout << cntx[i - 1][it].x << ' ';
            cntx[i].pb({id, 0});
            ++cntx[i - 1][it].y;
            ++id;
        }
    } 
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    //read("input")
    cin >> n >> s;
    if (1LL * n * (n + 1) / 2 < s || s < n + n - 1) {
        cout << "No" << endl;
        return 0;
    }
    int L = 0, R = n + 1;
    while (R - L > 1) {
        int M = (L + R) >> 1;
        if (check(M)) {
            R = M;
        } else {
            L = M;
        }
    }
    //cout << R << endl;
    build(R);
}