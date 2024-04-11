#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const ll inf=1e15;
const int MOD=1e9+7;
const int N=1e5+10;


ll h[N],d[N],g[N];
int n,m,q,x,y;
struct info{
    int L,R;
    ll rmax,lmax,v;
    info(ll _v=0,ll _lmax=0,ll _rmax=0,int _L=0,int _R=0){
        v=_v;lmax=_lmax;rmax=_rmax;L=_L;R=_R;
    }
}b[N<<2];
int idx(int x){return (x+n)%n;}
ll dis(int x,int y){
    if (y>=x) return g[y-1]-g[x-1];
    return g[n]-g[x-1]+g[y-1];
}
info merge(info a,info b){
    return info(max(max(a.v,b.v),a.rmax+b.lmax+dis(a.R,b.L)),max(a.lmax,b.lmax+dis(a.L,b.L)),max(b.rmax,a.rmax+dis(a.R,b.R)),a.L,b.R);
}
void build(int node,int L,int R){
    if (L==R){
        b[node]=info(0,2*h[L],2*h[L],L,L);
        return;
    }
    build(node*2,L,(L+R)/2);
    build(node*2+1,(L+R)/2+1,R);
    b[node]=merge(b[node*2],b[node*2+1]);
}
info query(int node,int L,int R,int l,int r){
    if (l>n||r<1) return info(-inf,-inf,-inf);
    if (L>r||R<l) return info(-inf,-inf,-inf,L,R);
    if (l<=L&&R<=r) return b[node];
    return merge(query(node*2,L,(L+R)/2,l,r),query(node*2+1,(L+R)/2+1,R,l,r));
}
void prepare(){
    scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%lld",d+i),g[i]=g[i-1]+d[i];
    FOR(i,1,n) scanf("%lld",h+i);

}
void check(int node,int L,int R){
    printf("%d %d %d %lld %lld %lld\n",node,L,R,b[node].v,b[node].lmax,b[node].rmax);
    if (L<R){
        check(node*2,L,(L+R)/2);
        check(node*2+1,(L+R)/2+1,R);
    }
}
int main(){
    prepare();
    build(1,1,n);
    //check(1,1,n);
    while (q--){
        scanf("%d%d",&x,&y);
        info ans;
        if (x<=y) ans=merge(query(1,1,n,y+1,n),query(1,1,n,1,x-1));
        else ans=query(1,1,n,y+1,x-1);
        printf("%lld\n",ans.v);
    }
}