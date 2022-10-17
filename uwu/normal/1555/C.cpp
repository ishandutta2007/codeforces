#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, MAXN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        int tota = accumulate(a.begin(), a.end(), 0);
        int totb = 0;
        int ans = inf;
        for (int i = 1; i <= n; ++i){
            tota -= a[i];
            totb += b[i - 1];
            ans = min(ans, max(tota, totb));
        }
        cout << ans << '\n';
    }
}