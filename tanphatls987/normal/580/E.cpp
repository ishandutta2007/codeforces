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
const int MOD=1e9+7,BASE=31;
const int N=1e5+10;

int n,m,k,pb[N],spb[N];
char s[N];
struct seg{
    int len,v,laz;
    seg(int _len=0,int _v=0,int _laz=0){
        len=_len;v=_v;laz=_laz;
    }
}b[N<<2];
seg merge(seg a,seg b){
    return seg(a.len+b.len,(b.v+1LL*a.v*pb[b.len])%MOD,0);
}

void lazyupdate(int node){
    if (!b[node].laz) return;
    b[node].v=1LL*spb[b[node].len-1]*b[node].laz%MOD;
    if (b[node].len>1) b[node*2].laz=b[node*2+1].laz=b[node].laz;
    b[node].laz=0;
}
void build(int node,int L,int R){
    if (L==R){
        b[node]=seg(1,s[L-1]-'0'+1,0);
        return;
    }
    build(node*2,L,(L+R)/2);
    build(node*2+1,(L+R)/2+1,R);
    b[node]=merge(b[node*2],b[node*2+1]);
}
void update(int node,int L,int R,int l,int r,int v){
    lazyupdate(node);
    if (L>r||R<l) return;
    if (l<=L&&R<=r){
        b[node].laz=v+1;
        lazyupdate(node);
        return;
    }
    update(node*2,L,(L+R)/2,l,r,v);
    update(node*2+1,(L+R)/2+1,R,l,r,v);
    b[node]=merge(b[node*2],b[node*2+1]);
}
seg query(int node,int L,int R,int l,int r){
    lazyupdate(node);
    if (L>r||R<l) return seg();
    if (l<=L&&R<=r) return b[node];
    return merge(query(node*2,L,(L+R)/2,l,r),query(node*2+1,(L+R)/2+1,R,l,r));
}
bool check(int L,int R,int v){
    seg p1=query(1,1,n,L,R-v),p2=query(1,1,n,L+v,R);
//        printf("%d %d %d %d %d %d\n",L,L+nex*v+tail,R-nex*v-tail,R,p1.v,p2.v);
    return (p1.v==p2.v);
}
void prepare(){
    scanf("%d%d%d\n%s",&n,&m,&k,s);
    ///
    pb[0]=1;
    FOR(i,1,n) pb[i]=1LL*BASE*pb[i-1]%MOD;
    spb[0]=1;
    FOR(i,1,n) spb[i]=(pb[i]+spb[i-1])%MOD;
    //
    build(1,1,n);
}
int main(){
    prepare();
    int type,x,y,z;
    FOR(te,1,m+k){
        scanf("%d%d%d%d",&type,&x,&y,&z);
        if (type==1) update(1,1,n,x,y,z);
        else {
            if (check(x,y,z)) printf("YES\n");
            else printf("NO\n");
        }
    }
}