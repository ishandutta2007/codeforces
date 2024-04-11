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
            int ok = 1, j;
            for(j = i + 1; j < n; ++j) {
                for(int k1 = i; k1 < j; ++k1) {
                    for(int k2 = k1 + 1; k2 < j; ++k2) {
                        if(a[k1] <= a[k2] && a[k2] <= a[j]) {
                            ok = 0;
                        } else if(a[k1] >= a[k2] && a[k2] >= a[j]) {
                            ok = 0;
                        }
                    }
                }
                if(!ok) {
                    break;
                }
            }
            ans += j - i;
        }
        cout << ans << '\n';
    }
}