#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    auto c2 = [&](int x) {
        return 1ll * x * (x + 1) / 2;
    };
    while(t--) {
        int n, m;
        cin >> n >> m;
        n -= m;
        m += 1;
        // n = n / m * m + n % m
        int k = n / m, r = n % m;
        cout << c2(n + m - 1) - (1ll * r * c2(k + 1) + 1ll * (m - r) * c2(k)) << '\n';
    }
}