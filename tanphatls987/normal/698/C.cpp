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
const int N=20;

int n,n1,k;
int p[21];
double f[1<<N],a[N],ans[N];
void prepare(){
    cin>>n>>k;
    REP(i,0,n) cin>>a[i];
    REP(i,0,n) if (a[i]>0)
        p[n1++]=i;
    k=min(k,n1);
//    REP(i,0,n) printf("%.6f ",a[i]);ENDL;
}
void solve(){
    f[0]=1;
    REP(i,1,1<<n1){
        double sumpro=.0;
        for(int j=0;j<n1;j++) if (i&(1<<j)) sumpro+=a[p[j]];
        for(int j=0;j<n1;j++) if (i&(1<<j))
            f[i]+=f[i^(1<<j)]/(1-sumpro+a[p[j]])*a[p[j]];
    }
    REP(i,0,1<<n1) if (__builtin_popcount(i)==k)
        for(int j=0;j<n1;j++) if (i&(1<<j)) ans[p[j]]+=f[i];
    REP(i,0,n) printf("%.9f ",ans[i]);
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    solve();
}