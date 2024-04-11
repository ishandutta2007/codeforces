#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

template<typename T>
struct fenwick {
    vector<T> a;
    int n;
    fenwick(int n): n(n), a(n) {}
    void add(int x, T v) {
        assert(0 <= x && x < n && v >= 0);
        for(int i = x + 1; i <= n; i += i & -i) a[i - 1] += v;
    }
    T qry(int x) {
        T ret = 0;
        for(int i = min(x + 1, n); i > 0; i -= i & -i) ret += a[i - 1];
        return ret;
    }
    int kth(T x) { // min pos s.t. [0, pos] >= x
        assert(x >= 0);
        int lg = 31 - __builtin_clz(n), pos = 0;
        for(int i = 1 << lg; i; i >>= 1) {
            if(pos + i <= n && a[pos + i - 1] < x) {
                pos += i;
                x -= a[pos - 1];
            }
        }
        return pos;
    }
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {return a[i] > a[j] || (a[i] == a[j] && i < j);});
    int q;
    cin >> q;
    vector<vector<pair<int,int>>> qs(n);
    for(int i = 0; i < q; ++i) {
        int k, p;
        cin >> k >> p;
        qs[k - 1].push_back({p, i});
    }
    vector<int> ans(q);
    fenwick<int> fen(n);
    for(int i = 0; i < n; ++i) {
        fen.add(ord[i], 1);
        for(auto [p, id] : qs[i]) {
            ans[id] = a[fen.kth(p)];
        }
    }
    for(int i = 0; i < q; ++i) cout << ans[i] << "\n";
}