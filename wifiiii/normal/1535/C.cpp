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
        int j = 0, cnt = 0, pos = -1;
        ll ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            while(j < s.size() && (s[j] == '?' || pos == -1 || pos == ((s[j] - '0') ^ (j % 2)))) {
                if(s[j] != '?') {
                    cnt += 1;
                    pos = (s[j] - '0') ^ (j % 2);
                }
                ++j;
            }
            ans += j - i;
            if(s[i] != '?' && --cnt == 0) {
                pos = -1;
            }
        }
        cout << ans << '\n';
    }
}