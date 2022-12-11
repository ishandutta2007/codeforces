#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 1e5 + 7;

vector <int> prime;

bool check(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void init() {
    for (int i = 2; i <= N; i++) {
        if (check(i))
            prime.push_back(i);
    }
}

void solve() {
    int d;
    cin >> d;
    int fi = *lower_bound(prime.begin(), prime.end(), d + 1);
    int se = *lower_bound(prime.begin(), prime.end(), fi + d);
    cout << 1ll * fi * se << "\n";
}

signed main() {
    init();
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