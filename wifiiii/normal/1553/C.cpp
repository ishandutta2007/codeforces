#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        int ans = 10;
        auto calc = [](string s) {
            int l = 0, r = 0, rl = 5, rr = 5;
            for(int i = 0; i < 10; ++i) {
                if(i & 1) --rl, l += s[i] - '0';
                else --rr, r += s[i] - '0';
                if(l > r + rr || r > l + rl) return i + 1;
            }
            return 10;
        };
        {
            string t = s;
            for(int i = 0; i < 10; i += 2) if(t[i] == '?') t[i] = '1';
            for(int i = 1; i < 10; i += 2) if(t[i] == '?') t[i] = '0';
            ans = min(ans, calc(t));
        }
        {
            string t = s;
            for(int i = 0; i < 10; i += 2) if(t[i] == '?') t[i] = '0';
            for(int i = 1; i < 10; i += 2) if(t[i] == '?') t[i] = '1';
            ans = min(ans, calc(t));
        }
        cout << ans << endl;
    }
}