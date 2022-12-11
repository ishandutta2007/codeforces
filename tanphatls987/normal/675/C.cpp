#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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

int n,f[N][2],a[N],t[N];
ll psum[N];
map <ll,int> ma;
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) a[i+n]=a[i];
    ma[0]=0;
    FOR(i,1,n) {
        psum[i]=psum[i-1]+a[i];
        if (ma.find(psum[i])==ma.end()) t[i]=-1;
        else t[i]=ma[psum[i]];
        ma[psum[i]]=i;
    }
}
int solve(){
    f[0][1]=-inf;
    FOR(i,1,n){
        if (t[i]==-1) {
            f[i][1]=0;
            f[i][0]=-inf;
        }else {
            f[i][1]=f[t[i]][1]+1;
            f[i][0]=f[t[i]][0]+1;
        }
    }
//    FOR(i,1,n) cout<<f[i][0]<<" "<<f[i][1]<<'\n';
    int ans=f[n][0];
    FOR(i,1,n) ans=max(ans,f[i][1]+1);
    return n-ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}