#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
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
const int N=4e5+10;

int n,p[N],in[N],out[N],c[N];
ll b[N<<2];
int laz[N<<2];
vector <int> v[N];
void DFS(int par,int x){
    static int top=0;
    in[x]=++top;
    p[top]=x;
    for(auto y:v[x]) if (y!=par) DFS(x,y);
    out[x]=top;
}
void lazyupdate(int node,int L,int R){
    if (laz[node]){
        b[node]=1LL<<laz[node];
        if (L<R){
            laz[node*2]=laz[node*2+1]=laz[node];
        }
        laz[node]=0;
    }
}
void update(int node,int L,int R,int l,int r,int v){
    lazyupdate(node,L,R);
    if (L>r||R<l) return;
    if (l<=L&&R<=r){
        laz[node]=v;
        lazyupdate(node,L,R);
        return;
    }
    update(node*2,L,(L+R)/2,l,r,v);
    update(node*2+1,(L+R)/2+1,R,l,r,v);
    b[node]=b[node*2]|b[node*2+1];
}
ll get(int node,int L,int R,int l,int r){
    lazyupdate(node,L,R);
    if (L>r||R<l) return 0;
    if (l<=L&&R<=r) return b[node];
    return get(node*2,L,(L+R)/2,l,r)|get(node*2+1,(L+R)/2+1,R,l,r);
}
void build(int node,int L,int R){
    if (L==R){
        b[node]=1LL<<c[p[L]];
        return;
    }
    build(node*2,L,(L+R)/2);
    build(node*2+1,(L+R)/2+1,R);
    b[node]=b[node*2]|b[node*2+1];
}
void prepare(){
    int test,x,y,type;
    scanf("%d%d",&n,&test);
    FOR(i,1,n) scanf("%d",c+i);
    FOR(i,1,n-1){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(0,1);
    build(1,1,n);

    while (test--){
        scanf("%d",&type);
        if (type==1){
            scanf("%d%d",&x,&y);
            update(1,1,n,in[x],out[x],y);
            continue;
        }
        scanf("%d",&x);
        printf("%d\n",__builtin_popcountll(get(1,1,n,in[x],out[x])));
    }
}
int main(){
    prepare();

}