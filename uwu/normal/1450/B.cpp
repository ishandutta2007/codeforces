#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=101;

int l[MAXN], r[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        for (int i=1;i<=n;++i){
            cin >> l[i] >> r[i];
        }
        bool can=0;
        for (int i=1;i<=n;++i){
            int cnt=0;
            for (int j=1;j<=n;++j){
                if (abs(l[j]-l[i])+abs(r[j]-r[i])<=k) cnt++;
            }
            if (cnt==n) can=1;
        }
        if (can) cout << 1 << '\n';
        else cout << -1 << '\n';
    }
}