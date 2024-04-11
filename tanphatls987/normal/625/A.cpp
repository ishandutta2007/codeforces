#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("625.inp","r",stdin)
#define OUTPUT freopen("625.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;

int main(){
    ll n,plas,bot,re;
    cin>>n>>plas>>bot>>re;
    if (bot-re>=plas) cout<<n/plas;
    else{
        ll ans=max((n-re)/(bot-re),0LL);
        n-=ans*(bot-re);
        cout<<ans+n/plas;
    }
}