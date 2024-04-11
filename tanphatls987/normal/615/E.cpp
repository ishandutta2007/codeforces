#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;
const pll d[6]={pll(-1,2),pll(-2,0),pll(-1,-2),pll(1,-2),pll(2,0),pll(1,2)};

ll n;
pll operator +(pll a,pll b){
    return pll(a.X+b.X,a.Y+b.Y);
}
pll operator *(pll a,ll x){
    return pll(a.X*x,a.Y*x);
}
void solve(){
    if (n==0){
        printf("0 0");
        return;
    }
    ll spin=ll(sqrt(n/3))-2;
    while (3*(spin+1)*(spin+2)<n) spin++;
//    cout<<spin<<'\n';
    n-=3*spin*(spin+1);
    spin++;
    pll cur=pll(2*spin,0);
    FOR(pha,0,5){
        if (!n) break;
        ll v=min(n,spin);
        cur=cur+d[pha]*v;
        n-=v;
    }
    cout<<cur.X<<" "<<cur.Y;
}
int main(){
    cin>>n;
    solve();
}