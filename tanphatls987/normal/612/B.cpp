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
const int N=2e5+10;

int n,pos[N];
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n){
        int x;
        scanf("%d",&x);
        pos[x]=i;
    }
}
ll solve(){
    ll ans=0;
    FOR(i,2,n) ans+=abs(pos[i]-pos[i-1]);
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}