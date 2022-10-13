#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<int> f(5000);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            ++f[a[j] - a[i]];
        }
    }
    vector<int> suf(5001);
    for(int i = 4999; i >= 0; i--) {
        suf[i] = suf[i + 1] + f[i];
    }
    
    double ans = 0.0;
    for(int r = 1; r < 5000; r++) {
        for(int s = 1; s < 5000; s++) {
            int make = r + s + 1;
            if (make >= 5000 || suf[make] == 0) continue;
            ans += suf[make] * 2.0 / (n * (n - 1)) * f[r] * 2.0 / (n * (n - 1)) * f[s] * 2.0 / (n * (n - 1));
        }
    }
    cout << setprecision(24);
    cout << ans << "\n";
}