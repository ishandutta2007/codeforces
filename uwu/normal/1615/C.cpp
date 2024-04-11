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
        string s, t; cin >> s >> t;
        s = " " + s;
        t = " " + t;
        int cnts0 = 0, cnts1 = 0, cntd0 = 0, cntd1 = 0;
        for (int i = 1; i <= N; ++i){
            if (s[i] == t[i]){
                if (s[i] == '0') cnts0++;
                else cnts1++;
            }
            else{
                if (s[i] == '0') cntd0++;
                else cntd1++;
            }
        }
        int ans = inf;
        if (cnts0 + 1 == cnts1) ans = min(ans, cnts0 + cnts1);
        if (cntd0 == cntd1) ans = min(ans, cntd0 + cntd1);
        if (ans == inf) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}