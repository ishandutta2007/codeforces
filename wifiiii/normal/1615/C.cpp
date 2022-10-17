#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        int ans = 1e9;
        if(s == t) ans = 0;
        if(count(s.begin(), s.end(), '1') == count(t.begin(), t.end(), '1')) {
            int cnt = 0;
            for(int i = 0; i < n; ++i) {
                if(s[i] == '1' && s[i] != t[i]) {
                    cnt++;
                }
            }
            ans = min(ans, cnt * 2);
        }
        if(count(s.begin(), s.end(), '1')) {
            if(count(s.begin(), s.end(), '0') + 1 == count(t.begin(), t.end(), '1')) {
                int cnt = 0, f = 0;
                for(int i = 0; i < n; ++i) {
                    if(s[i] == '1' && t[i] == '1') f = 1;
                }
                for(int i = 0; i < n; ++i) {
                    if(s[i] == '0' && s[i] == t[i]) {
                        cnt++;
                    }
                }
                if(!f) cnt++;
                ans = min(ans, cnt * 2 + 1);
            }
        }
        if(ans == 1e9) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}