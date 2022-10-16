#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

int cnt[30];
vector<pi> ans;

void solve(int n, int k) {
    // cout << "solve " << n << " " << k << endl;

    if (n == 0) return;
    if (n == 1) { cnt[k]++; return; }
    if (n == 2) {
        cnt[k]++;
        cnt[k+1]++;
        return;
    }

    const int res = __lg(n-1)+1;

    if ((1 << res) == n) {
        cnt[k+res]++;
        solve(n-1, k);
        return;
    }

    int i = (1 << res) - n;
    solve(i - 1, k);

    int j = n, w = 0;
    while (i < j) {
        ans.emplace_back((i++) << k, (j--) << k);
        ++w;
    }

    if (w > 0) {
        solve(w, k+1);
        if (i == j) cnt[k+__lg(i)]++;
        cnt[res+k] += w;
    }
}

void solve() {
    int n; cin >> n;

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    if (n == 2) {
        cout << -1 << '\n';
        return;
    }

    ans.clear();
    for (int i = 0; i < 30; ++i) cnt[i] = 0;
    solve(n, 0);

    int i0 = -1;
    for (int i = 0; i < 30; ++i) {
        if (cnt[i] > 1) { i0 = i; break; }
    }
    assert(i0 >= 0);

    ans.emplace_back(1 << i0, 1 << i0);
    cnt[i0] -= 2;
    cnt[i0+1]++;

    for (int i = 0; i < 30; ++i) {
        if (cnt[i] == n - 1) {
            ans.emplace_back(0, 1 << i);
            break;
        }

        while (cnt[i]) {
            ans.emplace_back(1 << i, 0);
            ans.emplace_back(1 << i, 1 << i);
            cnt[i]--;
            cnt[i+1]++;
        }
    }

    cout << ans.size() << '\n';
    for (auto [a, b] : ans) cout << a << " " << b << '\n';


}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}