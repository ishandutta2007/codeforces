#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> cnt(26 * 26);
        vector<string> a(n);
        for(int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            a[i] = s;
            cnt[(s[0] - 'a') * 26 + (s[1] - 'a')]++;
        }
        ll ans = 0;
        for(string s : a) {
            for(int j = 0; j < 26; ++j) {
                if(s[0] - 'a' == j) continue;
                ans += cnt[j * 26 + (s[1] - 'a')];
            }
            for(int j = 0; j < 26; ++j) {
                if(s[1] - 'a' == j) continue;
                ans += cnt[(s[0] - 'a') * 26 + j];
            }
        }
        cout << ans / 2 << '\n';
    }
}