#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    int n, p;
    cin >> n >> p;
    cout << (2 * n + 1) + (n - 1) + min(p - 1, n - p) << '\n';
}