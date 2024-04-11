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
        int ans = 1;
        for(int i = 0; i < n; ++i) {
            if(a[i] == 1) {
                ans += 1;
                if(i > 0 && a[i - 1] == 1) ans += 4;
            }
            if(i && a[i] == 0 && a[i - 1] == 0) {
                ans = -1;
                break;
            }
        }
        cout << ans << '\n';
    }
}