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
int n,m;
const int MAXN=2e5+7;
vector<int> g[MAXN][2];
const ll mod=998244353;
il ll add(ll x,ll y){return (x+=y)<mod?x:x-mod;}
il ll dec(ll x,ll y){return (x-=y)<0?x+mod:x;}
il ll ksm(ll d,ll tim){
    ll rest=1;
    while(tim){
        if(tim&1) rest=rest*d%mod;
        d=d*d%mod;
        tim>>=1;
    }
    return rest;
}
struct state
{
    int x,y,id;
};
const int lim=19;
bool cmp(const state &u,const state &v){
    if(u.x==v.x) return u.y<v.y;
    if(u.x>lim||v.x>lim) return u.x<v.x;
    return (1<<u.x)+u.y<(1<<v.x)+v.y;
}
bool operator<(const state &u,const state &v){
    return cmp(v,u);
}
priority_queue<state>q;
int mark[MAXN][2];
int main(){
    n=read(),m=read();
    // for(ri x=1;x<=n;x<<=1) ++lim;
    q.push((state){0,0,1});
    for(ri i=1;i<=m;++i){
        int u=read(),v=read();
        g[u][0].push_back(v);
        g[v][1].push_back(u);
    }
    memset(mark,0x3f,sizeof(mark));
    while (!q.empty())
    {
        state u=q.top();q.pop();
        if(mark[u.id][u.x&1]<=u.x) continue;
        mark[u.id][u.x&1]=u.x;
        if(u.id==n) {
            print((ksm(2,u.x)+u.y-1)%mod);
            // fprintf(stderr,"%.0lf",1000.0*clock()/CLOCKS_PER_SEC);
            return 0;
        }
        for(auto v:g[u.id][u.x&1])  q.push((state){u.x,u.y+1,v});
        for(auto v:g[u.id][(u.x&1)^1])  q.push((state){u.x+1,u.y+1,v});
    }
    return 0;
}