#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("G.inp","r",stdin)
#define OUTPUT freopen("G.out","w",stdout)
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
const int N=1e5+10,M=1e3+5;

typedef bitset<M> mbset;
int n,m,k;
int a[N],mark[M];
struct graph{
    vector <int> v[N];
    int p[N],in[N],out[N];
    void DFS(int x){
        static int n1=0;
        in[x]=++n1;
        p[n1]=x;
        for(auto y:v[x]) if (!in[y]) DFS(y);
        out[x]=n1;
    }
    void prepare(){
        int x,y;
        REP(i,1,n) {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        DFS(1);
    }
}mygr;
struct segtree{
    mbset b[N<<2];
    int laz[N<<2];
    void build(int node,int L,int R){
        if (L==R){
            b[node][a[mygr.p[L]]%m]=1;
            return;
        }
        build(node*2,L,(L+R)/2);
        build(node*2+1,(L+R)/2+1,R);
        b[node]=b[node*2]|b[node*2+1];
    }
    void lazyupdate(int node,int L,int R){
        int v=laz[node];
        laz[node]=0;
        if (v){
            b[node]=(b[node]>>(m-v))|(b[node]<<v);
//            cout<<node<<" "<<L<<" "<<R<<" "<<b[node]<<'\n';
            if (L==R) return;
            FOR(i,0,1) laz[node*2+i]=(laz[node*2+i]+v)%m;
        }
    }
    void update(int node,int L,int R,int l,int r,int v){
        lazyupdate(node,L,R);
        if (L>r||R<l) return;
        if (l<=L&&R<=r){
            laz[node]=(laz[node]+v)%m;
            lazyupdate(node,L,R);
            return;
        }
        update(node*2,L,(L+R)/2,l,r,v);
        update(node*2+1,(L+R)/2+1,R,l,r,v);
        b[node]=b[node*2]|b[node*2+1];
    }
    mbset get(int node,int L,int R,int l,int r){
        lazyupdate(node,L,R);
        if (L>r||R<l) return mbset();
        if (l<=L&&R<=r) return b[node];
        return get(node*2,L,(L+R)/2,l,r)|get(node*2+1,(L+R)/2+1,R,l,r);
    }
}mseg;


void prepare(){

    scanf("%d%d",&n,&m);
    mbset ans;
    REP(i,2,m) if (!mark[i]){
        ans[i]=1;
        for(int j=i+i;j<m;j+=i) mark[j]=1;
    }
    ///
    FOR(i,1,n) scanf("%d",a+i);
    mygr.prepare();
    mseg.build(1,1,n);
    ///for queries
    int test,type,x,y;
    scanf("%d",&test);
    while (test--){
        scanf("%d%d",&type,&x);
        if (type==1){
            scanf("%d",&y);
            mseg.update(1,1,n,mygr.in[x],mygr.out[x],y);
            continue;
        }
//        mbset cur=mseg.get(1,1,n,mygr.in[x],mygr.out[x]);
//        REP(i,0,m) cout<<cur[i];ENDL;
        printf("%d\n",(mseg.get(1,1,n,mygr.in[x],mygr.out[x])&ans).count());
    }
}

int main(){
//    freopen("input.inp","r",stdin);
    prepare();
}