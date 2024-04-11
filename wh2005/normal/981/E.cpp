#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<bitset>

using namespace std;
#define ri int
#define ll long long
#define pii pair<int,int>
#define T bitset<10005> 

const ll mod=1e9+7;
ll add(ll x,ll y){return (x+=y)<mod?x:x-mod;}
ll dec(ll x,ll y){return (x-=y)<0?x+mod:x;}
ll ksm(ll d,ll t,ll res=1){for(;t;t>>=1,d=d*d%mod) if(t&1) res=res*d%mod;return res;}
const int MAXN=1e4+7;
T f,g;
int n,q;
vector<int> vec[MAXN<<2];
#define lc u<<1
#define rc u<<1|1
#define mid (L+R>>1)
void insert(int u,int w,int l,int r,int L=1,int R=n){
    if(l==L&&r==R) return vec[u].push_back(w),void();
    if(r<=mid) insert(lc,w,l,r,L,mid);else if(l>mid) insert(rc,w,l,r,mid+1,R);
    else insert(lc,w,l,mid,L,mid),insert(rc,w,mid+1,r,mid+1,R);
}
void solve(int u,int L=1,int R=n){
    T tmp=f;
    for(auto x:vec[u]) f=f|(f<<x);
    if(L==R) g|=f;
    else solve(lc,L,mid),solve(rc,mid+1,R);
    f=tmp;
}
int main(){
    f[0]=1;
    scanf("%d%d",&n,&q);
    for(ri i=1;i<=q;++i){
        int l,r,w;scanf("%d%d%d",&l,&r,&w);
        insert(1,w,l,r);
    }
    solve(1);
    int cnt=0;
    for(ri i=1;i<=n;++i) if(g[i]) cnt++;
    printf("%d\n",cnt);
    for(ri i=1;i<=n;++i) if(g[i]) printf("%d ",i);
}