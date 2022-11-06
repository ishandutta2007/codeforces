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

const int N = 15;

int k;
vector<int> val[N];
long long w[N];
vector<long long> how[(1 << N) + 228];
pair<int, int> dp[(1 << N) + 228];
unordered_set<long long> used;
unordered_map<long long, int> place;
pair<int, int> ans[N];



int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> k;
    long long sum = 0;
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        val[i].resize(n);
        cin >> val[i];
        for (auto j : val[i]) {
            place[j] = i;
            sum += j;
            w[i] += j;
        }
    }
    if (sum % k != 0) {
        cout << "No\n";
        return 0;
    }
    int n = k;
    sum /= k;
    for (int i = 0; i < k; ++i) {
        for (auto j : val[i]) {
            if (used.count(j)) continue;
            vector<long long> val;
            val.push_back(j);
            while (true) {
                used.insert(val.back());
                long long delta = sum - (w[place[val.back()]] - val.back());
                if (place.count(delta) == 0) break;
                if (used.count(delta)) break;
                val.push_back(delta);
            }
            long long delta = sum - (w[place[val.back()]] - val.back());
            if (place.count(delta) == 0) continue;
            vector<long long> res;
            bool OK = false;
            for (auto q : val) {
                if (q == delta) OK = true;
                if (OK) res.push_back(q);
            }
            int mask = 0;
            for (auto q : res) {
                int id = place[q];
                if ((mask >> id) & 1) {
                    mask = -1;
                    break;
                }
                mask |= (1 << id);
            }
            if (mask == -1) continue;
            how[mask] = res;
        }
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
        int rev = ((1 << n) - 1) ^ mask;
        int cur = (1 << n) - 1;
        auto [x, y] = dp[mask];
        if ((x | y) != mask) continue;
        while (cur > 0) {
            cur &= rev;
            if (how[cur].size()) {
                dp[mask | cur] = {mask, cur};
            }
            --cur;
        }
    }
    int mm = (1 << n) - 1;
    auto [x, y] = dp[mm];
    if ((x | y) != mm) {
        cout << "No\n";
        return 0;
    }
    vector<int> masks;
    while (mm != 0) {
        masks.push_back(dp[mm].y);
        mm = dp[mm].x;
    }
    cout << "Yes\n";
    for (int cur : masks) {
        vector<long long> res = how[cur];
        res.push_back(res[0]);
        for (int i = 0; i + 1 < res.size(); ++i) {
            ans[place[res[i + 1]]] = {res[i + 1], place[res[i]] + 1};
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << '\n';
    }
}