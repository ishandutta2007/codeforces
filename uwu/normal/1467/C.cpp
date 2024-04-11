#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=3e5+1;

int n[4]; ll mn[4], tot[4];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for (int i=1;i<=3;++i) cin >> n[i], mn[i]=LLONG_MAX;
    for (int j=1;j<=3;++j){
        for (int i=1;i<=n[j];++i){
            ll a; cin >> a; tot[j]+=a;
            mn[j]=min(mn[j],a);
        }
    }
    ll ans=tot[1]+tot[2]+tot[3];
    ll rem=min({tot[1],tot[2],tot[3]});
    for (int i=1;i<=3;++i){
        rem=min(rem,mn[1]+mn[2]+mn[3]-mn[i]);
    }
    cout << ans-2*rem << '\n';
}