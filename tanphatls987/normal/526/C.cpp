#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0,LIM=1e4;

ll C,ha,hb,wa,wb;
ll solve(){
    ll ans=0;
    if (wa>=LIM){
        for(int i=0;wa*i<=C;i++) {
            ans=max(ans,ha*i+((C-wa*i)/wb)*hb);
            //cout<<i<<" "<<ans<<'\n';
        }
        return ans;
    }else if (wb>=LIM){
        for(int i=0;wb*i<=C;i++) ans=max(ans,hb*i+((C-wb*i)/wa)*ha);
        return ans;
    }else{
        if (C>1000000){
            if (ha*wb>hb*wa){
                ll use=(C-1000000)/wa;
                ans+=use*ha;
                C-=use*wa;
            }else{
                ll use=(C-1000000)/wb;
                ans+=use*hb;
                C-=use*wb;
            }
        }
        ll cur=0;
        for(int i=0;wa*i<=C;i++) cur=max(cur,ha*i+((C-wa*i)/wb)*hb);
        ans+=cur;
        return ans;
    }
}
int main(){
    cin>>C>>ha>>hb>>wa>>wb;
    cout<<solve();
}