#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=101;

int r[MAXN], b[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i=1;i<=n;++i) cin >> r[i], r[i]+=r[i-1];
        int m; cin >> m;
        for (int i=1;i<=m;++i) cin >> b[i], b[i]+=b[i-1];
        int ans=0;
        for (int i=0;i<=n;++i){
            for (int j=0;j<=m;++j){
                ans=max(ans,r[i]+b[j]);
            }
        }
        cout << ans << '\n';
    }
}