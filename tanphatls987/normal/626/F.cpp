#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("F.inp","r",stdin)
#define OUTPUT freopen("F.out","w",stdout)
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
const int N=2e2+10,M=1e3+10;

int n,m,a[N];
ll f[2][N][M];
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i);
    sort(a+1,a+n+1);
    f[0][0][0]=1;
    FOR(pha,1,n){
        int cur=pha&1,last=cur^1;
        memset(f[cur],0,sizeof(f[cur]));
        FOR(open,0,n)
            FOR(v,0,m) if (f[last][open][v]){
//                cout<<pha-1<<" "<<open<<" "<<v<<" "<<f[last][open][v]<<" \n";
                int tar=v+open*(a[pha]-a[pha-1]);
                if (tar>m) continue;
                ///isolate or do nothing
                f[cur][open][tar]=(f[cur][open][tar]+f[last][open][v]*(open+1))%MOD;
                ///open 1 more
                f[cur][open+1][tar]=(f[cur][open+1][tar]+f[last][open][v])%MOD;
                ///close 1
                if (open) f[cur][open-1][tar]=(f[cur][open-1][tar]+f[last][open][v]*open)%MOD;
            }
//        FOR(open,0,n)
//            FOR(v,0,m) if (f[cur][open][v]) printf("%d %d %d %lld\n",pha,open,v,f[cur][open][v]);
    }
    ll ans=0;
    FOR(i,0,m) ans=(ans+f[n&1][0][i])%MOD;
    cout<<ans;
}