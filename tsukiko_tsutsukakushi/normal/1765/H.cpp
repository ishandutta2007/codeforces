#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++ i)

#define all(c) std::begin(c), std::end(c)

#ifdef LOCAL
#define debug(...) debug_impl(#__VA_ARGS__, __VA_ARGS__)

template<class T, class ...Args> void debug_impl(string s, T&& first, Args &&...args) {
    cerr << "(" << s << ") : (" << forward<T>(first);
    ((cerr << ", " << forward<Args>(args)), ..., (cerr << ") " << "\n"));
}

#else
#define debug(...) void(0)
#endif

template<class T> bool chmax(T &a, const T&b) {
    return b > a ? (a = b, true) : false;
}

template<class T> bool chmin(T &a, const T&b) {
    return b < a ? (a = b, true) : false;
}

template<class T> istream& operator>>(istream& in, vector<T> &v) {
    for (auto &e : v) in >> e;
    return in;
}

template<class ...Args> void read(Args &...args) {
    (cin >> ... >> args);
}

template<class T> ostream& operator<<(ostream& out, const vector<T> &v) {
    int n = v.size();
    for(int i = 0; i < n; ++ i) {
        out << v[i];
        if(i + 1 != n) out << ' ';
    }
    return out;
}

template<class Head, class ...Tails> void print(Head && h, Tails && ...tail) {
    cout << h, ((cout << ' ' << forward<Tails>(tail)), ... , (cout << '\n'));
}

template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vc<T>>;
using ll = long long;
#define eb emplace_back

int main() {
    int n, m; read(n, m);
    vc<int> p(n); read(p);
    vvc<int> a(n);
    rep(i, n) {
        -- p[i];
        a[p[i]].eb(i);
    }
    vvc<int> g(n);
    vc<int> _deg(n, 0);
    rep(i, m) {
        int a, b; read(a, b);
        -- a, -- b;
        g[b].eb(a);
        _deg[a] ++;
    }
    vc<int> ans(n, 0);
    rep(i, n) {
        debug(i);
        queue<int> que;
        int check = 0;
        vc<int> ok(n);
        vc<int> deg = _deg;
        for(int j = n - 1; j >= 0; -- j) {
            for(int x: a[j]) {
                if(deg[x] == 0) {
                    if(x != i) que.push(x);
                    else check = 1;
                } else {
                    ok[x] = 1;
                }   
            }
            if(que.empty()) {
                assert(check);
                ans[i] = j;
                break;
            }
            int y = que.front(); que.pop();
            debug(j, y);
            for(int z: g[y]) {
                -- deg[z];
                if(deg[z] == 0 and ok[z]) {
                    if(z != i) que.push(z);
                    else check = 1;
                }
            }
        }
    }
    for(auto &x: ans) ++ x;
    print(ans);
}