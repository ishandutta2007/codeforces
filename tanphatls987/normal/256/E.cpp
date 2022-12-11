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

const int inf=1e9;
const int MOD=777777777;
const int N=1e5+10;

int b[N<<2][3][3],a[N],good[3][3],n;
void merge(int node){
    memset(b[node],0,sizeof(b[node]));
    FOR(p1,0,2)
        FOR(p2,0,2) if (good[p1][p2])
            FOR(r1,0,2)
                FOR(r2,0,2) b[node][r1][r2]=(b[node][r1][r2]+1LL*b[node<<1][r1][p1]*b[node*2+1][p2][r2])%MOD;
}
void build(int node,int L,int R){
    if (L==R){
        FOR(i,0,2) b[node][i][i]=1;
        return;
    }
    build(node*2,L,(L+R)/2);
    build(node*2+1,(L+R)/2+1,R);
    merge(node);
}
void query(int node,int L,int R,int M){
    if (L>M||R<M) return;
    if (L==R&&R==M){
        FOR(i,0,2) b[node][i][i]=(a[M]==-1||a[M]==i);
        return;
    }
    query(node*2,L,(L+R)/2,M);
    query(node*2+1,(L+R)/2+1,R,M);
    merge(node);
}
int main(){
    int m,x,v;
    scanf("%d%d",&n,&m);
    FOR(i,0,2)
        FOR(j,0,2) scanf("%d",&good[i][j]);
    build(1,1,n);
    while (m--){
        scanf("%d%d",&x,&v);
        a[x]=v-1;
        query(1,1,n,x);
        int ans=0;
        FOR(r1,0,2)
            FOR(r2,0,2) ans=(ans+b[1][r1][r2])%MOD;
        printf("%d\n",ans);
    }
}