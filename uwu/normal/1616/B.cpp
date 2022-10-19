#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        string s; cin >> s;
        string ans = "";
        vector<int> nxt(N);
        if (N == 1 || s[0] == s[1]){
            cout << s[0] << s[0] << '\n';
            continue;
        }
        ans = s[0];
        for (int i = 1; i < N; ++i){
            if (s[i] <= ans.back()) ans += s[i];
            else break;
        }
        cout << ans;
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
}