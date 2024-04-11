#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> m >> n;
        cout << (ll)n*(n-1)/2 + (ll)m*(m+1)/2*n << endl;
    }
}