#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
bool chmax(T& x, T y){ return x < y ? (x = y, true) : false; }

void solve() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (auto& x : p) cin >> x;

    auto R = [&](int i){ return i + p[i]; };

    vector<int> dp(n, -1), nxt(n, -1), candidates, stk;
    candidates.push_back(-1);
    stk.push_back(0);

    vector<bool> left(n, false);

    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1], nxt[i] = i - 1;
        left[i] = true;
        if (dp[i - 1] >= i && chmax(dp[i], i + p[i])) left[i] = false;

        auto cmp = [&](int i, int x){ return i == -1 ? x >= 0 : dp[i] < x; };
        auto iter = lower_bound(all(candidates), i - p[i] - 1, cmp);
        if (iter != end(candidates)) {
            auto iterstk = lower_bound(all(stk), *iter + 1);
            int x = i - 1;
            if (iterstk != end(stk)) chmax(x, R(*iterstk));
            if (chmax(dp[i], x)) nxt[i] = *iter, left[i] = true;
        }

        if (candidates.back() == -1 || dp[i] > dp[candidates.back()]) candidates.push_back(i);
        while (not empty(stk) && R(i) >= R(stk.back())) stk.pop_back();
        stk.push_back(i);
    }

    auto iter = max_element(all(dp));
    if (*iter >= n - 1) {
        cout << "YES" << endl;
        string s(n, 'R');
        for (int i = (int)distance(begin(dp), iter); i != -1; i = nxt[i]) {
            if (left[i]) s[i] = 'L';
        }
        cout << s << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    exit(0);
}