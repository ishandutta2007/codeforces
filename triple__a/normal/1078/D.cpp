#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int>

using namespace std;
 
typedef long long ll;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn=300007;
int n,a[maxn];
static PI tree[maxn<<2][20];

inline int min(int u,int v){
    return u>v?v:u;
}

inline int max(int u,int v){
    return u>v?u:v;
}

inline void pushup(int num,int val){
    tree[num][val]={min(tree[num<<1][val].F,tree[num<<1|1][val].F),max(tree[num<<1][val].S,tree[num<<1|1][val].S)};
}

pair<int,int> query(int num,int l,int r,int val,int L,int R){
//    cout<<num<<" "<<l<<" "<<r<<" "<<val<<" "<<L<<" "<<R<<endl;
    if (L<=l&&r<=R){
        return tree[num][val];
    }
    int md=(l+r)>>1;
    if (md>=L&&md>=R){
        return query(num<<1,l,md,val,L,R);
    }
    if (md<R&&md<L){
        return query(num<<1|1,md+1,r,val,L,R);    
    }
    if (md<R&&md>=L){
        PI tmp=query(num<<1,l,md,val,L,R), tmp2=query(num<<1|1,md+1,r,val,L,R);
        return {min(tmp.F,tmp2.F),max(tmp.S,tmp2.S)};
    }
}

void build(int num,int l,int r,int val){
    if (l==r){
        if (!val){
            tree[num][0]={max(l-a[l],1),min(l+a[l],3*n)};
        }
        else{
            PI rg=query(1,1,3*n,val-1,l,l);
            tree[num][val]=query(1,1,3*n,val-1,rg.F,rg.S);
        }
        return;
    }
    int md=(l+r)>>1;
    build(num<<1,l,md,val);
    build(num<<1|1,md+1,r,val);
    pushup(num,val);
}

inline int calc(int u){
    int ret=0;
    PI cnt={u,u};
    for (int i=16;i>-1;--i){
        PI tmp=query(1,1,3*n,i,cnt.F,cnt.S);
        if (tmp.S-tmp.F<n-1) {ret+=(1<<i); cnt=tmp;}
    }
    return ret;
}

int main(){
    scanf("%d",&n);
    if (n==1){
        puts("0");
        return 0;
    }
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        a[i+n]=a[i+2*n]=a[i];
    }
    for (int i=0;i<17;++i){
        build(1,1,3*n,i);
    }
    for (int i=n+1;i<=2*n;++i){
        printf("%d ",calc(i)+1);
    }
    return 0;
}