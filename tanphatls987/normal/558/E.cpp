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
const int MOD=1e9+7,alpha=26;
const int N=1e5+10;

int laz[N<<2],b[N<<2][alpha],n,m,h[alpha];
char s[N];
void lazyupdate(int node,int L,int R){
    if (laz[node]==-1) return;
    memset(b[node],0,sizeof(b[node]));
    b[node][laz[node]]=R-L+1;
    if (L<R){
        laz[node*2]=laz[node];
        laz[node*2+1]=laz[node];
    }
    laz[node]=-1;
}
void build(int node,int L,int R){
    laz[node]=-1;
    if (L==R){
        b[node][s[L-1]-'a']=1;
        return;
    }
    build(node*2,L,(L+R)/2);
    build(node*2+1,(L+R)/2+1,R);
    REP(i,0,alpha) b[node][i]=b[node*2][i]+b[node*2+1][i];
}
void query(int node,int L,int R,int l,int r){
    lazyupdate(node,L,R);
    if (L>r||R<l) return ;
    if (l<=L&&R<=r){
        REP(i,0,alpha) h[i]+=b[node][i];
        return;
    }
    query(node*2,L,(L+R)/2,l,r);
    query(node*2+1,(L+R)/2+1,R,l,r);
}
void update(int node,int L,int R,int l,int r,int x){
    lazyupdate(node,L,R);
    if (L>r||R<l) return;
    if (l<=L&&R<=r){
        laz[node]=x;
        lazyupdate(node,L,R);
        return;
    }
    update(node*2,L,(L+R)/2,l,r,x);
    update(node*2+1,(L+R)/2+1,R,l,r,x);
    REP(i,0,alpha) b[node][i]=b[node*2][i]+b[node*2+1][i];
}
void rebuild(int node,int L,int R){
    lazyupdate(node,L,R);
    if (L==R) printf("%c",max_element(b[node],b[node]+alpha)-b[node]+'a');
    else{
        rebuild(node*2,L,(L+R)/2);
        rebuild(node*2+1,(L+R)/2+1,R);
    }
}
int main(){
    scanf("%d%d\n%s",&n,&m,s);
    build(1,1,n);
    int x,y,type;
    while (m--){
        scanf("%d%d%d",&x,&y,&type);
        memset(h,0,sizeof(h));
        query(1,1,n,x,y);
//        REP(i,0,alpha) cout<<h[i]<<" \n"[i==alpha-1];
        if (type) {
            REP(i,0,alpha) if (h[i]) {
//                printf("%d %d %d\n",i,x,x+h[i]-1);
                update(1,1,n,x,x+h[i]-1,i);
                x+=h[i];
            }
        }else {
            FORD(i,alpha-1,0) if (h[i]) {
//                printf("%d %d %d\n",i,x,x+h[i]-1);
                update(1,1,n,x,x+h[i]-1,i);
                x+=h[i];
            }
        }
    }
    rebuild(1,1,n);
}