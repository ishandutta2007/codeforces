// author: xay5421
// created: Thu Jul 22 23:58:33 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=524299,INF=1e9;
vector<int>vec[25];
int lc[N<<2],rc[N<<2],L[N<<2],R[N<<2],res[N<<2];
int ans[N],cnt[N];
int k,n;
void update(int u,int dep){
    res[u]=min(min(res[lc[u]],res[rc[u]]),L[rc[u]]+(1<<dep)-R[lc[u]]);
    L[u]=(L[lc[u]]==INF?(L[rc[u]]==INF?INF:L[rc[u]]+(1<<dep)):L[lc[u]]);
    R[u]=(R[rc[u]]==-INF?R[lc[u]]:R[rc[u]]+(1<<dep));
}
void build(int u,int l,int r,int dep){
    if(l==r){
        if(cnt[l]){
            L[u]=R[u]=0;res[u]=INF;
        }else{
            L[u]=INF;R[u]=-INF;res[u]=INF;
        }
        return;
    }
    vec[dep].push_back(u);
    int mid=(l+r)>>1;
    lc[u]=u<<1;rc[u]=u<<1|1;
    build(u<<1,l,mid,dep-1);
    build(u<<1|1,mid+1,r,dep-1);
    update(u,dep);
}
void rev(int u,int dep){
    swap(lc[u],rc[u]);
    while(u)update(u,dep),u>>=1,++dep;
}
void dfs(int u,int now){
    if(u==k){
        ans[now]=res[1];
        return;
    }
    dfs(u+1,now);
    rep(i,0,SZ(vec[u])-1)rev(vec[u][i],u);
    dfs(u+1,now|(1<<u));
    rep(i,0,SZ(vec[u])-1)rev(vec[u][i],u);
}
int main(){
    rd(n);rd(k);
    rep(i,1,n){
        int x;rd(x);
        ++cnt[x];
    }
    int ok=0;
    rep(i,0,(1<<k)-1)ok|=(cnt[i]>=2);
    if(ok){
        rep(i,1,1<<k)pt(0,' ');
        return 0;
    }
    build(1,0,(1<<k)-1,k-1);
    dfs(0,0);
    rep(i,0,(1<<k)-1)pt(ans[i], ' ');
    return 0;
}