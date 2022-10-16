#include <bits/stdc++.h>
#include <cassert>

#define F first
#define S second

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

const int MOD =  998244353;

void check(int& x) {
    if (x >= MOD) x -= MOD;
    if (x < 0) x += MOD;
}

void solve() {
    int n; cin >> n;
    vector<int> x(n), y(n), s(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> s[i];

    vector<int> cnt(n+1);
    vector<int> ps(n);

    int ans = (x.back() + 1) % MOD;

    for (int i = n; i--; ) {
        cnt[i] = (cnt[i] + s[i]) % MOD;
        if (i != 0) cnt[i-1] = (cnt[i-1] + MOD - s[i]) % MOD;

        if (i != 0) check(cnt[i - 1] += 2 * cnt[i] % MOD);
        int j = lower_bound(x.begin(), x.end(), y[i]) - x.begin();
        if (j != 0) check(cnt[j - 1] -= cnt[i]);

        ans = (ans + (ll) cnt[i] * (x[i] - y[i])) % MOD;
    }

    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}