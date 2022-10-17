#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 301;

int a[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        for (int i = 1; i <= m; ++i) cin >> a[i];
        ll ans = 0;
        for (int i = 1; i <= m; ++i){
            for (int j = i + 1; j <= m; ++j){
                if (a[i] < a[j]) ans++;
            }
        }
        cout << ans << '\n';
    }
}