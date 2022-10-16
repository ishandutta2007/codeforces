#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;

const int maxn=200007;
const int mod=998244353;
int n,q;
long long ans=0;
int p[maxn],inv[107];
pair<int,int> tree[maxn<<2];
set<int> s;

int quick_power(int a,int b){
    int ans=1,t=a;
    while (b){
        if (b&1){
            ans=1ll*ans*t%mod;
        }
        t=1ll*t*t%mod, b>>=1;
    }
    return ans;
}

int inverse(int u){
    return quick_power(u,mod-2);
}

int mult(int u,int v){
    return 1ll*u*v%mod;
}

pair<int,int> prod(pair<int,int> u,pair<int,int> v){
    return {mult(u.F,v.F),(mult(u.S,v.F)+v.S)%mod};
}
void pushup(int num){
    tree[num]=prod(tree[num<<1],tree[num<<1|1]);
}

void build(int num,int l,int r){
    if (l==r){
        tree[num].F=tree[num].S=mult(100,inv[p[l]]);
        return;
    }
    int md=(l+r)>>1;
    build(num<<1,l,md);
    build(num<<1|1,md+1,r);
    pushup(num);
}

pair<int,int> query(int num,int l,int r,int L,int R){
    if (L<=l&&r<=R){
        return tree[num]; 
    }
    int md=(l+r)>>1;
    pair<int,int> ret={1,0};
    if (L<=md) ret=prod(ret,query(num<<1,l,md,L,R));
    if (R>md) ret=prod(ret,query(num<<1|1,md+1,r,L,R));
    return ret;
}

int main(){
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;++i){
        scanf("%d",&p[i]);
    }
    for (int i=1;i<=100;++i){
        inv[i]=inverse(i);
    }
    build(1,1,n);
    ans=query(1,1,n,1,n).S;
    s.insert(1),s.insert(n+1);
    while (q--){
        int u;
        scanf("%d",&u);
        if (s.find(u)==s.end()){
            s.insert(u);
            auto p=s.find(u);
            int l=*prev(p), r=*next(p);
            ans-=query(1,1,n,l,r-1).S;
            ans+=query(1,1,n,l,u-1).S+query(1,1,n,u,r-1).S;
        }
        else{
            auto p=s.find(u);
            int l=*prev(p), r=*next(p);
            ans+=query(1,1,n,l,r-1).S;
            ans-=query(1,1,n,l,u-1).S+query(1,1,n,u,r-1).S;
            s.erase(p);
        }
        ans=(ans%mod+mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}