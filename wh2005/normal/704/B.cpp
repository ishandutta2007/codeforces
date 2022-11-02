#include<bits/stdc++.h>
using namespace std;
#define il inline
#define ri register int
#define ll long long
#define ui unsigned int
il ll read(){
    bool f=true;ll x=0;
    register char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=false;ch=getchar();}
    while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    if(f) return x;
    return ~(--x);
}
il void write(const ll &x){if(x>9) write(x/10);putchar(x%10+'0');}
il void print(const ll &x) {x<0?putchar('-'),write(~(x-1)):write(x);putchar('\n');}
il ll max(const ll &a,const ll &b){return a>b?a:b;}
il ll min(const ll &a,const ll &b){return a<b?a:b;}
const int MAXN=5e3+7;
ll x[MAXN],a[MAXN],b[MAXN],c[MAXN],d[MAXN];
ll f(int p,int q){
    if(p>q) return x[p]-x[q]+c[p]+b[q];
    if(p<q) return x[q]-x[p]+d[p]+a[q];
}
int n,s,t;
int nxt[MAXN];
#define pll pair<ll,ll>
ll ans;
int main(){
    n=read(),s=read(),t=read();
    for(ri i=1;i<=n;++i) x[i]=read();
    for(ri i=1;i<=n;++i) a[i]=read();
    for(ri i=1;i<=n;++i) b[i]=read();
    for(ri i=1;i<=n;++i) c[i]=read();
    for(ri i=1;i<=n;++i) d[i]=read();
    nxt[s]=t;
    ans=f(s,t);
    for(ri i=1;i<=n;++i){
        if(i==s||i==t) continue;
        pll now=(pll){1e18,0};
        for(ri u=s;u!=t;u=nxt[u]){
            int v=nxt[u];
            ll delta=f(u,i)+f(i,v)-f(u,v);
            now=min(now,(pll){delta,u});
        }
        ans+=now.first;
        nxt[i]=nxt[now.second],nxt[now.second]=i;
    }
    print(ans);
    return 0;
}