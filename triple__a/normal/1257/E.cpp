#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int,int>

using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* DSU
int p[maxn]; // rep1(i,n) p[i]=i;

int find(int u){
    if (p[u]==u) return u;
    return p[u]=find(p[u]);
}

bool unite(int u,int v){
    int pu=find(u),pv=find(v);
    p[pu]=pv;
    return pu!=pv;
}
*/

const int maxn=200007;

int tree[maxn<<2],lz[maxn<<2],idx[maxn];
int n,k1,k2,k3;

void pushup(int num){
    tree[num]=min(tree[num<<1],tree[num<<1|1]);
}

void pushdown(int num){
    if (lz[num]){
        tree[num<<1]+=lz[num];
        tree[num<<1|1]+=lz[num];
        lz[num<<1]+=lz[num];
        lz[num<<1|1]+=lz[num];
        lz[num]=0;
    }
}

void build(int num,int l,int r){
    if (l==r){
        tree[num]=0;
        return;
    }
    int md=(l+r)>>1;
    build(num<<1,l,md);
    build(num<<1|1,md+1,r);
    pushup(num);
}

void update(int num,int l,int r,int L,int R,int val){
    if (L<=l&&r<=R){
        tree[num]+=val;
        lz[num]+=val;
        return;
    }
    pushdown(num);
    int md=(l+r)>>1;
    if (L<=md) update(num<<1,l,md,L,R,val);
    if (R>md) update(num<<1|1,md+1,r,L,R,val);
    pushup(num);
}

int main(){
    scanf("%d%d%d",&k1,&k2,&k3);
    int u,ans=k1+k2,mv=k1+k2;
    rep(i,k1) scanf("%d",&u),idx[u]=1;
    rep(i,k2) scanf("%d",&u),idx[u]=2;
    rep(i,k3) scanf("%d",&u),idx[u]=3;
    n=k1+k2+k3;
    build(1,1,n+1);
    rep1(i,n){
        if (idx[i]==3){
            mv++;
        }
        else{
            mv--;
            if (idx[i]==1){
                update(1,1,n+1,1,i,1);
            }
            else{
                update(1,1,n+1,i+1,n+1,1);
            }
        }
        ans=min(ans,tree[1]+mv);
    }
    printf("%d\n",ans);
    return 0;
}