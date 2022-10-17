#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=3e5+10;

struct Bit{
    ll a[MAXN];
    void upd(int i, ll x){ for (;i<MAXN;i+=i&-i) a[i]+=x; }
    ll qry(int i){
        if (i<=0) return 0;
        ll ret=0;
        for (;i;i-=i&-i) ret+=a[i];
        return ret;
    }
    ll qry(int l, int r){
        l=min(l,MAXN-1);
        r=min(r,MAXN-1);
        return qry(r)-qry(l-1);
    }
} cnt, val, uwu;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll ans=0;
    for (int i=1;i<=n;++i){
        ll x; cin >> x;

        ll less=cnt.qry(x), more=i-1-less;
        ans+=val.qry(x); ans+=more*x; // l mod r <=x, l mod r >x 
        ans+=less*x-uwu.qry(x); // r mod l <=x
        // if (i==4) cout << ans << " ";
        // r mod l, >x
        for (ll j=1;j*x<MAXN;j++){
            ll c=cnt.qry(j*x,(j+1)*x-1);
            ll v=val.qry(j*x,(j+1)*x-1);
            ans+=v-j*c*x;
        }
        for (int i=x;i<MAXN;i+=x) uwu.upd(i,x);
        cnt.upd(x,1);
        val.upd(x,x);

        cout << ans << " ";
    }
}