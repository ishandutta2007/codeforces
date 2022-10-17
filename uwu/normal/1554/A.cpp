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
        ll a; cin >> a;
        ll ans=0;
        for (int i=2;i<=n;++i){
            ll b; cin >> b;
            ans=max(ans,a * b);
            a = b;
        }
        cout << ans << '\n';
    }
}