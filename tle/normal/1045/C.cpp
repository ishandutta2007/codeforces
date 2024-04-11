#include"bits/stdc++.h"


#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(int x = (l);x<=(u);x++)
#define RREP(x,l,u) for(int x = (l);x>=(u);x--)
#define mst(x,a) memset(x,a,sizeof(x))
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define se second
#define fi first
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define sz(x) ((int)x.size())
#define cl(x) x.clear()

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;

const int maxn = 400010;
const int mod = 1e9+7;
const int MAX = 1000000010;
const double eps = 1e-6;
const double PI = acos(-1);

template<typename T> inline void read(T &x){
    x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}

template<typename A,typename B> inline void read(A&x,B&y){read(x);read(y);}
template<typename A,typename B,typename C> inline void read(A&x,B&y,C&z){read(x);read(y);read(z);}
template<typename A,typename B,typename C,typename D> inline void read(A&x,B&y,C&z,D&w){read(x);read(y);read(z);read(w);}
template<typename A,typename B> inline A fexp(A x,B p){A ans=1;for(;p;p>>=1,x=1LL*x*x%mod)if(p&1)ans=1LL*ans*x%mod;return ans;}
template<typename A,typename B> inline A fexp(A x,B p,A mo){A ans=1;for(;p;p>>=1,x=1LL*x*x%mo)if(p&1)ans=1LL*ans*x%mo;return ans;}

int n,m,q;

vector<int> G[maxn],W[maxn];

map<PII,int> ban;

int low[maxn],dfn[maxn],S[maxn],tot,top;

int cnt;vector<int> bcc[maxn];

int size[maxn],fa[maxn],son[maxn],len[maxn],an[maxn],dep[maxn];

int U[500010],V[500010];

void dfs(int u,int f){
    low[u]=dfn[u]=++tot;
    for(auto v:G[u])if(v!=f){
        if(!dfn[v]){
            S[++top]=v;
            dfs(v,u);
            if(low[v]>=dfn[u]){
                cnt++;
                do{
                    bcc[cnt].PB(S[top]);
                }while(S[top--]!=v);
                bcc[cnt].PB(u);
            }
            if(low[v]<low[u])low[u]=low[v];
        }
        if(dfn[v]<low[u])low[u]=dfn[v];
    }
}

void dfs1(int u){
    size[u]=1;
    int now=-1;
    for(auto v:G[u]){
        now++;
        if(v!=fa[u]){
            fa[v]=u;
            dep[v]=dep[u]+1;
            len[v]=len[u]+W[u][now];
            dfs1(v);
            size[u]+=size[v];
        }
    }
    if(size[u]>size[son[fa[u]]])son[fa[u]]=u;
}

void dfs2(int u,int anc){
    an[u]=anc;
    if(son[u])dfs2(son[u],anc);
    for(auto v:G[u])if(v!=son[u]&&v!=fa[u])dfs2(v,v);
}

int lca(int u,int v){
    while(an[u]!=an[v]){
        if(dep[an[u]]>dep[an[v]])u=fa[an[u]];else v=fa[an[v]];
    }
    return dep[u]<dep[v]?u:v;
}

void find_bcc(){
    dfs(1,0);
    REP(i,1,cnt)
        for(auto x:bcc[i])
            for(auto y:bcc[i])ban[MP(x,y)]=1;
    REP(i,1,n)G[i].clear();
    REP(i,1,m){
        int u,v;
        u=U[i],v=V[i];
        if(ban[MP(u,v)])continue;
        G[u].PB(v);W[u].PB(2);
        G[v].PB(u);W[v].PB(2);
        ban[MP(u,v)]=ban[MP(v,u)]=1;
    }
    REP(i,1,cnt){
        for(auto x:bcc[i]){
            int u=n+i,v=x;
            G[u].PB(v);W[u].PB(1);
            G[v].PB(u);W[v].PB(1);
        }
    }
}

void Work(){
    find_bcc();
    dfs1(1);
    dfs2(1,1);
    while(q--){
        int u,v;
        read(u,v);
        int p=lca(u,v);
        int ans=len[u]+len[v]-len[p]-len[p];
        ans>>=1;
        iout(ans);
    }
}

void Init(){
    read(n,m,q);
    REP(i,1,m){
        int u,v;
        read(u,v);
        G[u].PB(v);G[v].PB(u);
        U[i]=u;V[i]=v;
    }
}


int main(){
    
    Init();
    
    Work();
    
    return 0;
}