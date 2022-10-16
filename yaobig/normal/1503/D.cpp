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
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5],b[maxn+5],dir[maxn+5];
pii V[maxn+5];
bool used[maxn+5];

vector<pii> e[maxn+5];

void link(int x,int y)
{
    int w=1^dir[x]^dir[y];
    e[x].pb({y,w});
    e[y].pb({x,w});
}

int vis[maxn+5];
int clr[maxn+5];
int sum,cnt,ok;
 
void dfs(int now)
{
    vis[now]=1;
    sum++; cnt+=clr[now];
    for(auto [v,w]: e[now])
    {
        if(vis[v]==0)
        {
            clr[v]=clr[now]^w;
            dfs(v);
        }
        else if(clr[v]^clr[now]^w) ok=0;
    }
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d%d",&a[i],&b[i]);
    rep(i,1,n) if(a[i]>n && b[i]>n) return puts("-1"),0;
    rep(i,1,n) if(a[i]>b[i]) swap(a[i],b[i]),dir[i]=1;
    vi id; 
    rep(i,1,n) id.pb(i);
    rep(i,1,n) V[i]={b[i],i};
    sort(id.begin(),id.end(),[](int x,int y){return a[x]<a[y];});
    sort(V+1,V+n+1);
    set<pii> S;
    int ptr=n;
    for(auto i: id)
    {
        used[i]=1;
        S.erase({b[i],i});
        if(S.size() && S.rbegin()->FI>b[i]) link(i,S.rbegin()->SE);
        while(ptr>0 && V[ptr].FI>b[i])
        {
            int j=V[ptr].SE;
            if(used[j]==0)
            {
                S.insert({b[j],j});
                link(i,j);
            }
            ptr--;
        }
    }
    int ans=0;
    rep(i,1,n) if(vis[i]==0)
    {
        sum=cnt=0; ok=1;
        dfs(i);
        if(ok==0) return puts("-1"),0;
        ans+=min(cnt,sum-cnt);
    }
    printf("%d\n",ans);
    return 0;
}