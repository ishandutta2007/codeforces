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
const int N=40;

ll a[N],h[N],g[N];
int n,m,x;
void consume(int i){
    int v=min(h[i],a[i]);
    g[i]+=v;
    a[i]-=v;
    h[i]-=v;
}
int main(){
    scanf("%d%d",&n,&m);
    while (n--){
        scanf("%d",&x);
        for(int i=0;x;i++,x>>=1) a[i]+=x&1;
    }
    while (m--){
        scanf("%d",&x);
        h[x]++;
    }
    FORD(i,30,0){
        consume(i);
        FORD(j,30,i+1) while (h[i]){
            if (g[j]){
                a[i]+=1LL<<(j-i);
                g[j]--;
                consume(i);
            }else break;
        }
        if (i) a[i-1]+=a[i]<<1;
        a[i]=0;
    }
    int ans=0;
    FOR(i,0,30) ans+=g[i];
    cout<<ans;
}