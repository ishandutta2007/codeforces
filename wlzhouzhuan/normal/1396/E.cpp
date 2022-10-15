//  
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define rep(i,l,r) for(rint i=l;i<=r;i++)
#define per(i,l,r) for(rint i=l;i>=r;i--)
#define ll long long
#define mk make_pair
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define fir first
#define sec second
#define mset(s,t) memset(s,t,sizeof(s))
template<typename T1,typename T2>void ckmin(T1 &a,T2 b){if(a>b)a=b;}
template<typename T1,typename T2>void ckmax(T1 &a,T2 b){if(a<b)a=b;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
int read(){
  int x=0,f=0;
  char ch=getchar();
  while(!isdigit(ch))f|=ch=='-',ch=getchar();
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return f?-x:x;
}
const int N=120000;
int n; ll k; vector<int> v[N];
int sz[N],dep[N],fa[N],root; ll minn=N,maxn=0;
void dfs1(int u,int f)
{
    sz[u]=1; int maxsz=0;
    for(int i=0;i<(int)v[u].size();i++)
    {
        int to=v[u][i]; if(to==f) continue;
        dfs1(to,u); sz[u]+=sz[to];
        maxsz=max(maxsz,sz[to]);
    }
    if(minn>max(maxsz,n-sz[u])) minn=max(maxsz,n-sz[u]),root=u;
}

int top[N],deg[N];
set<pii> S[N],R;// maybe lca,  not leef 
void dfs(int u,int from)
{
    sz[u]=1;
    top[u]=from;
    if(from&&(int)v[u].size()-1>=1) S[from].insert(mk(dep[u],u)); 
    for(int i=0;i<(int)v[u].size();i++)
    {
        int to=v[u][i]; if(to==fa[u]) continue;
        if(u==root) from=to; deg[u]++;
        dep[to]=dep[u]+1; fa[to]=u;
        dfs(to,from); sz[u]+=sz[to];
    }
}

void del(int x)
{
    if(!--deg[fa[x]])
        S[top[x]].erase(mk(dep[fa[x]],fa[x]));
}

int vis[N];
vector<int> rem;
void dfs3(int u)
{
    if(!vis[u]) rem.push_back(u);
    for(int i=0;i<(int)v[u].size();i++)
    {
        int to=v[u][i]; if(to==fa[u]) continue;
        dfs3(to);
    }
}

int main()
{
    scanf("%d%lld",&n,&k);
    for(int i=1;i<n;i++) 
    {
        int x,y; scanf("%d%d",&x,&y);
        v[x].push_back(y); v[y].push_back(x);
    }
    dfs1(1,-1); dep[root]=0; dfs(root,0);
    minn=0,maxn=0;
    for(int i=1;i<=n;i++) 
        if(i!=root) maxn+=sz[i], minn+=sz[i]%2;
    if(k>maxn||k<minn||(maxn-k)&1) {puts("NO"); return 0;}
    puts("YES");
    for(int i=0;i<v[root].size();i++)
    {
        int to=v[root][i];
        if(sz[to]>1) R.insert(mk(sz[to],to));
    }
    ll rest=maxn-k;
    while(rest)
    {
        int now=R.rbegin()->second; R.erase(--R.end());
        int pos=S[now].rbegin()->second;
        if(2*dep[pos]>rest)
        {
            rest/=2;
            pos=S[now].lower_bound(mk(rest,0))->second;
            vector<int> V; V.clear();
            for(int i=0;i<(int)v[pos].size();i++) 
            {
                int to=v[pos][i];
                if(to==fa[pos]||vis[to]) continue;
                V.push_back(to);
            }
            if((int)V.size()<2) V.push_back(pos);
            printf("%d %d\n",V[0],V[1]); vis[V[0]]=1; vis[V[1]]=1;
            rest-=dep[pos];
            break;
        }
        else
        {
            vector<int> V; V.clear();
            for(int i=0;i<(int)v[pos].size();i++) 
            {
                int to=v[pos][i];
                if(to==fa[pos]||vis[to]) continue;
                V.push_back(to);
            }
            if((int)V.size()<2) V.push_back(pos);

            rest-=dep[pos]*2;
            printf("%d %d\n",V[0],V[1]); vis[V[0]]=1; vis[V[1]]=1;
            del(V[0]); del(V[1]);
        }
        sz[now]-=2;
        if(sz[now]>1) R.insert(mk(sz[now],now));
    }
    dfs3(root);
    int T=(int)rem.size()/2;
    for(int i=0;i<T;i++) printf("%d %d\n",rem[i],rem[i+T]);
    return 0;
}