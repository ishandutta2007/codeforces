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
        ll l,r,m; cin >> l >> r >> m;
        ll start=m-r+l, end=m+r-l,ans,a;
        for (ll i=l;i<=r;++i){
            if ((end/i)*i>=start){ ans=(end/i)*i, a=i; break; }
        }
        if (ans<=m){
            cout << a << " " << r << " " << ans+r-m << '\n';
        }
        else{
            cout << a << " " << m+r-ans << " " << r << '\n';
        }
    }
}