#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second

const int MOD=1e9+7;
const int N=1e5+10;

int n,a[N];

struct matrix{
    int a[2][2];
    matrix(){
        memset(a,0,sizeof(a));
    }
};
matrix base[30];
matrix operator *(matrix a,matrix b){
    matrix ans;
    for(int i=0;i<=1;i++)
        for(int j=0;j<=1;j++)
            for(int k=0;k<=1;k++) ans.a[i][j]=(ans.a[i][j]+1LL*a.a[i][k]*b.a[k][j])%MOD;
    return ans;
}
ii mergefib(ii a,ii b){
    ii na;
    na.Y=(1LL*a.Y*b.Y+1LL*a.X*b.X)%MOD;
    na.X=(1LL*a.Y*b.X+1LL*a.X*(b.Y-b.X+MOD))%MOD;
    return na;
}
void prepare(){
    base[0].a[0][0]=base[0].a[0][1]=base[0].a[1][0]=1;
    for(int i=1;i<30;i++) base[i]=base[i-1]*base[i-1];
}
ii getfib(int val){
    matrix ans;
    ans.a[0][0]=ans.a[1][1]=1;
    for(int i=0;val;i++,val>>=1) if (val&1)
        ans=ans*base[i];
    return ii(ans.a[0][1],ans.a[0][0]);
}
ii operator +(ii a,ii b){
    return ii((a.X+b.X)%MOD,(a.Y+b.Y)%MOD);
}
struct segtree{
    ii b[N<<2],laz[N<<2];
    void build(int node,int L,int R){
        laz[node]=ii(0,1);
        if (L==R){
            b[node]=getfib(a[L]);
//            cout<<node<<" "<<L<<" "<<b[node].X<<" "<<b[node].Y<<'\n';
            return;
        }
        build(node*2,L,(L+R)/2);
        build(node*2+1,(L+R)/2+1,R);
        b[node]=b[node*2]+b[node*2+1];
    }
    void lazyupdate(int node,int L,int R){
        b[node]=mergefib(b[node],laz[node]);
        if (L<R){
            for(int i=0;i<=1;i++)
                laz[node*2+i]=mergefib(laz[node*2+i],laz[node]);
        }
        laz[node]=ii(0,1);
    }
    void update(int node,int L,int R,int l,int r,ii cur){
        lazyupdate(node,L,R);
        if (L>r||R<l) return;
        if (l<=L&&R<=r){
            laz[node]=mergefib(laz[node],cur);
            lazyupdate(node,L,R);
            return;
        }
        update(node*2,L,(L+R)/2,l,r,cur);
        update(node*2+1,(L+R)/2+1,R,l,r,cur);
        b[node]=b[node*2]+b[node*2+1];
    }
    int query(int node,int L,int R,int l,int r){
        lazyupdate(node,L,R);
        if (L>r||R<l) return 0;
        if (l<=L&&R<=r) return b[node].X;
        return (query(node*2,L,(L+R)/2,l,r)+query(node*2+1,(L+R)/2+1,R,l,r))%MOD;
    }
}mseg;
int main(){
    prepare();
    int test;
    scanf("%d%d",&n,&test);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    mseg.build(1,1,n);
    while (test--){
        int type,L,R,val;
        scanf("%d%d%d",&type,&L,&R);
        if (type==1){
            scanf("%d",&val);
            mseg.update(1,1,n,L,R,getfib(val));
            continue;
        }
        printf("%d\n",mseg.query(1,1,n,L,R));
    }
}