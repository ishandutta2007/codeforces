#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k; ll x;
        cin >> n >> k >> x;
        string s;
        cin >> s;
        if(k == 0) {
            for(char c : s) {
                if(c != '*') cout << c;
            }
            cout << '\n';
            continue;
        }
        --x;
        string ans;
        for(int i = s.size() - 1; i >= 0; --i) {
            if(s[i] == '*') {
                int j = i;
                while(j >= 0 && s[j] == '*') --j;
                ans += string(x % ((i - j) * k + 1), 'b');
                x /= ((i - j) * k + 1);
                i = j + 1;
            } else {
                ans += s[i];
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
}