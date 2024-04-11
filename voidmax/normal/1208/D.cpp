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

const int N = 1 << 19;

struct seg_tree {
    long long t[N * 2 + 22];
    long long mod[N * 2 + 22];

    void push(int i) {
        t[i] += mod[i];
        if (i < N) {
            mod[i * 2] += mod[i];
            mod[i * 2 + 1] += mod[i];
        }
        mod[i] = 0;
    }

    void add(int i, int L, int R, int Ln, int Rn, long long d) {
        push(i);
        if (Rn <= L || R <= Ln) return;
        if (Ln <= L && R <= Rn) {
            mod[i] += d;
            push(i);
            return;
        }
        int M = (L + R) >> 1;
        add(i * 2,     L, M, Ln, Rn, d);
        add(i * 2 + 1, M, R, Ln, Rn, d);
        t[i] = min(t[i * 2], t[i * 2 + 1]);
    }

    int get() {
        int i = 1;
        while (i < N) {
            push(i);
            push(i * 2);
            push(i * 2 + 1);
            i <<= 1;
            if (t[i + 1] == 0) ++i;
        }
        return i;
    }

    void print() {
        for (int i = 0; i < N * 2; ++i) push(i);
        for (int i = 0; i < 2; ++i) cout << t[i + N] << ' '; cout << endl;
    }
} box;

int n;
int ans[N];

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n;
    box.add(1, 0, N, 0, N, 1e12);
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        a -= 1e12;
//        box.print();
//        cout << a << endl;
        box.add(1, 0, N, i, i + 1, a);
    }
//    box.print();
    for (int i = 0; i < n; ++i) {
        int j = box.get() - N;
        ans[j] = i + 1;
//        cout << j << endl;
        box.add(1, 0, N, j, j + 1, 1e12);
        box.add(1, 0, N, j + 1, N, -ans[j]);
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
    cout << '\n';
}