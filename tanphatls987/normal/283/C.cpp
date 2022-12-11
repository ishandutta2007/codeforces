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
const int N=3e2+10,M=1e5+10;

int n,m,k,a[N],v[N],h[N],f[M],g[N],mark[N];
void prepare(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) scanf("%d",a+i);
    while (m--){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x]=y;
        h[y]=g[x]=1;
    }
    FOR(i,1,n) if (!h[i]){
        int x=i;
        mark[x]=1;
        while (v[x]) {
            a[v[x]]+=a[x];
            x=v[x];
            mark[x]=1;
        }
    }
    FOR(i,1,n) if (v[i]&&!mark[i]){
        printf("0");
        exit(0);
    }
}
int solve(){
    f[0]=1;
//    FOR(i,1,n) cout<<a[i]<<" \n"[i==n];
    FOR(i,1,n){
        FOR(j,a[i],k) f[j]=(f[j]+f[j-a[i]])%MOD;
        FORD(j,k,0) if (g[i]) f[j]=(j>=a[i]?f[j-a[i]]:0);
    }
    return f[k];
}
int main(){
    prepare();
    cout<<solve();
}