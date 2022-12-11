#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("hwork.inp","r",stdin)
#define OUTPUT freopen("hwork.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9;
const int N=2e5+10;

ll fib[N],sfib[N];
int n,a[N];
struct info{
    ll v,rec,len;
    info (ll _v=0,ll _rec=0,ll _len=0){
        v=_v;rec=_rec;len=_len;
    }
};
info merge(info a,info b){
    if (!a.len) return b;
    if (!b.len) return a;
    return info((a.v+b.v*fib[a.len+1]+b.rec*fib[a.len])%MOD,(a.rec+b.v*fib[a.len]+b.rec*fib[a.len-1])%MOD,a.len+b.len);
}
info scale(info a,ll add){
    return info((a.v+sfib[a.len]*add)%MOD,(a.rec+sfib[a.len-1]*add)%MOD,a.len);
}

struct segtree{
    ll laz[N<<2];
    info b[N<<2];
    void build(int node,int L,int R){
        if (L==R){
            b[node]=info(a[L],0,1);
            return;
        }
        build(node*2,L,(L+R)/2);
        build(node*2+1,(L+R)/2+1,R);
        b[node]=merge(b[node*2],b[node*2+1]);
    }
    void lazyupdate(int node,int L,int R){
        b[node]=scale(b[node],laz[node]);
        if (L<R){
            laz[node*2]=(laz[node*2]+laz[node])%MOD;
            laz[node*2+1]=(laz[node*2+1]+laz[node])%MOD;
        }
        laz[node]=0;
    }
    void supdate(int node,int L,int R,int idx,int nval){
        lazyupdate(node,L,R);
        if (L>idx||R<idx) return;
        if (L==R){
            a[L]=nval;
            b[node]=info(nval,0,1);
            return;
        }
        supdate(node*2,L,(L+R)/2,idx,nval);
        supdate(node*2+1,(L+R)/2+1,R,idx,nval);
        b[node]=merge(b[node*2],b[node*2+1]);
    }
    void rupdate(int node,int L,int R,int l,int r,int add){
//        cout<<node<<" "<<L<<" "<<R<<'\n';
        lazyupdate(node,L,R);
        if (L>r||R<l) return;
        if (l<=L&&R<=r){
            laz[node]=(laz[node]+add)%MOD;
            lazyupdate(node,L,R);
            return;
        }
        rupdate(node*2,L,(L+R)/2,l,r,add);
        rupdate(node*2+1,(L+R)/2+1,R,l,r,add);
        b[node]=merge(b[node*2],b[node*2+1]);
    }
    info get(int node,int L,int R,int l,int r){
        lazyupdate(node,L,R);
        if (L>r||R<l) return info();
        if (l<=L&&R<=r) return b[node];
        return merge(get(node*2,L,(L+R)/2,l,r),get(node*2+1,(L+R)/2+1,R,l,r));
    }
}mseg;
void prepare(){
    fib[1]=1;
    REP(i,2,N) fib[i]=(fib[i-1]+fib[i-2])%MOD;
    REP(i,1,N) sfib[i]=(sfib[i-1]+fib[i])%MOD;
//    FOR(i,0,10) cout<<sfib[i]<<" ";ENDL;
    ///
    int test,type,x,y,add;
    ///
    scanf("%d%d",&n,&test);
    FOR(i,1,n) scanf("%d",a+i);
    mseg.build(1,1,n);
    while (test--){
        scanf("%d",&type);
        if (type==1){
            scanf("%d%d",&x,&y);
            mseg.supdate(1,1,n,x,y);
        }
        if (type==2){
            scanf("%d%d",&x,&y);
            printf("%lld\n",mseg.get(1,1,n,x,y).v);
        }
        if (type==3){
            scanf("%d%d%d",&x,&y,&add);
            mseg.rupdate(1,1,n,x,y,add);
        }
    }
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
}