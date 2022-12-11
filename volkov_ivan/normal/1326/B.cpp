#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7;
int a[N], b[N];

signed main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> b[i];
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        a[i] = b[i] + maxi;   
        maxi = max(maxi, a[i]);
        cout << a[i] << ' ';
    }
    cout << "\n";
    return 0;
}