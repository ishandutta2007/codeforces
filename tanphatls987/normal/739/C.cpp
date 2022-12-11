#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,int> ii;

const int N=3e5+10;

int n,a[N];
int f[4][N];
int tidx[N];
struct BIT{
    ll b[N<<2];
    void add(int x,int val){
        while (x<=n){
            b[x]+=val;
            x+=x&-x;
        }
    }
    ll get(int x){
        ll ans=0;
        while (x){
            ans+=b[x];
            x-=x&-x;
        }
        return ans;
    }
}mbit;
struct segtree{
    int b[N<<2][4];
    int lazb[N<<2][4];
    int f[N<<2];
    void build(int node,int L,int R){
        if (L==R){
            for(int i=0;i<4;i++) b[node][i]=::f[i][L];
            f[node]=b[node][2]+b[node][3];
            return;
        }
        build(node*2,L,(L+R)/2);
        build(node*2+1,(L+R)/2+1,R);
        f[node]=max(f[node*2],f[node*2+1]);
    }
    void lazyupdate(int node,int L,int R){
        for(int i=0;i<4;i++) b[node][i]+=lazb[node][i];
        f[node]+=lazb[node][2]+lazb[node][3];
        if (L<R){
            for(int i=0;i<=1;i++){
                for(int j=0;j<4;j++) lazb[node*2+i][j]+=lazb[node][j];
            }
        }
        memset(lazb[node],0,sizeof(lazb[node]));
    }
    void updateb(int node,int type,int L,int R,int l,int r,int val){
        lazyupdate(node,L,R);
        if (L>r||R<l) return;
        if (l<=L&&R<=r){
            lazb[node][type]+=val;
            lazyupdate(node,L,R);
            return;
        }
        updateb(node*2,type,L,(L+R)/2,l,r,val);
        updateb(node*2+1,type,(L+R)/2+1,R,l,r,val);
        f[node]=max(f[node*2],f[node*2+1]);
    }
    int flush(int node,int L,int R,int idx){
        lazyupdate(node,L,R);
        if (L>idx||R<idx) return 0;
        if (L==R) return node;
        return (flush(node*2,L,(L+R)/2,idx)+flush(node*2+1,(L+R)/2+1,R,idx));
    }
    void updaterange(int L,int R,int val){
        if (L>1){
            int bL=flush(1,1,n,L-1),cL=flush(1,1,n,L);
            int tmpL[4]={b[bL][0],b[cL][1],b[cL][2],b[bL][3]};
            ll vbL=mbit.get(L-1)+a[L-1],vcL=mbit.get(L)+a[L];
            if (vbL>vcL&&vcL+val>=vbL){
                updateb(1,2,1,n,L-tmpL[0],L-1,-tmpL[2]);
                updateb(1,0,1,n,L,L+tmpL[2]-1,-tmpL[0]);
            }
            if (vbL>=vcL&&vcL+val>vbL){
                updateb(1,1,1,n,L-tmpL[3],L-1,tmpL[1]);
                updateb(1,3,1,n,L,L+tmpL[1]-1,tmpL[3]);
            }
        }
        ///
        if (R<n){
            int bR=flush(1,1,n,R+1),cR=flush(1,1,n,R);
            int tmpR[4]={b[cR][0],b[bR][1],b[bR][2],b[cR][3]};
            ll vbR=mbit.get(R+1)+a[R+1],vcR=mbit.get(R)+a[R];
            if (vbR>vcR&&vcR+val>=vbR){
                updateb(1,1,1,n,R-tmpR[3]+1,R,-tmpR[1]);
                updateb(1,3,1,n,R+1,R+tmpR[1],-tmpR[3]);
            }
            if (vcR<=vbR&&vcR+val>vbR){
                updateb(1,0,1,n,R+1,R+tmpR[2],tmpR[0]);
                updateb(1,2,1,n,R-tmpR[0]+1,R,tmpR[2]);
            }
        }
        mbit.add(L,val);
        mbit.add(R+1,-val);
    }
}mseg;

void prepare(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++){
        if (a[i]>a[i-1]) f[3][i]=f[3][i-1]+1;
        else f[3][i]=1;
        if (a[i]<a[i-1]) f[0][i]=f[0][i-1]+1;
        else f[0][i]=1;
    }
    for(int i=n;i>=1;i--){
        if (a[i]>a[i+1]) f[2][i]=f[2][i+1]+1;
        else f[2][i]=1;
        if (a[i]<a[i+1]) f[1][i]=f[1][i+1]+1;
        else f[1][i]=1;
    }
    mseg.build(1,1,n);
}


int main(){
    prepare();
//    for(int i=1;i<=n;i++) tidx[i]=mseg.flush(1,1,n,i);
    ///
    int test;
    scanf("%d",&test);
    while (test--){
        int L,R,val;
        scanf("%d%d%d",&L,&R,&val);
        mseg.updaterange(L,R,val);

        printf("%d\n",mseg.f[1]-1);
    }
}