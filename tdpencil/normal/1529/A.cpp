#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<ll> a(n);
        for(int64_t &i : a) cin >> i;

        int cnt = count(a.begin(), a.end(), *min_element(a.begin(), a.end()));

        cout << n - cnt << "\n";
    }
}