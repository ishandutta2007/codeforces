#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

struct E {int u,v,mark;};
vi to[maxn+5];
vector<E> e;

int cnt[maxn+5];
int dep[maxn+5];
int deg[maxn+5];

void dfs(int now,int fe)
{
    for(auto i: to[now]) if(i!=fe)
    {
        int v=now^e[i].u^e[i].v;
        if(dep[v]==0) 
        {
            dep[v]=dep[now]+1;
            dfs(v,i);
            cnt[now]+=cnt[v];
        }
        else if(dep[v]<dep[now])
        {
            cnt[now]++;
            cnt[v]--;
            e[i].mark=1;
        }
    }
    if(cnt[now]>0) e[fe].mark=1;
}

int vis[maxn+5];
void pre(int now,int fe)
{
    vis[now]=1;
    for(auto i: to[now]) if(e[i].mark==0 && i!=fe) 
    {
        int v=now^e[i].u^e[i].v;
        pre(v,i);
    }
    if(fe==-1) return;
    int fa=now^e[fe].u^e[fe].v;
    if(deg[now]&1 && deg[fa]&1) e[fe].mark=1,deg[now]--,deg[fa]--;
}

vector<pii> ans;
vi ret[maxn+5];
int match(int now,int fe)
{
    vis[now]=1;
    for(auto i: to[now]) if(e[i].mark==0 && i!=fe) 
    {
        int v=now^e[i].u^e[i].v;
        ret[now].pb(match(v,i));
    }
    int res=now;
    if(ret[now].size()&1) res=ret[now].back(),ret[now].pop_back();
    while(ret[now].size())
    {
        int u=ret[now].back(); ret[now].pop_back();
        int v=ret[now].back(); ret[now].pop_back();
        ans.pb({u,v});
    }
    if(fe==-1 && res!=now)
    {
        ans.pb({res,now}); res=0;
    }
    return res;
}

int main()
{
    int n,m; while(~scanf("%d%d",&n,&m))
    {
        if(n==0) break;
        e.clear();
        rep(i,1,n) to[i].clear();
        rep(i,1,m)
        {
            int k; scanf("%d",&k); k--;
            int last; scanf("%d",&last);
            while(k--)
            {
                int x; scanf("%d",&x);
                to[last].pb(e.size());
                to[x].pb(e.size());
                e.pb({last,x,0});
                last=x;
            }
        }
        rep(i,1,n) dep[i]=0;
        rep(i,1,n) cnt[i]=0;
        dep[1]=1; dfs(1,-1);

        rep(i,1,n) deg[i]=0;
        for(auto [x,y,mark]: e) if(mark==0) deg[x]++, deg[y]++;
        rep(i,1,n) vis[i]=0;
        rep(i,1,n) if(vis[i]==0) pre(i,-1);
        
        rep(i,1,n) vis[i]=0;
        ans.clear();
        rep(i,1,n) if(vis[i]==0) match(i,-1);
        int N=ans.size();
        printf("%d\n",N);
        for(auto [x,y]: ans) printf("%d %d\n",x,y);
    }
    return 0;
}