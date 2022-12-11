#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

const ll inf=1e12+10;
const int MOD=1e9+7;
const int N=2e5+10;

int en,cap,n,m,last[3];
ll f[N][3],cfu[N][3],tf[3],tcfu[3],sub[3];
ii a[N];
pll ans[N];
vector <ii> v[N];
bool operator <(pll a,pll b){
    return (a.X==b.X)?a.Y<b.Y:a.X<b.X;
}
void prepare(){
    scanf("%d%d%d%d",&en,&cap,&n,&m);
    FOR(i,1,n){
        scanf("%d%d",&a[i].Y,&a[i].X);
        a[i].Y--;
        if (a[i].X>en) i--,n--;
    }
    sort(a+1,a+n+1);
    if (a[n].Y!=en) a[++n]=ii(en,2);
    FOR(i,1,m){
        int x;
        scanf("%d",&x);
        int L=1,R=n;
        while (L<=R){
            int mid=(L+R)/2;
            if (x<=a[mid].X) R=mid-1;
            else L=mid+1;
        }
//        printf("%d %d\n",x,L);
        v[L].push_back(ii(x,i));
    }
//    FOR(i,1,n) printf("%d %d %d\n",i,a[i].X,a[i].Y);
}

void optimize(int x,int tar){
//    printf("%d %d\n",x,tar);
    ll dist=a[tar].X-a[x].X;
    if (dist>cap) return;
    FOR(i,0,2) tf[i]=f[tar][i],tcfu[i]=cfu[tar][i];
    memset(sub,0,sizeof(sub));
    REP(i,0,a[x].Y) {
        sub[i]=min(cfu[tar][i],cap-dist);
        tf[i]-=sub[i];
        dist+=sub[i];
    }
    memset(tcfu,0,sizeof(tcfu));
    tcfu[a[x].Y]=dist;
    tf[a[x].Y]+=dist;
    FOR(i,0,1){
        ll v=min(cfu[tar][i]-sub[i],cap-dist);
        tcfu[i]+=v;
        dist+=v;
    }
//    FOR(i,0,2) printf("%lld ",tf[i]);ENDL;
//    FOR(i,0,2) printf("%lld ",tcfu[i]);ENDL;
    if (pll(tf[0],tf[1])<pll(f[x][0],f[x][1])){
        FOR(i,0,2) cfu[x][i]=tcfu[i],f[x][i]=tf[i];
    }
}
void solve(){
    FOR(i,0,2) last[i]=n;
    FORD(i,n,1){
        if (i!=n){
            f[i][0]=f[i][1]=inf;
            FOR(type,0,2) optimize(i,last[type]);
            last[a[i].Y]=i;
        }
//        printf("%d %lld %lld\n",a[i].X,f[i][0],f[i][1]);
        for(auto j:v[i]){
            a[0]=ii(j.X,2);
            f[0][0]=f[0][1]=inf;
            FOR(type,0,2) optimize(0,last[type]);
            if (f[0][0]==inf) ans[j.Y]=pll(-1,-1);
            else ans[j.Y]=pll(f[0][0],f[0][1]);
//            printf("->%d %d %d %d %d\n",i,j.Y,j.X,ans[j.Y].X,ans[j.Y].Y);
        }
    }
    FOR(i,1,m) printf("%I64d %I64d\n",ans[i].X,ans[i].Y);
}
int main(){
    prepare();
    solve();
}