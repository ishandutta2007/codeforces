#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    auto match = [](string s, string t) -> int {
        assert(s.size() == t.size() && s.size() == 2);
        return (s[0] == '_' || s[0] == t[0]) && (s[1] == '_' || s[1] == t[1]);
    };
    auto solve = [&](string s) -> int {
        if(s.size() == 1) {
            if(s[0] == '_' || s[0] == '0') return 1;
            return 0;
        }
        if(s[0] == '0') return 0;
        if(s.size() == 2) {
            int ret = 0;
            ret += match(s, "25");
            ret += match(s, "50");
            ret += match(s, "75");
            return ret;
        }
        int n = s.size();
        string p2 = s.substr(s.size() - 2);
        int ret = 0;
        ret += match(p2, "00");
        ret += match(p2, "25");
        ret += match(p2, "50");
        ret += match(p2, "75");
        int cnt = 1;
        for(int i = 0; i < s.size() - 2; ++i) {
            if(s[i] == '_') {
                int tmp = 0;
                if(s[i] == '_') tmp += (!!i) + 9;
                cnt *= tmp;
            }
        }
        return ret * cnt;
    };
    if(count(s.begin(), s.end(), 'X')) {
        int ans = 0;
        for(int x = 0; x <= 9; ++x) {
            string t = s;
            for(char &c : t) if(c == 'X') c = '0' + x;
            ans += solve(t);
        }
        cout << ans << '\n';
    } else {
        cout << solve(s) << '\n';
    }
}