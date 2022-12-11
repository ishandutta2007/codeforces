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
const int N=1e5;

int hl,hr,n,w[105],g[105],h[105];
char c;
ii a[105];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>hl>>hr>>n;
    FOR(i,1,n){
        cin>>w[i]>>c>>a[i].X>>a[i].Y;
        g[i]=(c=='T');
    }
    int ans=0,cr=hr;
    FOR(k,0,1){
        FOR(T,1,n){
            int cur=0;
            hr=(T%2)?cr:100-cr;
            bool ok=true;
            memset(h,0,sizeof(h));
            REP(i,0,T) if (ok){
                bool get=0;
                FOR(j,1,n) if (!h[j]&&g[j]==i%2){
                    ll L=(1LL*(hl+(T-1)*100+hr)*a[j].X+i*100+hl-1)/(hl+i*100),R=1LL*(hl+(T-1)*100+hr)*a[j].Y/(hl+i*100);
                    //printf("%d %d %lld %lld\n",k,T,L,R);
                    if (L<=100000&&R>=100000){
                        get=1;cur+=w[j];
                        h[j]=1;
                        break;
                    }
                }
                ok&=get;
            }
            if (ok) ans=max(ans,cur);
        }
        hl=100-hl;cr=100-cr;
        FOR(i,1,n) g[i]=1-g[i];
    }
    cout<<ans;
}