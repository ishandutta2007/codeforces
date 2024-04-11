#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

template<typename T, typename F = function<T(const T &, const T &)>>
struct stable {
    int n;
    vector<vector<T>> st;
    F f;
    stable(const vector<T> &a, const F &f) : f(f), n(a.size()) {
        assert(n);
        int lg = 32 - __builtin_clz(n);
        st.resize(lg);
        st[0] = a;
        for(int i = 1; i < lg; ++i) {
            st[i].resize(n + 1 - (1 << i));
            for(int j = 0; j < n + 1 - (1 << i); ++j) {
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    T qry(int l, int r) {
        // 0 <= l <= r < n
        int k = 31 - __builtin_clz(r - l + 1);
        return f(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        vector<ll> sum(n + 1);
        for(int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + a[i];
        }
        stable st(sum, [&](ll i, ll j) {return min(i, j);});
        int ans = 0, l = -1, r = -1;
        for(int i = 0; i < n; ++i) {
            int lo = i - 1, hi = n - 1;
            while(lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if(st.qry(i, mid + 1) >= -s + sum[i]) lo = mid;
                else hi = mid - 1;
            }
            if(lo - i + 1 > ans) {
                ans = lo - i + 1;
                l = i;
                r = lo;
            }
        }
        if(ans == 0) cout << -1 << '\n';
        else cout << l + 1 << " " << r + 1 << '\n';
    }
}