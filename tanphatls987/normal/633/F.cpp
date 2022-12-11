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
typedef pair<ll,ll> pll;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e5+10;

int n,q[N],v[N<<1],w[N],pa[N],p[N];
vector <int> e[N];

template <class T>
bool maximize(T &x,T y){
    if (x<y) x=y;else return 0;
    return 1;
}
void update(pll &a,ll v){
    maximize(a.Y,v);
    if (a.Y>a.X) swap(a.Y,a.X);
}
pll merge(pll a,pll b){
    if (b.X>a.X) swap(a,b);
    maximize(a.Y,b.X);
    return a;
}
struct info{
    pll a;
    ll v;
    info (pll _a=pll(0,0),ll _v=0){
        a=_a;v=_v;
    }
};
info fv[N],fe[N<<1],g[2][N];
void BFS(){
    int top=1,bot=1;
    q[1]=1;
    pa[1]=-1;
    while (top<=bot){
        int x=q[top++];
//        cout<<x<<" "<<pa[x]<<'\n';
        for(auto i:e[x]) if (i!=(pa[x]^1)){
            int y=v[i];
            q[++bot]=y;
            pa[y]=i;
        }
    }
}
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",w+i);
    REP(i,0,n-1){
        int x,y;
        scanf("%d%d",&x,&y);
        v[2*i]=y;e[x].push_back(2*i);
        v[2*i+1]=x;e[y].push_back(2*i+1);
    }
    BFS();
}
ll solve(){
    ///bottom up and build down edges
    FORD(pha,n,1){
        int x=q[pha];
        for(auto i:e[x]) if (i!=(pa[x]^1)){
            maximize(fv[x].v,fe[i].v);
            update(fv[x].a,fe[i].a.X);
        }
        fv[x].a.X+=w[x];
        fv[x].a.Y+=w[x];
        maximize(fv[x].v,fv[x].a.X+fv[x].a.Y-w[x]);
        fe[pa[x]]=fv[x];
    }
//    REP(i,0,2*(n-1)) cout<<fe[i].a.X<<" "<<fe[i].a.Y<<" "<<fe[i].v<<'\n';
    ///top down and build up edges
    FOR(pha,1,n){
        int x=q[pha];
        int n1=0;
        for(auto i:e[x]) p[++n1]=i;
//        cout<<x<<" "<<n1<<'\n';
//        FOR(i,1,n1) cout<<p[i]<<" \n"[i==n1];
        g[1][n1+1]=info();
        FOR(i,1,n1){
            g[0][i]=g[0][i-1];
            maximize(g[0][i].v,fe[p[i]].v);
            update(g[0][i].a,fe[p[i]].a.X);
        }
        FORD(i,n1,1){
            g[1][i]=g[1][i+1];
            maximize(g[1][i].v,fe[p[i]].v);
            update(g[1][i].a,fe[p[i]].a.X);
        }
//        FOR(j,0,2)
//            FOR(i,0,n1) cout<<g[0][i][j]<<" \n"[i==n1];
//        FOR(j,0,2)
//            FOR(i,0,n1+1) cout<<g[1][i][j]<<" \n"[i==n1+1];
        FOR(i,1,n1){
            int use=p[i]^1;
            if (use==pa[x]) continue;
            info cur;
            cur.a=merge(g[0][i-1].a,g[1][i+1].a);
            cur.a.X+=w[x],cur.a.Y+=w[x];
            cur.v=max(max(g[0][i-1].v,g[1][i+1].v),cur.a.X+cur.a.Y-w[x]);
            fe[use]=cur;
        }
    }
//    REP(i,0,2*(n-1))
//        FOR(j,0,2) cout<<fe[i][j]<<" \n"[j==2];
    ///
    ll ans=0;
    REP(i,0,n-1) ans=max(ans,fe[i*2].v+fe[i*2+1].v);
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}