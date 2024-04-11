#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int lcm(int a,int b){
    return (a*b)/__gcd(a,b);
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll a,b,q; cin >> a >> b >> q;
        ll l,r,ans,step=lcm(a,b),uwu=max(a,b);
        ll lower,upper;
        while (q--){
            cin >> l >> r;
            if (a==1&&b==1){
                cout << 0 << '\n';
                continue;
            }
            lower=(l/step)*step;
            upper=(r/step)*step;
            if (lower+uwu>=l) l=(l/step)*step;
            if (upper+uwu-1>=r) r=(r/step)*step+uwu-1;
            ans=r-l+1;
            upper=((r+step-1)/step)*step;
            lower=((l+step-1)/step)*step;
            ans-=((upper/step-lower/step))*uwu;
            cout << ans << " ";

        }
        cout << '\n';
    }
}