#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int ans = 0, f1 = 0, f0 = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] != t[i]) {
                ans += 2;
                f1 = f0 = 0;
            } else {
                if(s[i] == '0') {
                    f0 = 1;
                    ans += 1;
                    if(f0 && f1) {
                        f0 = f1 = 0;
                        ans += 1;
                    }
                } else {
                    f1 = 1;
                    if(f0 && f1) {
                        f0 = f1 = 0;
                        ans += 1;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}