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
// 0 <= x < n
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        vector<int> aa = a;
        sort(aa.begin(), aa.end());
        aa.resize(unique(aa.begin(), aa.end()) - aa.begin());
        auto f = [&](int x) {return lower_bound(aa.begin(), aa.end(), x) - aa.begin();};
        for(int &i : a) i = f(i);
        fenwick<int> fen(aa.size());
        for(int i : a) fen.add(i, 1);
        ll ans = 0;
        for(int i = n - 1; i >= 0; --i) {
            int tmp1 = fen.qry(a[i] - 1), tmp2 = fen.qry(n - 1) - fen.qry(a[i]);
            ans += min(tmp1, tmp2);
            fen.add(a[i], -1);
        }
        cout << ans << '\n';
    }
}