#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int n, a[N];
void solve() {
    long long sum = 0;
    long long xorSum = 0;
    for(int i = 1; i <= n; i++) {
        sum += a[i];
        xorSum ^= a[i];
    }
    cout << "2\n" << xorSum << " " << sum + xorSum << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        solve();
    }
}