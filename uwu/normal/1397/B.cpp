#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

ll arr[MAXN],ans=LLONG_MAX;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    sort(arr+1,arr+1+n);
    if (n==1){ cout << 0 << '\n'; return 0; }
    for (int i=1;;++i){
        ll val=1,cost=0;
        for (int j=1;j<=n;++j){
            cost+=abs(arr[j]-val);
            val*=i;
            if (cost>=1e14+1) break;
        }
        ans=min(ans,cost);
        if (cost>=1e14+1) break;
    }
    cout << ans << '\n';
}