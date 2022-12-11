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

const ll inf=1e14;
const int MOD=1e9+7;
const int N=1e5+10;

int n,w[N],p[N],q[N];
ll f[N],d[N];
vector <int> v[N];
ll gcd(ll x,ll y){
    if (x==inf||y==inf) return 1;
    return __gcd(x,y);
}
ll lcm(ll x,ll y){
    if (x==inf||y==inf) return inf;
    ll tmp=x/gcd(x,y);
    if (inf/tmp<y) return inf;
    return tmp*y;
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",w+i);
    int x,y;
    FOR(i,2,n){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
}
void BFS(){
    int top=1,bot=1;
    q[1]=1;
    p[1]=-1;
    while (top<=bot){
        int x=q[top++];
        for(auto y:v[x]) if (!p[y]){
            p[y]=x;
            q[++bot]=y;
        }
    }
    FORD(i,n,1){
        int x=q[i];
        f[x]=inf;
        d[x]=1;
        int m=v[x].size();
        if (m==(p[x]!=-1)){
            f[x]=w[x];
            continue;
        }
        for(auto y:v[x]) if (y!=p[x]){
            f[x]=min(f[x],f[y]);
            d[x]=lcm(d[x],d[y]);
        }
        f[x]=(f[x]/d[x]*d[x])*(m-(p[x]!=-1));
        if (d[x]<inf) d[x]=min(d[x]*(m-(p[x]!=-1)),inf);
    }
//    printf("%d %d %lld %lld\n",par,x,f[x],d[x]);

}
int main(){
    prepare();
    BFS();
    ll ans=0;
    FOR(i,1,n) ans+=w[i];
    cout<<ans-f[1];
}