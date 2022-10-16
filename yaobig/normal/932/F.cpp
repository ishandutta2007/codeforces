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
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef double db;

int a[maxn+5],b[maxn+5];
vi e[maxn+5];
ll dp[maxn+5];

pll operator -(const pll &a,const pll &b) {return {a.FI-b.FI,a.SE-b.SE};}
long double cross(const pll &a,const pll &b) {return (long double)a.FI*b.SE-(long double)a.SE*b.FI;}

set<pll> *s[maxn+5],ss[maxn+5];

inline void ins(set<pll> *s,pll a)
{
    if(s->find(a)!=s->end()) return;
    s->insert(a);
    auto it=s->find(a);
    auto it1=it,it2=it;
    it2++;
    if(it1!=s->begin() && it2!=s->end())
    {
        it1--;
        if(cross((*it2)-a,(*it1)-a)<=0)
        {
            s->erase(a);
            return;
        }
    }
    while(1)
    {
        auto it=s->find(a);
        if(it==s->begin()) break;
        auto it1=it; it1--;
        if(it1==s->begin()) break;
        auto it2=it1; it2--;
        if(cross((*it1)-a,(*it2)-a)>=0) s->erase(it1);
        else break;
    }
    while(1)
    {
        auto it1=s->find(a); it1++;
        if(it1==s->end()) break;
        auto it2=it1; it2++;
        if(it2==s->end()) break;
        if(cross((*it2)-a,(*it1)-a)>=0) s->erase(it1);
        else break;
    }
}

inline set<pll>* mrg(set<pll>* a,set<pll>* b)
{
    if(a->size()<b->size()) swap(a,b);
    for(auto &x: *b) ins(a,x);
    return a;
}

pll lb(set<pll>* s,pll a)
{
    if((int)s->size()==1) return *(s->begin());
    int l=-maxn,r=maxn+1;
    while(l<r)
    {
        int mid=(l+r)>>1;
        auto it=s->lower_bound({mid,-1ll<<60});
        if(it==s->end()) r=mid;
        else
        {
            auto it1=it; it1++;
            if(it1==s->end() || cross(a,(*it1)-(*it))>=0) r=mid;
            else l=mid+1;
        }
    }
    auto it=s->lower_bound({r,-1ll<<60});
    return *it;
}

void dfs(int now,int fa)
{
    s[now]=&ss[now];
    for(auto v: e[now]) if(v!=fa) 
    {
        dfs(v,now);
        s[now]=mrg(s[now],s[v]);
    }
    if(fa && (int)e[now].size()==1) dp[now]=0;
    else
    {
        pll r=lb(s[now],{1,-a[now]});
        dp[now]=r.SE+a[now]*r.FI;
    }
    ins(s[now],{b[now],dp[now]});
}


int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) scanf("%d",&b[i]);
    rep(i,1,n-1)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs(1,0);
    rep(i,1,n) printf("%lld%c",dp[i]," \n"[i==n]);
    return 0;
}