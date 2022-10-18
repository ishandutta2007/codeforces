#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

template <class T>
struct fenwick {
    vector<T> node;
    int n;

    fenwick(int _n)
        : n(_n) {
        node.resize(n);
    }

    void add(int x, T v) {
        while (x < n) {
            node[x] += v;
            x |= (x + 1);
        }
    }

    T get(int x) {
        T v = 0;
        while (x >= 0) {
            v += node[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }

    T get(int a, int b) {
        return get(b) - get(a - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> p(n), a(n);
    rep(i, 0, n) {
        cin >> p[i];
        p[i]--;
        a[p[i]] = i;
    }
    vector<ll> ans(n);
    fenwick<ll> ft(n + 1), cnt(n + 1);
    ll sub = 0;
    rep(i, 0, n) {
        sub += i - ft.get(a[i]);
        ans[i] = sub;
        ft.add(a[i], 1);
        cnt.add(a[i], a[i]);
        if (i == 0) continue;

        ll o = -1, m = n;
        while (m - o > 1) {
            ll q = (m + o) / 2;
            if (ft.get(q) <= (i + 1) / 2)
                o = q;
            else
                m = q;
        }
        ll l = (i + 1) / 2, r = i - (i + 1) / 2;
        ll ls = l * m - l * (l + 1) / 2 - (cnt.get(m - 1));
        ll rs = cnt.get(m + 1, n) - m * r - r * (r + 1) / 2;
        ans[i] += ls + rs;
    }
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}