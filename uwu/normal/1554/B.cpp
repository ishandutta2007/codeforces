#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, MAXN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int l = max(n - 2 * k, 1);
        ll ans = -inf;
        for (int i = l; i <= n; ++i){
            for (int j = i + 1; j <= n; ++j){
                ans = max(ans, 1LL * i * j - 1LL * k * (a[i] | a[j]));
            }
        }
        cout << ans << '\n';
    }
}