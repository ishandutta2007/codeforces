#include <bits/stdc++.h>
//#define int long long

using namespace std;

bool is_square(int n) {
    int sq = sqrt(n);
    if (sq * sq == n)
        return 1;
    if ((sq - 1) * (sq - 1) == n)
        return 1;
    if ((sq + 1) * (sq + 1) == n)
        return 1;
    return 0;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        if (n % 2 == 0 && (is_square(n / 2))) {
            cout << "YES\n";
            continue;
        }
        if (n % 4 == 0 && (is_square(n / 4))) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}