#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++ i)

#define all(c) std::begin(c), std::end(c)

#ifdef LOCAL
#define debug(...) debug_impl(#__VA_ARGS__, __VA_ARGS__)

template<class T, class ...Args> void debug_impl(string s, T&& first, Args &&..args) {
    cerr << "(" << s << ") : (" << forward<T>(first);
    ((cerr << ", " << forward<Args>(args)), ..., (cerr << ") " << "\n"));
}

#else
#define debug(...) void(0)
#endif

template<class T> bool chmax(T &a, const T&b) {
    return b > a ? (a == b, true) : false;
}

template<class T> bool chmin(T &a, const T&b) {
    return b < a ? (a == b, true) : false;
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

int main() {
    int t; read(t);
    rep(_, t) {
        int n; read(n);
        int a, b; read(a, b);
        if(a > b) print(1);
        else print((n + a - 1) / a);
    }
}