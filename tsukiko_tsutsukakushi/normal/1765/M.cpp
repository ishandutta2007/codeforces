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

int main() {
    int t; read(t);
    rep(_, t) {
        ll n; read(n);
        bool ok = 0;
        for(ll i = 2; i * i <= n; ++ i) {
            if(n % i == 0) {
                ll a = n / i;
                print(a, n - a);
                ok = 1;
                break;
            }
        }
        if(!ok) {
            print(1, n - 1);
        }
    }
}