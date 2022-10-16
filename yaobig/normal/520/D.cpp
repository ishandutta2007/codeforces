#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 100000
#define mod 1000000009
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

map<pii,int> id;
vi to[maxn+5],from[maxn+5],e[maxn+5];
int x[maxn+5],y[maxn+5],dead[maxn+5],sup[maxn+5],deg[maxn+5];
ll pw[maxn+5];

set<int> S;

int main()
{
    int n; scanf("%d",&n);
    pw[0]=1;
    rep(i,1,n) pw[i]=pw[i-1]*n%mod;

    rep(i,1,n) scanf("%d%d",&x[i],&y[i]);
    rep(i,1,n) id[mp(x[i],y[i])]=i;
    rep(i,1,n)
    {
        rep(xx,x[i]-1,x[i]+1)
        {
            if(id[mp(xx,y[i]-1)])
            {
                sup[i]++;
                to[i].pb(id[mp(xx,y[i]-1)]);
                from[id[mp(xx,y[i]-1)]].pb(i);
            }
        }
    }
    rep(i,1,n)
    {
        if(sup[i]==1) for(auto v: to[i]) if(dead[v]==0) e[i].pb(v),deg[v]++;
    }
    rep(i,1,n) if(deg[i]==0) S.insert(i);
    ll ans=0;
    rep(i,1,n)
    {
        set<int>::iterator it=(i&1)?S.end():S.begin();
        if(i&1) it--;
        int id=*it;
        S.erase(id);
        //printf("?? %d\n",id);
        ans=(ans+(id-1)*pw[n-i])%mod;
        dead[id]=1;
        for(auto fa: from[id]) if(dead[fa]==0)
        {
            if(--sup[fa]==1)
            {
                for(auto v: to[fa]) if(dead[v]==0)
                {
                    e[fa].pb(v);
                    deg[v]++;
                    S.erase(v);
                }
            }
        }
        for(auto v: e[id]) if(dead[v]==0)
        {
            if(--deg[v]==0) S.insert(v);
        }
    }
    printf("%I64d\n",ans);
    return 0;
}