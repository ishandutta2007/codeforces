#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Fenwick {
    vector<ll> f;

    Fenwick(int n) : f(n) { }

    void add(int i, int x) {
        for (int j = i; j < f.size(); j |= j + 1) f[j] += x;
    }

    ll sum(int i) {
        ll ans = 0;
        for (int j = i - 1; j >= 0; j = (j&(j+1))-1) ans += f[j];
        return ans;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> p(n), ord(n);
    for (int& x : p) cin >> x, --x;
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return p[i] < p[j]; });
    
    Fenwick fnw(n);
    vector<ll> a(n, 0);

    ll inv = 0;
    for (int i : ord) {
        inv += fnw.sum(i, n);
        a[i] = i - 2*fnw.sum(i,n) - 2*fnw.sum(0, i);
        fnw.add(i, 1); 
    }

    sort(a.rbegin(), a.rend());

    cout << inv;
    int t = 0;
    for (int x : a) {
        inv -= x;
        inv -= t++;
        cout << ' ' << inv;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}