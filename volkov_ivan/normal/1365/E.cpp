#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int n;
    cin >> n;
    int a[n];
    int maxi = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = j; k < n; k++) {
                maxi = max(maxi, (a[i] | a[j]) | a[k]);
            }
        }
    }
    cout << maxi << endl;
}