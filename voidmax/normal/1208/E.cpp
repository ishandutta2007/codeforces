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

const int N = 1e6 + 5;

const int S = 1 << 20;

struct seg_tree {
    int t[S * 2 + 22];

    void chg(int i, int d) {
        i += S;
        t[i] = d;
        while (i > 1) {
            i >>= 1;
            t[i] = max(t[i * 2 + 1], t[i * 2]);
        }
    }

    int get(int i, int L, int R, int Ln, int Rn) {
        if (Rn <= L || R <= Ln) return -2e9;
        if (Ln <= L && R <= Rn) {
            return t[i];
        }
        int M = (L + R) >> 1;
        return max(get(i * 2,     L, M, Ln, Rn),
                   get(i * 2 + 1, M, R, Ln, Rn));
    }

    void print() {
//        for (int i = 0; i < N * 2; ++i) push(i);
        for (int i = 0; i < 3; ++i) cout << t[i + S] << ' '; cout << endl;
    }
} box;

int n, w;
long long pref[N];

void add(int L, int R, int d) {
    pref[L] += d;
    pref[R + 1] -= d;
//    cout << " + " << L << ' ' << R << ' ' << d << endl;
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n >> w;
    w += 2;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        vector<int> a;
        a.resize(m);
        cin >> a;
        a.insert(a.begin(), 0);
        a.pb(0);
        for (int j = 0; j < a.size(); ++j) {
            box.chg(j, a[j]);
        }
        m += 2;
//        cout << a << endl;
        int L = 0;
        while (L < w) {
            int Ln = L - (w - m);
            int Rn = L;
            chkmax(Ln, 0);
            chkmin(Rn, m - 1);
//            cout << "? " << L << ' ' << Ln << ' ' << Rn << endl;
            if (Ln == 0 && Rn == m - 1) break;
            add(L, L, box.get(1, 0, S, Ln, Rn + 1));
            ++L;
        }

        int R = w - 1;
        while (L < R) {
            int Ln = R - (w - m);
            int Rn = R;
            chkmax(Ln, 0);
            chkmin(Rn, m - 1);
//            cout << "! " << R << ' ' << Ln << ' ' << Rn << endl;
            if (Ln == 0 && Rn == m - 1) break;
            add(R, R, box.get(1, 0, S, Ln, Rn + 1));
            --R;
        }
//        cout << L << ' ' << R << endl;
        if (L <= R) {
            add(L, R, box.get(1, 0, S, 0, m));
        }
    }
    for (int i = 1; i < w - 1; ++i) {
        pref[i] += pref[i - 1];
        cout << pref[i] << ' ';
    }
    cout << '\n';
}