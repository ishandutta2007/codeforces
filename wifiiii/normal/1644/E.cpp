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
        string s;
        cin >> s;
        int x = 0, y = 0;
        for(char c : s) {
            if(c == 'R') ++y;
            else ++x;
        }
        int p = 0;
        while(p < s.size() && s[0] == s[p]) ++p;
        if(p == s.size()) {
            cout << n << '\n';
            continue;
        }
        ll ans = p + 1ll * (n - x) * (n - y);
        while(p < s.size()) {
            char c = s[p++];
            if(c == 'R') ans += n - x;
            else ans += n - y;
        }
        cout << ans << '\n';
    }
}