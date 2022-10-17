#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        ll ans = 1;
        for (int i = 1; i <= k; ++i){
            ans = ans * n % mod;
        }
        cout << ans << '\n';
    }
}