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
        map<int, int> mp;
        for (int i = 1; i <= N; ++i){
            int x; cin >> x;
            mp[abs(x)]++;
        }
        if (mp.count(0)) mp[0] = 1;
        int ans = 0;
        for (auto [x, c] : mp){
            ans += min(c, 2);
        }
        cout << ans << '\n';
    }
}