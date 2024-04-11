#include<bits/stdc++.h>
//#define int long long
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int>

using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* DSU
int p[maxn]; // rep1(i,n) p[i]=i;

int find(int u){
    if (p[u]==u) return u;
    return p[u]=find(p[u]);
}

bool unite(int u,int v){
    int pu=find(u),pv=find(v);
    p[pu]=pv;
    return pu!=pv;
}
*/
const int maxn=100007;
int n,ret[maxn];
PI ans[maxn];
bool vis[maxn];
VI vec[maxn];

void dfs(int u,int k){
    vis[u]=1;
    int sum=0,mx1=0,mx2=0;
    for (auto c:vec[u]){
        if (!vis[c]){
            dfs(c,k);
            sum+=ans[c].F;
            if (mx1<ans[c].S) mx2=mx1, mx1=ans[c].S;
            else if (mx2<ans[c].S) mx2=ans[c].S;
        }
    }
    if (mx1+mx2+1>=k){
        ans[u]={sum+1,0};
    }
    else{
        ans[u]={sum,mx1+1};
    }
}

int ms(int l,int r,int val){
    if (l==r) return l;
    int md=(l+r)>>1;
    memset(vis,0,sizeof(vis));
    memset(ans,0,sizeof(ans));
    dfs(1,md+1);
    if (ans[1].F>=val){
        return ms(md+1,r,val);
    }
    else{
        return ms(l,md,val);
    }
}

//#undef int
int main(){
    scanf("%lld",&n);
    rep(i,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        vec[u].pb(v), vec[v].pb(u);
    }
    int q=min(n,400);
    rep1(i,q){
        memset(ans,0,sizeof(ans));
        memset(vis,0,sizeof(vis));
        dfs(1,i);
        ret[i]=ans[1].F;
    }
    int l=q,r=n/q;
    for (int i=ret[q];i>0;--i){
        int j=ms(l,n/i,i);
        l=j;
        while (j>0&&!ret[j]){
            ret[j]=i;
            j--;
        }
    }
    rep1(i,n) printf("%d\n",ret[i]);
    return 0;
}