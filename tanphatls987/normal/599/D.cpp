#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;

ll myf(ll x,ll y){
    return 3*(x+1)*y-x*x+1;
}
int main(){
    ll x;
    cin>>x;
    vector <pll> ans;
    for(ll sel=1;myf(sel,sel)<=(6*x/sel);sel++){
        if (x*6%sel) continue;
        ll rem=x*6/sel+sel*sel-1;
        if (rem%(3*(sel+1))) continue;
        ans.push_back(pll(sel,rem/(3*(sel+1))));
    }
    int n1=ans.size();
    FORD(i,n1-1,0) if (ans[i].X!=ans[i].Y) ans.push_back(pll(ans[i].Y,ans[i].X));
    cout<<ans.size()<<'\n';
    for(auto i:ans) cout<<i.X<<" "<<i.Y<<'\n';
}