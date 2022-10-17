#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=5e5+1;

ll a[MAXN], b[MAXN], arr[MAXN], cnt[62], tot;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ms(cnt,0); tot=0;
        int n; cin >> n;
        for (int i=1;i<=n;++i){
            cin >> arr[i];
            for (ll j=0;j<=61;++j) cnt[j]+=(1&(arr[i]>>j));
        }
        for (int i=1;i<=n;++i){
            a[i]=b[i]=0;
            for (ll j=0;j<=61;++j){
                ll e=(1LL<<j)%mod;
                if (1&(arr[i]>>j)){
                    a[i]+=cnt[j]*e;
                    b[i]+=n*e;
                }
                else{
                    a[i]+=0;
                    b[i]+=cnt[j]*e;
                }
                a[i]%=mod, b[i]%=mod;
            }
            tot+=a[i]*b[i]%mod; tot%=mod;
        }
        cout << tot << '\n';
    }
}