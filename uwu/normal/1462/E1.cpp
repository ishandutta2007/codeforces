#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

ll arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i=1;i<=n;++i) cin >> arr[i];
        sort(arr+1,arr+1+n); arr[0]=-0x3f3f3f3f;
        ll ans=0;
        for (int pr=n,pl=n;pr>=1;--pr){
            while (arr[pr]-arr[pl-1]<=2) pl--;
            if (pr-pl<2) continue;
            ans+=(ll)(pr-pl)*(pr-pl-1)/2;
        }
        cout << ans << '\n';
    }
}