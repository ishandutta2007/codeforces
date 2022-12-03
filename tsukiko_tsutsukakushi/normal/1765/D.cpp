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
    return b > a ? (a == b, true) : false;
}

template<class T> bool chmin(T &a, const T&b) {
    return b < a ? (a == b, true) : false;
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


int main() {
    int n, m;
    cin >> n >> m;

    set<pair<long long, int>> a;
    
    rep(i, n) {
        int v;
        read(v);
        a.emplace(v, i);
    }

    long long max_v = (--a.end())->first;

    a.erase(--a.end());

    long long t = max_v + 1;
    long long rest = m - max_v;

    while (a.size()) {
        // debug(t, rest);
        auto it = a.upper_bound(pair<long long, int>(rest, n));
        if (it != a.begin()) {
            --it;
            t += it->first;
            rest = m - it->first;
            a.erase(it);
        } else {
            max_v = (--a.end())->first;
            t += max_v + 1;
            rest = m - max_v;
            a.erase(--a.end());
        }
    }

    print(t);

    // map<long long, int> cnt;

    // multiset<pair<long long, int>> st;
    // rep(i, n) {
    //     ++cnt[a[i]];

    //     st.emplace(a[i], i);
    //     st.emplace(a[i], i);
    // }

    // map<pair<long long, long long>, int> used;

    // long long ans = n + accumulate(all(a), 0LL);

    // int num = 0;

    // while (st.size()) {
    //     auto it = --st.end();
    //     auto [v, i] = *it;
    //     st.erase(it);

    //     auto it2 = st.upper_bound(pair<long long, int>(m - v, 1 << 30));

    //     if (it2 == st.begin()) continue;
    //     --it2;

    //     if (it2->second == i or ++used[minmax(i, it2->second)] >= cnt[v] + cnt[it2->first]) {
    //         if (it2 == st.begin()) continue;
    //         --it2;
    //     }
    //     if (it2->second == i or ++used[minmax(i, it2->second)] >= cnt[v] + cnt[it2->first]) {
    //         if (it2 == st.begin()) continue;
    //         --it2;
    //     }

    //     int j = it2->second;

    //     st.erase(it2);
    //     ++num;
    // }

    // print(ans - num);
}