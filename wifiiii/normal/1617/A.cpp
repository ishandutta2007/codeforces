#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string s, t;
        cin >> s >> t;
        vector<int> c(26);
        for(char x : s) c[x - 'a'] += 1;
        string qwq = "abc", ans;
        do {
            string res;
            for(char x : qwq) {
                res += string(c[x - 'a'], x);
            }
            for(int i = 3; i < 26; ++i) {
                res += string(c[i], i + 'a');
            }
            vector<int> cc(4);
            cc[0] = 1;
            for(char x : res) {
                for(int i = 0; i < 3; ++i) {
                    if(x == t[i]) cc[i + 1] |= cc[i];
                }
            }
            if(!cc[3]) {
                if(ans.empty()) ans = res;
                ans = min(ans, res);
            }
        } while(next_permutation(qwq.begin(), qwq.end()));
        cout << ans << '\n';
    }
}