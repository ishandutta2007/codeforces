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

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10,M=1e5;

int fac[N],rev[N],refac[N],x,y,q,f[N];
vector <int> a[N];
int C(int x,int y){
    if (y>x) return 0;
    return ((1LL*fac[x]*refac[y])%MOD*refac[x-y])%MOD;
}
int main(){
    fac[0]=1;
    FOR(i,1,M) fac[i]=(1LL*fac[i-1]*i)%MOD;
    rev[1]=1;
    FOR(i,2,M) rev[i]=MOD-(1LL*(MOD/i)*rev[MOD%i])%MOD;
    refac[0]=1;
    FOR(i,1,M) refac[i]=(1LL*refac[i-1]*rev[i])%MOD;
    FOR(i,1,M)
        for(int j=i+i;j<=M;j+=i) a[j].push_back(i);
    scanf("%d",&q);
    while (q--){
        scanf("%d%d",&x,&y);
        f[x]=C(x-1,y-1);
        for(auto i:a[x]){
            f[i]=C(i-1,y-1);
            //printf("%d %d\n",i,f[i]);
            for(auto j:a[i]) f[i]=(f[i]+MOD-f[j])%MOD;
            f[x]=(f[x]+MOD-f[i])%MOD;
            //printf("%d %d\n",i,f[i]);
        }
        printf("%d\n",f[x]);
    }
}