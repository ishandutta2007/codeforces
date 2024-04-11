#include <bits/stdc++.h>

using namespace std;

int f(int n) {
    vector<int> v;
    while (n > 0) {
        v.push_back(n % 10);
        n /= 10;
    }
    int ans = 1;
    for (int c : v) {
        if (c > 0) {
            ans *= c;
        }
    }
    return ans;
}

int g(int n) {
    if (n < 10) return n;
    else return g(f(n));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int N  = 1e6 + 5;
    vector<vector<int>> pref(N, vector<int>(10, 0));
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            pref[i][j] += pref[i - 1][j];
        }
        pref[i][g(i)]++;
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << pref[r][k] - pref[l - 1][k] << '\n';
    }
    return 0;
}