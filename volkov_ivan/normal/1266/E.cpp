#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7;
int a[N];
int up[N];

int calc_one(int pos) {
    return max(0ll, a[pos] - up[pos]);
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        res += a[i];
    }
    memset(up, 0, sizeof(up));
    int q;
    cin >> q;
    map <pair <int, int>, int> mp;
    for (int i = 0; i < q; i++) {
        int s, t, u;
        cin >> s >> t >> u;
        pair <int, int> kek(s, t);
        if (mp.find(kek) != mp.end()) {
            res -= calc_one(mp[kek]);
            up[mp[kek]]--;
            res += calc_one(mp[kek]);
            mp.erase(kek);
        }
        if (u != 0) {
            mp[kek] = u;
            res -= calc_one(u);
            up[u]++;
            res += calc_one(u);
        }
        cout << res << "\n";
    }
}