#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 7;
int a[N];

bool check(int n, int maxi) {
    int lst = a[n - 1] + maxi;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > lst) return 0;
        lst = min(a[i] + maxi, lst);
    }
    return 1;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < 40; i++) {
        if (check(n, (1ll << i) - 1)) {
            cout << i << "\n";
            return;
        }
    }
    exit(-1);
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}