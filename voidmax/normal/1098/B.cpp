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

const int N = 1.5e5 + 5;

int n, m;
int cur_ans = 1e9;
string a[N], b[N], c[N];

pair<int, string> dp[N][2];
int way[N][2];

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    //read("input")
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
        c[i] = a[i];
    }
    vector<char> cur = {'A', 'G', 'C', 'T'};
    sort(cur.begin(), cur.end());
    do {
        //case1 
        int sum = 0;
        int who = 0;
        for (int i = 0; i < n; i += 1, who ^= 2) {
            int cnt1 = 0, cnt2 = 0;
            string s1, s2;
            for (int j = 0; j < m; ++j, who ^= 1) {
                if (a[i][j] != cur[who]) {
                    ++cnt1;
                }
                s1 += cur[who];
            }
            who ^= (m & 1) ^ 1;
            for (int j = 0; j < m; ++j, who ^= 1) {
                if (a[i][j] != cur[who]) {
                    ++cnt2;
                }
                s2 += cur[who];
            }
            if (cnt1 < cnt2) {
                swap(s1, s2);
            }
            for (int j = 0; j < m; ++j) {
                b[i][j] = s2[j];
            }
            sum += min(cnt1, cnt2);
        }
        if (sum < cur_ans) {
            for (int i = 0; i < n; ++i) {
                c[i] = b[i];
            }
            cur_ans = sum;
        }
        //case2
        sum = 0;
        who = 0;
        for (int i = 0; i < m; i += 1, who ^= 2) {
            int cnt1 = 0, cnt2 = 0;
            string s1, s2;
            for (int j = 0; j < n; ++j, who ^= 1) {
                if (a[j][i] != cur[who]) {
                    ++cnt1;
                }
                s1 += cur[who];
            }
            who ^= (n & 1) ^ 1;
            for (int j = 0; j < n; ++j, who ^= 1) {
                if (a[j][i] != cur[who]) {
                    ++cnt2;
                }
                s2 += cur[who];
            }
            if (cnt1 < cnt2) {
                swap(s1, s2);
            }
            for (int j = 0; j < n; ++j) {
                b[j][i] = s2[j];
            }
            sum += min(cnt1, cnt2);
        }
        if (sum < cur_ans) {
            for (int i = 0; i < n; ++i) {
                c[i] = b[i];
            }
            cur_ans = sum;
        }
    } while (next_permutation(cur.begin(), cur.end()));
    for (int i = 0; i < n; ++i) {
        cout << c[i] << '\n';
    }
}