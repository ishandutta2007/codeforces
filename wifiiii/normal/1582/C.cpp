#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int p = 1;
        for(int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if(s[i] != s[j]) p = 0;
        }
        if(p == 1) {
            cout << 0 << '\n';
            continue;
        }
        int ans = 1e9;
        for(int i = 0; i < 26; ++i) {
            string t;
            for(int j = 0; j < s.size(); ++j) {
                if(s[j] - 'a' == i) continue;
                t += s[j];
            }
            int j = 0, k = t.size() - 1, ok = 1;
            while(j < k) {
                if(t[j] != t[k]) ok = 0;
                ++j, --k;
            }
            if(ok == 0) continue;
            j = 0, k = s.size() - 1;
            int tmp = 0;
            while(j < k) {
                int c1 = 0, c2 = 0, lk = k, lj = j;
                while(j <= lk && s[j] - 'a' == i) ++j, ++c1;
                while(k >= lj && s[k] - 'a' == i) --k, ++c2;
                ++j, --k;
                tmp += abs(c1 - c2);
            }
            ans = min(ans, tmp);
        }
        if(ans == 1e9) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}