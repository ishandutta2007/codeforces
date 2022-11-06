/*
 












 
 */
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
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define x first
#define y second
const string FILENAME = "input";
const int MAXN = 600001;



int next[MAXN][26];
int pr[MAXN];
int uk = 0;
int where[MAXN];
int cnt[MAXN];
int deep[MAXN];
bool term[MAXN];
char pc[MAXN];


inline void add(const string &s, int id) {
    int cur = 0;
    for (auto x: s) {
        if (next[cur][x - 'a']) {
            cur = next[cur][x - 'a'];
        } else {
            uk++;
            next[cur][x - 'a'] = uk;
            deep[uk] = deep[cur] + 1;
            pc[uk] = x;
            pr[uk] = cur;
            cur = uk;
        }
    }
    where[id] = cur;
}



int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
   // read(FILENAME);
    char c[300228];
    int ans = 0;
    vector<string> st;
    while (cin.getline(c, 300100)) {
        string s = string(c);
        int l = 0;
        ans++;
        while (l < sz(s)) {
            if (s[l] >= 'a' && s[l] <= 'z') {
                int r = l;
                while (r + 1 < sz(s) && s[r + 1] >= 'a' && s[r + 1] <= 'z') {
                    r++;
                }
                string a;
                for (int t = l; t <= r; t++) {
                    a += s[t];
                }
                st.push_back(a);
                l = r + 1;
            } else {
                ans++;
                l++;
            }
        }
    }
    for (int i = 0; i < sz(st); i++) {
        add(st[i], i);
    }
    for (int i = 0; i < sz(st); i++) {
        int s = where[i];
        vector<int> g;
        while (s != 0) {
            g.push_back(s);
          // /  cout << pc[s];
            s = pr[s];
        }
     //   cout << ' ' << st[i] << endl;
        int pos = -1;
        for (int is = 0; is < sz(g); is++) {
            if (term[g[is]]) {
                pos = is;
                break;
            }
        }
        if (pos == -1) {
            term[where[i]] = true;
            for (auto x: g) {
                cnt[x]++;
            }
            ans += sz(g);
            continue;
        }
        bool was = false;
        for (int is = sz(g) - 1; is >= pos; is--) {
            if (cnt[g[is]] == 1) {
                was = true;
                if (is == pos || sz(g) - deep[g[pos]] + sz(g) - is + 1 >= sz(g)) {
                    ans += sz(g);
                } else {
                    ans += sz(g) - deep[g[pos]] + sz(g) - is + 1;
                }
                break;
            }
        }
        if (!was) {
            ans += sz(st[i]);
        }
        if (!term[where[i]]) {
            term[where[i]] = true;
            for (auto x: g) {
                cnt[x]++;
            }
            continue;
        }
    }   
    cout << ans << '\n';
	return 0;
}