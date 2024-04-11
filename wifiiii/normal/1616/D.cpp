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
        int x;
        cin >> x;
        for(int i = 0; i < n; ++i) a[i] -= x;
        vector<int> b(n);
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if((i - 1 >= 0 && b[i - 1] && a[i - 1] + a[i] < 0) ||
               (i - 2 >= 0 && b[i - 1] && b[i - 2] && a[i - 2] + a[i - 1] + a[i] < 0)) {
                b[i] = 0;
            } else {
                b[i] = 1;
                ans += 1;
            }
        }
        cout << ans << '\n';
    }
}