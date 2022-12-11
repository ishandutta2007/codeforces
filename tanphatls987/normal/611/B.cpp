#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
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
    ll L,R;
    cin>>L>>R;
    int ans=0;
    FOR(pha,0,60){
        ll cur=(1LL<<(pha+1))-1;
        REP(i,0,pha){
            ll now=cur^(1LL<<i);
            if (now>=L&&now<=R) ans++;
        }
    }
    cout<<ans;
}