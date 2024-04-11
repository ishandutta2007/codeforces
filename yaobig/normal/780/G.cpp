#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100010
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int l[maxn+5],r[maxn+5],u[maxn+5],s[maxn+5];
vi vec;
vi pool[maxn+5],ask_pool[maxn+5];

struct segtree
{
    #define ls i*2
    #define rs i*2+1

    set<int> s[maxn*4+5];
    void chg(int i,int l,int r,int ql,int qr,int x)
    {
        if(ql<=l && r<=qr)
        {
            if(x>0) s[i].insert(x);
            else s[i].erase(-x);
            return;
        }
        if(r<ql || qr<l) return;
        int mid=(l+r)>>1;
        chg(ls,l,mid,ql,qr,x);
        chg(rs,mid+1,r,ql,qr,x);
    }
    int ask(int i,int l,int r,int p)
    {
        int res=0;
        if(s[i].size()) res=max(res,*s[i].rbegin());
        if(l==r) return res;
        int mid=(l+r)>>1;
        if(p<=mid) res=max(res,ask(ls,l,mid,p));
        else res=max(res,ask(rs,mid+1,r,p));
        return res;
    }
}T;

map<int,int> id;
map<pii,int> nxt,dp;
int h,w,n;

int dfs(int x,int y)
{
    if(dp.find(mp(x,y))!=dp.end()) return dp[mp(x,y)];
    int i=nxt[mp(x,y)],ans=0;
    if(i==0) return dp[mp(x,y)]=1;
    if(l[i]==1) ans=(ans+dfs(r[i]+1,u[i]))%mod; else ans=(ans+dfs(l[i]-1,u[i]))%mod;
    if(r[i]!=w) ans=(ans+dfs(r[i]+1,u[i]))%mod; else ans=(ans+dfs(l[i]-1,u[i]))%mod;
    return dp[mp(x,y)]=ans;
}

int main()
{
    scanf("%d%d%d",&h,&w,&n);
    rep(i,1,n) scanf("%d%d%d%d",&u[i],&l[i],&r[i],&s[i]);
    vec.pb(h+1);
    rep(i,1,n) vec.pb(u[i]);
    sort(vec.begin(),vec.end());
    int N=vec.size();
    rep(i,1,n) id[u[i]]=i;

    rep(i,1,n) pool[l[i]].pb(i),pool[r[i]+1].pb(-i);
    rep(i,1,w) ask_pool[i].pb(h+1);
    rep(i,1,n)
    {
        if(l[i]!=1) ask_pool[l[i]-1].pb(u[i]);
        if(r[i]!=w) ask_pool[r[i]+1].pb(u[i]);
    }
    rep(x,1,w)
    {
        for(auto it: pool[x])
        {
            int i=abs(it),sgn=it>0?1:-1;
            int y1=lower_bound(vec.begin(),vec.end(),u[i]+1)-vec.begin()+1;
            int y2=upper_bound(vec.begin(),vec.end(),u[i]+s[i])-vec.begin();
            T.chg(1,1,N,y1,y2,sgn*u[i]);
        }
        for(auto y: ask_pool[x])
        {
            int yid=lower_bound(vec.begin(),vec.end(),y)-vec.begin()+1;
            int r=T.ask(1,1,N,yid);
            nxt[mp(x,y)]=id[r];
            //printf("? %d, %d: %d\n",x,y,id[r]);
        }
    }
    int ans=0;
    rep(x,1,w) ans=(ans+dfs(x,h+1))%mod;
    printf("%d\n",ans);
    return 0;
}