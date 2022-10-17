#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        int ans = 233;
        for(string p : {"00", "52", "57", "05"}) {
            int j = 0;
            for(int i = 0; i < s.size(); ++i) {
                if(p[j] == s[i]) ++j;
                if(j == p.size()) {
                    ans = min(ans, i - 1);
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
}