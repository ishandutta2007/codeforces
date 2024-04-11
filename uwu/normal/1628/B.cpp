#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;
string s[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        for (int i = 1; i <= N; ++i) cin >> s[i];
        bool ans = 0;
        for (int i = 1; i <= N; ++i){
            if (s[i].size() == 1) ans = 1;
            if (s[i].size() == 2 && s[i][0] == s[i][1]) ans = 1;
            if (s[i].size() == 3 && s[i][0] == s[i][2]) ans = 1;
        }
        set<string> seen;
        for (int i = 1; i <= N; ++i){
            string t = s[i];
            reverse(t.begin(), t.end());
            if (seen.count(t)) ans = 1;
            if (s[i].size() == 3 && seen.count(t.substr(0, 2))){
                ans = 1;
            }
            for (char c = 'a'; c <= 'z'; ++c){
                if (s[i].size() == 2 && seen.count(t + c)){
                    ans = 1;
                }
            }
            seen.insert(s[i]);
        }
        cout << (ans ? "YES" : "NO") << '\n';
    }
}