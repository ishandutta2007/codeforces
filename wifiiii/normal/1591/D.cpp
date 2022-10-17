#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct fenwick {
    vector<T> a;
    int n;
    fenwick(int n): n(n), a(n) {}
    void add(int x, T v) {
        assert(0 <= x && x < n);
        for(int i = x + 1; i <= n; i += i & -i) a[i - 1] += v;
    }
    T qry(int x) {
        T ret = 0;
        for(int i = min(x + 1, n); i > 0; i -= i & -i) ret += a[i - 1];
        return ret;
    }
};
template<typename T>
ll revpair(vector<T> a) {
    vector<T> b = a;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    fenwick<int> fen(b.size());
    ll ret = 0;
    for(int i = 0; i < a.size(); ++i) {
        int p = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        ret += i - fen.qry(p);
        fen.add(p, 1);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        cout << ((revpair(a) % 2 == 0 || set<int>(a.begin(), a.end()).size() != n) ? "YES" : "NO") << '\n';
    }
}