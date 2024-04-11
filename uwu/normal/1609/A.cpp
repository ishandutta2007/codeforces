#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 16;

ll a[MN], b[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        ll ans = 0;
        for (int idx = 1; idx <= n; ++idx){
            for (int i = 1; i <= n; ++i) b[i] = a[i];
            for (int i = 1; i <= n; ++i){
                if (i == idx) continue;
                while (b[i] % 2 == 0){
                    b[i] /= 2;
                    b[idx] *= 2;
                }
            }
            ans = max(ans, accumulate(b + 1, b + 1 + n, 0LL));
        }
        cout << ans << '\n';
    }
}