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
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int z = 0;
            for(int j = i; j < n; ++j) {
                if(a[j] == 0) z += 1;
                ans += j - i + 1 + z;
            }
        }
        cout << ans << '\n';
    }
}