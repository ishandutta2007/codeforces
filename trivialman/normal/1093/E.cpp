#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repr(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 1e9+7;
const int N = 200010;

int a[N],b[N],n,q,m,x;
struct Fenwick_Tree{
    int a[510][N];
    void add(int x,int y,int z){
        for(x=x/q+1;x<=n/q;x+=x&-x)
            for(int i=y;i<=n;i+=i&-i)
                a[x][i]+=z;
    }
    int query(int x,int k){
        int ret=0;
        for(;x;x-=x&-x)
            for(int i=k;i;i-=i&-i)
                ret+=a[x][i];
        return ret;
    }
}t;

int query(int x,int k){
    int y=x/q*q,ans=0;
    if(!y)y=1;
    for(int i=y;i<=x;++i)ans+=(b[i]<=k);
    ans+=t.query(x/q,k);
    return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
    scanf("%d%d",&n,&m);
    q=sqrt(n);
    rep(i,1,n)scanf("%d",&x),a[x]=i;
    rep(i,1,n)scanf("%d",&x),b[i]=a[x];
    //rep(i,1,n)cout<<b[i]<<" ";cout<<endl;
    rep(i,1,n)t.add(i,b[i],1);
    int A,B,C,D,E,ans;
    while(m--){
        scanf("%d%d%d",&A,&B,&C);
        if(A==1){
            scanf("%d%d",&D,&E);
            ans=query(E,C)-query(E,B-1)-query(D-1,C)+query(D-1,B-1);
            printf("%d\n",ans);
        }
        else{
            t.add(B,b[B],-1);
            t.add(C,b[C],-1);
            t.add(B,b[C],1);
            t.add(C,b[B],1);
            swap(b[B],b[C]);
        }
    }
}