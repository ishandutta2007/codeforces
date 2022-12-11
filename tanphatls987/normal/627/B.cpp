#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
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
const int N=2e5+10;

int n,k;
struct segtree{
    int b[N<<2],cap;
    void add(int node,int L,int R,int idx,int v){
        if (L>idx||R<idx) return;
        if (L==R){
            b[node]=min(cap,b[node]+v);
            return;
        }
        add(node*2,L,(L+R)/2,idx,v);
        add(node*2+1,(L+R)/2+1,R,idx,v);
        b[node]=b[node*2]+b[node*2+1];
    }
    int get(int node,int L,int R,int l,int r){
        if (l>r) return 0;
        if (L>r||R<l) return 0;
        if (l<=L&&R<=r) return b[node];
        return get(node*2,L,(L+R)/2,l,r)+get(node*2+1,(L+R)/2+1,R,l,r);
    }
}bef,aft;
void prepare(){
    int test,type,x,y;
    scanf("%d%d%d%d%d",&n,&k,&aft.cap,&bef.cap,&test);
    while (test--){
        scanf("%d%d",&type,&x);
        if (type==2){
            int ans=bef.get(1,1,n,1,x-1)+aft.get(1,1,n,x+k,n);
            printf("%d\n",ans);
            continue;
        }
        scanf("%d",&y);
        bef.add(1,1,n,x,y);
        aft.add(1,1,n,x,y);
    }
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
}