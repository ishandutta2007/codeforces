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

const int inf=2e9;
const int MOD=1e9+7;
const int N=2e5+10;

int n,k,a[N];
ll f[3][N],g[N];
map <int,int> ma;
int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) f[0][i]=1;
    FOR(ph,0,1){
        ma.clear();
        memset(g,0,sizeof(g));
        int m=0;
        FOR(i,1,n) if (a[i]!=-inf){
            if (a[i]%k==0){
                int x=a[i]/k;
                f[ph+1][i]=g[ma[x]];
            }
            if (!ma[a[i]]) ma[a[i]]=++m;
            g[ma[a[i]]]+=f[ph][i];
        }
        FOR(i,1,n) if (a[i]!=-inf) a[i]=(a[i]%k)?-inf:a[i]/k;
    }
    ll ans=0;
    FOR(i,1,n) ans+=f[2][i];
    cout<<ans;
}