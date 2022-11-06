#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n; vector<int> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];
    sort(t.begin(), t.end());
    long long s = 0; int ans = n;
    for (int i : t) {
        if (s > i) { --ans; continue; }
        s += i;
    }
    cout << ans << endl;
    return 0;
}