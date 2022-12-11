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
const int N=1e5+10;

int n,f[N];
vector <int> v[N];
void prepare(){
    int m,x,y;
    scanf("%d%d",&n,&m);
    while (m--){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    FOR(x,1,n)
        for(auto y:v[x]) if (y<x) f[x]=max(f[x],f[y]+1);
}
ll solve(){
    ll ans=0;
    FOR(x,1,n) ans=max(ans,1LL*(f[x]+1)*v[x].size());
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}