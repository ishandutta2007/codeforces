#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7, K = 20;
int sparse[K][N];
int val[N];
int arr[N];

void build(int n) {
    for (int i = 0; i < n; i++)
        sparse[0][i] = val[i];
    for (int lvl = 1; lvl < K; lvl++) {
        for (int i = 0; i + (1 << lvl) <= n; i++) {
            int j = i + (1 << (lvl - 1));
            sparse[lvl][i] = __gcd(sparse[lvl - 1][i], sparse[lvl - 1][j]);
        }
    }
}

int get(int l, int r) {
    int lvl = 63 - __builtin_clzll(r - l + 1);
    return __gcd(sparse[lvl][l], sparse[lvl][r - (1 << lvl) + 1]);
}

void solve() {
    int n;
    cin >> n;
    int maxi = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n - 1; i++)
        val[i] = abs(arr[i] - arr[i + 1]);
    build(n - 1);
    for (int i = 0; i < n - 1; i++) {
        if (val[i] == 1)
            continue;
        int l = -1, r = i, mid;
        while (r - l > 1) {
            mid = (l + r) / 2;
            if (get(mid, i) != 1)
                r = mid;
            else
                l = mid;
        }
        maxi = max(maxi, i - l);
    }
    cout << maxi + 1 << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}