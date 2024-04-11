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
        int ans = 2e9;
        for(int c1 = 0; c1 <= 3; ++c1) {
            for(int c2 = 0; c2 <= 3; ++c2) {
                int c3 = max(0, (a.back() - c1 * 1 - c2 * 2 + 2) / 3), ok = 1;
                for(int i = 0; i < n; ++i) {
                    int okk = 0;
                    for(int j = 0; j <= c1; ++j) {
                        for(int k = 0; k <= c2; ++k) {
                            if(j * 1 + k * 2 <= a[i] && (a[i] - j * 1 - k * 2) % 3 == 0
                            && (a[i] - j * 1 - k * 2) / 3 <= c3) {
                                okk = 1;
                            }
                        }
                    }
                    if(okk == 0) {
                        ok = 0;
                        break;
                    }
                }
                if(ok) {
                    ans = min(ans, c1 + c2 + c3);
                }
            }
        }
        cout << ans << '\n';
    }
}