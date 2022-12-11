#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef pair<int,int> ii;


const int inf=1e9+10;
const int N=2e5+10;
const int M=20;


int n,k,m,np;
int a[N];
int p[N];
int rmq[N][M];

ii typ[N];
ii qu[N];

int callRMQ(int L,int R){
    int lv=int(log2(R-L+1));
    return min(rmq[L][lv],rmq[R-(1<<lv)+1][lv]);
}


struct segtree{
    int b[N<<2],laz[N<<2];
    void build(int node,int L,int R){
        laz[node]=-1;
        if (L==R){
            int crL=p[L],crR=p[L+1];
            if (crR-crL>=n) b[node]=callRMQ(0,n-1);
            else {
                crL%=n,crR%=n;
                if (crL<crR) b[node]=callRMQ(crL,crR-1);
                else b[node]=callRMQ(crL,crR+n-1);
            }
            return;
        }
        build(node*2,L,(L+R)/2);
        build(node*2+1,(L+R)/2+1,R);
        b[node]=min(b[node*2],b[node*2+1]);
    }
    void lazyupdate(int node,int L,int R){
        if (laz[node]!=-1){
            b[node]=laz[node];
            if (L<R)
                laz[node*2]=laz[node*2+1]=laz[node];
            laz[node]=-1;
        }
    }
    void update(int node,int L,int R,int l,int r,int val){
        lazyupdate(node,L,R);
        if (L>r||R<l) return;
        if (l<=L&&R<=r){
            laz[node]=val;
            lazyupdate(node,L,R);
            return;
        }
        update(node*2,L,(L+R)/2,l,r,val);
        update(node*2+1,(L+R)/2+1,R,l,r,val);
        b[node]=min(b[node*2],b[node*2+1]);
    }
    int get(int node,int L,int R,int l,int r){
        lazyupdate(node,L,R);
        if (L>r||R<l) return inf;
        if (l<=L&&R<=r) return b[node];
        return min(get(node*2,L,(L+R)/2,l,r),get(node*2+1,(L+R)/2+1,R,l,r));
    }
}mseg;
void prepare(){
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) a[n+i]=a[i];
    cin>>m;
    for(int i=0;i<m;i++) {

        cin>>typ[i].X>>qu[i].X>>qu[i].Y;
        if (typ[i].X==1) cin>>typ[i].Y;
        qu[i].X--,qu[i].Y--;
    }
    np=0;
    for(int i=0;i<m;i++) p[++np]=qu[i].X,p[++np]=qu[i].Y+1;
    p[++np]=n*k;
    p[++np]=0;
    sort(p+1,p+np+1);
    np=unique(p+1,p+np+1)-p-1;


    for(int i=0;i<2*n;i++) rmq[i][0]=a[i];
    for(int j=1;j<M;j++)
        for(int i=0;i<=2*n-(1<<j);i++) rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
    mseg.build(1,1,np-1);
}

void solve(){
    for(int i=0;i<m;i++){
        int L=lower_bound(p+1,p+np+1,qu[i].X)-p;
        int R=lower_bound(p+1,p+np+1,qu[i].Y+1)-p-1;
        if (typ[i].X==1) mseg.update(1,1,np-1,L,R,typ[i].Y);
        else cout<<mseg.get(1,1,np-1,L,R)<<'\n';
    }
}
int main(){
    prepare();
    solve();
}