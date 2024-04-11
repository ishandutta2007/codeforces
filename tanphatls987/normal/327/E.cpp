#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9+10;
const int MOD=1e9+7;
const int N=24;

int s[1<<N],f[1<<N],a[2],n,m;
int solve(){
    sort(a,a+m);
    f[0]=1;
    REP(i,1,1<<n){
        REP(j,0,n) if (i&(1<<j)) f[i]=(f[i]+f[i^(1<<j)])%MOD;
        REP(j,0,m) if (s[i]==a[j]) f[i]=0;
    }
    return f[(1<<n)-1];
}
int main(){
    cin>>n;
    REP(i,0,n) cin>>s[1<<i];
    cin>>m;
    REP(i,0,m) cin>>a[i];
    REP(i,1,1<<n) s[i]=min(s[i&-i]+s[i^(i&-i)],inf);
    cout<<solve();
}