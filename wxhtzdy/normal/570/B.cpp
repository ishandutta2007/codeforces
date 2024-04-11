#include <bits/stdc++.h>

using namespace std;

int n, m;


mt19937 rng(time(0));

void Solve() {
    cin >> n >> m;
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    if (m <= n / 2) {
        cout << m + 1 << '\n';
        return;
    } else {
        cout << m - 1 << '\n';
        return;
    }
}

int Test() {
    cout << n << " " << m << '\n';
    double p = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        double tmp = 0;
        for (int j = 1; j <= n; j++) {
            if (abs(j - i) < abs(j - m)) {
                tmp++;
            }
        }
        double new_p = tmp / n;
        if (new_p > p) {
            p = new_p;
            ans = i;
        }
    }
    return ans;
}

void Run() {
    n = rng() % 200 + 10, m = rng() % n + 1;
    //int ans = Solve(), bans = Test();
    //cout << ans << " " << bans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solve();
    return 0;
}