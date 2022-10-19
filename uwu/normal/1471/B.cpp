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
        int n, x; cin >> n >> x;
        vector<ll> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i], b[i] = a[i];
        ll ans = accumulate(a.begin(), a.end(), 0LL);
        for (int j = 1; ; ++j){
            int i = (j - 1) % n + 1;
            if (a[i] % x == 0){
                ans += b[i];
                a[i] /= x;
            }
            else{
                break;
            }
        }
        cout << ans << '\n';
    }
}