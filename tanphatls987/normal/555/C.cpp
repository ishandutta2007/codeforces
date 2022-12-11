#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=2e5+10;

int b[2][N<<3]={0},q[N][3]={0},p[2][N]={0},n,m,tmp;
char ch;
void lazyupdate(int type,int node,int L,int R){
    if (L<R){
        b[type][node*2]=max(b[type][node*2],b[type][node]);
        b[type][node*2+1]=max(b[type][node*2+1],b[type][node]);
    }
}
int query(int type,int node,int L,int R,int x){
    lazyupdate(type,node,L,R);
    if (L>x||R<x) return 0;
    if (L==R) return b[type][node];
    return max(query(type,node*2,L,(L+R)/2,x),query(type,node*2+1,(L+R)/2+1,R,x));
}
void update(int type,int node,int L,int R,int l,int r,int v){
    lazyupdate(type,node,L,R);
    if (L>r||R<l) return;
    if (l<=L&&R<=r){
        b[type][node]=max(b[type][node],v);
        lazyupdate(type,node,L,R);
        return;
    }
    update(type,node*2,L,(L+R)/2,l,r,v);
    update(type,node*2+1,(L+R)/2+1,R,l,r,v);
}
void solve(){
    FOR(i,1,n)
        FOR(j,0,1) q[i][j]=lower_bound(p[j]+1,p[j]+m+1,q[i][j])-p[j];
    FOR(as,1,n){
        int type=q[as][2],x=q[as][type],y=q[as][type^1];
        int cord=query(type,1,1,m,x);
        printf("%d\n",p[type^1][y]-p[type^1][cord]);
        update(type^1,1,1,m,cord+1,y,x);
        update(type,1,1,m,x,x,y);
    }
}
int main(){
    scanf("%d%d",&tmp,&n);
    FOR(i,1,n){
        scanf("%d%d %c",&q[i][0],&q[i][1],&ch);
//        printf("%d %d %c\n",q[i][0],q[i][1],ch);
        p[0][i]=q[i][0],p[1][i]=q[i][1];
        q[i][2]=(ch=='L');
    }
    FOR(i,0,1) {
        sort(p[i]+1,p[i]+n+2);
        m=unique(p[i]+1,p[i]+n+2)-p[i]-1;
    }
    solve();
}