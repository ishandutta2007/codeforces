#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

const int maxn = 1000005;
struct edge
{
    int v,w,nxt;
}es[maxn<<1];
int head[maxn], tot=1;
inline void adde(int u,int v,int w){es[tot]=edge{v,w,head[u]}, head[u]=tot++;}
int fa[maxn],faw[maxn],dfn[maxn],in[maxn],dfscnt=0,tp=0;
ll mx[maxn],mmx[maxn],pre[maxn],suf[maxn],pre2[maxn],suf2[maxn];
pair<int,ll> lp[maxn];
void dfs1(int u) {
    dfn[u]=++dfscnt;
    for(int j=head[u];j;j=es[j].nxt) {
        int v=es[j].v,w=es[j].w;
        if(v==fa[u]) continue;
        if(dfn[v]) {
            if(dfn[v] < dfn[u]) continue;
            for(int x=v;x!=u;x=fa[x]) in[x]=1,lp[++tp]={x,faw[x]};
            in[u]=1,lp[++tp]={u,w};
        } else {
            fa[v]=u;
            faw[v]=w;
            dfs1(v);
        }
    }
}

ll dfs2(int u,int f) {
    ll ret=0,m1=0,m2=0;
    for(int j=head[u];j;j=es[j].nxt) {
        int v=es[j].v,w=es[j].w;
        if(v==f || in[v]) continue;
        ll tmp=dfs2(v,u)+w;
        mmx[u]=max(mmx[u],mmx[v]);
        ret=max(ret,tmp);
        if(tmp > m1) {
            m2 = m1;
            m1 = tmp;
        } else if(tmp > m2) m2 = tmp;
    }
    mmx[u]=max(mmx[u],m1+m2);
    return ret;
}
inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
int32_t main() {
    int n = read();
    for(int i=1;i<=n;++i) {
        int u=read(),v=read(),w=read();
        adde(u,v,w);
        adde(v,u,w);
    }
    ll ans=0;
    for(int u=1;u<=n;++u) {
        if(!dfn[u]) {
            tp=0;dfs1(u);
            ll tmp=1e18,tmp2=0;
            for(int j=1;j<=tp;++j) {
                mx[j]=dfs2(lp[j].first,-1);
                tmp2=max(tmp2,mmx[lp[j].first]);
            }
//            D(tmp2);
//            for(int i=1;i<=tp;++i) {
//                D(i,mx[i],lp[i].first,lp[i].second);
//            }
            ll dtot=0,dmx=0;
            for(int j=1;j<=tp;++j) {
                pre[j]=max(pre[j-1],dtot+mx[j]);
                pre2[j]=max(pre2[j-1],dtot+mx[j]+dmx);
                dmx=max(dmx,mx  [j]-dtot);
                dtot+=lp[j].second;
            }
            dmx=dtot=0;
            for(int j=tp;j>=1;--j) {
                suf[j]=max(suf[j+1],dtot+mx[j]);
                suf2[j]=max(suf2[j+1],dtot+mx[j]+dmx);
                dmx=max(dmx,mx[j]-dtot);
                dtot+=lp[j-1].second;
            }
//            for(int i=1;i<=tp;++i) {
//                D(i,pre[i],pre2[i],suf[i],suf2[i]);
//            }
            for(int i=1;i<tp;++i) tmp=min(tmp,max(max(max(pre2[i],suf2[i+1]),pre[i]+suf[i+1]+lp[tp].second),tmp2));
            tmp=min(tmp,max(tmp2,pre2[tp]));
            ans+=tmp;
        }
    }
    cout<<ans<<endl;
}