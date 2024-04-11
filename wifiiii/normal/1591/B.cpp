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
        int ans = -1, lst = -1;
        for(int i = n - 1; i >= 0; --i) {
            if(a[i] > lst) {
                lst = a[i];
                ans += 1;
            }
        }
        cout << ans << '\n';
    }
}