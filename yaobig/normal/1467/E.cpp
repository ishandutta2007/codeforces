#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vi e[maxn+5];
int a[maxn+5];
map<int,vi> M;

struct bit
{
    int a[maxn+5];
    void add(int x,int v)
    {
        for(;x<=maxn;x+=x&-x) a[x]+=v;
    }
    int ask(int x)
    {
        int res=0;
        for(;x;x-=x&-x) res+=a[x];
        return res;
    }
    int ask(int x,int y)
    {
        return ask(y)-ask(x-1);
    }
}cnt,b;

int tin[maxn+5],tout[maxn+5],tot,dep[maxn+5];
void dfs(int now,int fa)
{
    tin[now]=++tot;
    dep[now]=dep[fa]+1;
    for(auto v: e[now]) if(v!=fa) dfs(v,now);
    tout[now]=tot;
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs(1,0);
    rep(i,1,n) 
    {
        if(M.find(a[i])==M.end()) M[a[i]]=vi();
        M[a[i]].pb(i);
    }
    int thr=n;
    for(auto &it: M)
    {
        vi &lst=it.SE;
        if(lst.size()==1) {thr--; continue;}
        for(auto now: lst) b.add(tin[now],1);
        for(auto now: lst)
        {
            int mark=0;
            for(auto v: e[now]) if(dep[now]<dep[v])
            {
                if(b.ask(tin[v],tout[v])>0)
                {
                    if(mark) return puts("0"),0;
                    mark=1;
                    cnt.add(tin[v],1);
                    cnt.add(tout[v]+1,-1);
                }
            }
            if((int)lst.size()-b.ask(tin[now],tout[now])>0)
            {
                if(mark) return puts("0"),0;
                cnt.add(1,1);
                cnt.add(tin[now],-1);
                cnt.add(tout[now]+1,1);
            }
        }
        for(auto now: lst) b.add(tin[now],-1);
    }
    int ans=0;
    rep(i,1,n) if(cnt.ask(i)==thr) ans++;
    printf("%d\n",ans);    
    return 0;
}