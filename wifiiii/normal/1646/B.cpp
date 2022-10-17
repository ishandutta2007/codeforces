#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        ll r = a[n - 1], l = a[0] + a[1];
        int ok = r > l;
        for(int i = 2, j = n - 2; i < j; ++i, --j) {
            l += a[i];
            r += a[j];
            ok |= r > l;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}