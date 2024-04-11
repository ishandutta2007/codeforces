#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 2e5 + 7;
pair <int, int> cnt[N];

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++)
        cnt[i] = {0, 0};
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        if (i <= l) {
            cnt[c].first++;
        } else {
            cnt[c].second++;
        }
    }
    for (int i = 1; i <= n; i++) {
        int mn = min(cnt[i].first, cnt[i].second);
        cnt[i].first -= mn;
        cnt[i].second -= mn;
    }
    if (l < r) {
        swap(l, r);
        for (int i = 1; i <= n; i++)
            swap(cnt[i].first, cnt[i].second);
    }
    int sm = 0, nech = 0, rt = 0;
    for (int i = 1; i <= n; i++) {
        rt += cnt[i].second;
        sm += cnt[i].first + cnt[i].second;
        if (cnt[i].first % 2 == 1)
            nech++;
    }

    nech = max(0, nech - rt);
    assert(nech % 2 == 0 && sm % 2 == 0);
    cout << (sm + nech) / 2 << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}