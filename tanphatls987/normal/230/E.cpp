#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
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
const int N=1e6+10;

int n,m,deg[N];
ll solve(){
    if (n<3) return 0;
    ll ans=1LL*n*(n-1)*(n-2)/6-1LL*m*(n-2);
    FOR(i,1,n) ans+=1LL*deg[i]*(deg[i]-1)/2;
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        int x,y;
        scanf("%d%d",&x,&y);
        deg[x]++,deg[y]++;
    }
    cout<<solve();
}