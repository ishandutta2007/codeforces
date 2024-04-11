#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll n,k; cin >> n >> k;
        ll l1,r1,l2,r2; cin >> l1 >> r1 >> l2 >> r2;
        if (l2<l1) swap(l1,l2), swap(r1,r2);
        ll cost, most, sect;
        if (l2>r1) cost=l2-r1, most=r2-l1, sect=0;
        else if (r2>r1){ sect=r1-l2; most=r2-l1-sect; cost=0; }
        else { cost=0; most=r1-l1-(r2-l2); sect=r2-l2; }
        if (n*sect>=k){
            cout << 0 << '\n';
            continue;
        }
        k-=n*sect;
        ll tot=0, ans=LLONG_MAX;
        for (int i=1;i<=n;++i){
            if (most>=k) tot+=k+cost, k=0;
            else tot+=most+cost, k-=most;
            ans=min(ans,tot+2*k);
        }
        cout << ans << '\n';
    }
}